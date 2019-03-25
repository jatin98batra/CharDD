#include"headers.h"
#include"declarations.h"
ssize_t writeDev (struct file *fl , const char __user *buf, size_t size , loff_t * pointer)
{
	struct Dev * ldev;
	struct Qset * start; 
	size_t actualSize;
	char character;
	int i;
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
	
		
	for(i=0;i<4;i++)
	{
	character=(*(*(((char**)start->data)+(5))+i));
	printk(KERN_INFO "Character Rec: %c\n",character);
	}
	

	
	
		

	printk(KERN_INFO "%s:End\n",__func__);

return 0;
}
