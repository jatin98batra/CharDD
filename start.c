#include"headers.h"
#include"declarations.h"
#include"file_ops.h"


/*Declaration/Definition of Sharable Variables*/
dev_t devNo;
int majorNo=MAJORNO;
int minorNo=MINORNO;
int neededRegs;
int noReg;
int regSize;
int devSize;
int dataSize;
Dev * devParam;
struct Qset *startQset;

/*Parameter Defaults and Module parameters*/
int noDev=NODEV;
module_param(noDev,int,S_IRUGO);

static int __init start(void)
{
	int chkMajor;
	int chkMinor;
	int ret,i;	
	ret = alloc_chrdev_region(&devNo,MINORSTART,noDev,DDNAME); //devNo will be fetched into the first argumet with consecutive noDev Values
	if(ret < 0 )
	{
		#ifdef DEBUG
		printk(KERN_ERR "ERROR:Character Device Driver registraton failed\n");	
		#endif
		return -1;
	}
	
	majorNo = MAJOR(devNo);
	minorNo = MINOR(devNo);

	#ifdef DEBUG
	printk(KERN_INFO "Device(s) Registerd: %d-%d\n",majorNo,minorNo);	
	#endif

	/*Creating space for the Device Parameters Structure*/
	devParam=(Dev*)kmalloc(sizeof(Dev)*noDev,GFP_KERNEL);
	if(!devParam)
	{
		#ifdef DEBUG
		printk(KERN_ERR "Couldn't allocate space for Device Parameter\n");
		#endif
		return -1;
	
	}
	devParam->ptr=NULL; //START = NULL	
	#ifdef DEBUG
	printk(KERN_INFO "Space Allocated: %p of length %ld for %d \n",devParam,sizeof(Dev),noDev);	
	#endif

	for(i=MINORSTART;i<noDev;i++)
	{
		/*Declarations and Definitions of the Device Specific parameters*/
		(devParam+i)->noReg=NOREG;
		(devParam+i)->regSize=REGSIZE;
		(devParam+i)->devSize=DEVSIZE;
		(devParam+i)->dataSize=DATASIZE;
		
		/*Character Device Initialization And Registry in the Device Table*/
		cdev_init(&(devParam+i)->c_dev,&fops); //Right now We are keeping fops Same for each device

		
		/*Creating Different DevId fo Different Devices connected to the same driver*/
		devNo=MKDEV(majorNo,i); //cosecutive	
			
		/*Pushing the device structure to the device table*/
		ret=cdev_add(&(devParam+i)->c_dev,devNo,1); //one at a time
		if(ret < 0)
		{
		#ifdef DEBUG
			printk(KERN_ERR "ERROR:Character Device Driver Addition failed\n");	
		#endif
			return -1;
		
		}
	}

	devNo=MKDEV(majorNo,0); //Reset : because the unregistering requires the first devNo and the count of devices afterwards this devNo
	

	for(i=MINORSTART;i<noDev;i++)
	{
		/*Cross Check The devId present in Cdev*/
		chkMajor=MAJOR((devParam+i)->c_dev.dev);
		chkMinor=MINOR((devParam+i)->c_dev.dev);
		#ifdef DEBUG
		printk(KERN_INFO "Checked Major Minor Numbers are : %d-%d \n",chkMajor,chkMinor);
		#endif
	}
return 0;

}


module_init(start);
