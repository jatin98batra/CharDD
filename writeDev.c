#include"headers.h"
#include"declarations.h"
ssize_t writeDev (struct file *fl , const char __user *buf, size_t size , loff_t * pointer)
{
	printk(KERN_INFO "%s:Begin\n",__func__);
 	
	//printk(KERN_INFO "%s:Inode Number: %ld\n",__func__,a->i_ino);
	
	
		

	printk(KERN_INFO "%s:End\n",__func__);

return 0;
}
