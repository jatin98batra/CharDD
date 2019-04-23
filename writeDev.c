#include"headers.h"
#include"declarations.h"
ssize_t writeDev (struct file *fl , const char __user *buf, size_t size , loff_t * pointer)
{
	struct Dev *ldev;
	struct Qset *temp;	
	size_t actualSize;
	int nocsw,noctw,nocnw,i;
	ldev=(Dev*)fl->private_data;

	printk(KERN_INFO "%s:Begin\n",__func__);
	//printk(KERN_INFO "%s:Inode Number: %ld\n",__func__,a->i_ino);

	if(size > ldev->devSize)
	{
		actualSize=ldev->devSize;
	
	}

	else
		actualSize=size;

	printk(KERN_INFO "The size we are passing to the createScull is:%ld\n",actualSize);
	startQset=createScull(actualSize,ldev);//extern variable
	ldev->ptr=startQset;
	

	
	/*	
	 *	Number of characters successfully written		nocsw
	 *	Number Of Characters Not Written 			nocnw
	 *	Number Of Characters To be Written			noctw
	 */
	
	temp=startQset;
	nocsw=0;
	i=0;

	while(actualSize!=0)
	{
		if(actualSize>ldev->regSize)
		{
			noctw=ldev->regSize;
		}
		else
			noctw=actualSize;

#ifdef DEBUG
			printk(KERN_INFO "No of characters to be written: %d \n",noctw);
#endif
	
		/*copy the data from the offset, namely nocsw*/
		nocnw=copy_from_user(*(temp->data+i),buf+nocsw,noctw);
		if(!nocnw)
		{
#ifdef DEBUG
			printk(KERN_INFO "Written Successfully %d bytes till now..\n",nocsw);
			printk(KERN_INFO "Written Successfully %d bytes..\n",noctw);
#endif
		}
		else
#ifdef DEBUG
			printk(KERN_ERR "PartialWrite..\n");
#endif
	

		/*update the postion*/
		nocsw=nocsw+noctw-nocnw;
		/*change the postion*/
		actualSize=actualSize-noctw+nocnw;
		/*update the Device Specific paramater and also the Extern Variable*/
		ldev->dataSize=nocsw;
		dataSize=nocsw; 
		i++; //Next Register
		if(i > ldev->noReg) //next Qset
		{ 
			temp=temp->next;
			i=0;
		
		}

	}	
	

	
	
		

	printk(KERN_INFO "%s:End\n",__func__);

return nocsw;
}
