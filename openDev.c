#include"headers.h"
#include"declarations.h"
int openDev(struct inode * inodep, struct file * filp)
{
	

	Dev *ldev;  //pointer to the same structure that was allocated by the kmalloc
	
	printk(KERN_INFO "%s:Begin\n",__func__);
	//TODO: i will also try to see if there is anything related in the struct file{} and struct inode{ } like writable pointer etc
	// we can have accessed the cdev structure using the inode structure but we want actually the cdev structure which is inside the "struct Dev" 	
	
	ldev=container_of( inodep->i_cdev , Dev , c_dev );

	//CROSSCHECK:
#ifdef DEBUG
	printk(KERN_INFO "ldev = %p",ldev);	
#endif 

			
	
		

	printk(KERN_INFO "%s:End\n",__func__);

return 0;
}
