#include"headers.h"
#include"declarations.h"
ssize_t readDev (struct file *filp, char __user *buf, size_t size, loff_t * ptr )
{
	struct Qset *temp;
	struct Dev  *ldev;
	int actualSize;	
	int nocnr,noctr,nocsr;
	int i;
	printk(KERN_INFO "%s:Begin\n",__func__);
	
	ldev=filp->private_data;
	temp=ldev->ptr;
	if(!temp)
	{
#ifdef DEBUG
		printk(KERN_ERR "No data written to read\n");
#endif
		return 0;
	}
	
	if(size > ldev->dataSize)

		actualSize=ldev->dataSize;
	
	else
		actualSize=size;
	
	nocsr=0;
	i=0;
	while(actualSize){
		if(actualSize>ldev->regSize)
			noctr=ldev->regSize;
		else
			noctr=actualSize;
		
		nocnr=copy_to_user(buf+nocsr,*(temp->data+i),noctr);
		if(!nocnr)
		{
#ifdef DEBUG
			printk(KERN_INFO "Successfully Read %d bytes till now\n",nocsr);
			printk(KERN_INFO "Successfully Read %d bytes\n",noctr);
#endif
			
		}
		else
#ifdef DEBUG
			printk(KERN_ERR "PartialRead...\n");
#endif
		nocsr=nocsr+noctr-nocnr;
		actualSize=actualSize-noctr+nocnr;
		ldev->dataSize-=noctr;
		dataSize-=noctr;
		i++;
		if(i >= ldev->noReg)
		{
			temp=temp->next;
			i=0;
		}


	}
	
		

	printk(KERN_INFO "%s:End\n",__func__);

return nocsr;
}
