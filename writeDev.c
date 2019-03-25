#include"headers.h"
#include"declarations.h"
ssize_t writeDev (struct file *fl , const char __user *buf, size_t size , loff_t * pointer)
{
	struct Dev * ldev;
	struct Qset * start; 
	size_t actualSize;
	ldev=(Dev*)fl->private_data;

	printk(KERN_INFO "%s:Begin\n",__func__);
	//printk(KERN_INFO "%s:Inode Number: %ld\n",__func__,a->i_ino);

	if(size > ldev->devSize)
	{
		actualSize=ldev->devSize;
	
	}

	else
		actualSize=size;


//	printk(KERN_INFO "The size we are passing to the createScull is:%ld\n",actualSize);
	start=createScull(actualSize,ldev);
	

	
	
		

	printk(KERN_INFO "%s:End\n",__func__);

return 0;
}
