#include"headers.h"
#include"declarations.h"
ssize_t writeDev (struct file *fl , const char __user *buf, size_t size , loff_t * pointer)
{
	struct Dev * ldev;
	struct Qset * start; 
	size_t actualSize;
	char *kernBuf;
	int ret;
	char *string1,*string2;
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
	start=createScull(actualSize,ldev);
	

	string1=(char*)kmalloc(10,GFP_KERNEL);
	string2=(char*)kmalloc(10,GFP_KERNEL);
	copy_from_user(string1,buf,9);
	copy_from_user(string2,buf+9,9);
	string1[9]='\0';
	string2[9]='\0';
	printk(KERN_INFO"string1: %s ",string1);
	printk(KERN_INFO"string2: %s ",string2);
	
	
	/*noctw=actualSize;
	temp=start;
	i=0;
	while()
	{
		nocnw=copy_from_user((*((temp->data)+i)),buf,ldev->regSize);
		noctw=noctw-ldev->regSize+nocnw;
		i++; //FIXME: how to move the file postition
	}*/

	
		
	
	
	
		

	printk(KERN_INFO "%s:End\n",__func__);

return 0;
}
