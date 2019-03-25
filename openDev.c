#include"headers.h"
#include"declarations.h"
int openDev(struct inode * inodep, struct file * filp)
{
	

	Dev *ldev;  //pointer to the same structure that was allocated by the kmalloc
	
	printk(KERN_INFO "%s:Begin\n",__func__);
	//TODO: i will also try to see if there is anything related in the struct file{} and struct inode{ } like writable pointer etc
	// we can have accessed the cdev structure using the inode structure but we want actually the cdev structure which is inside the "struct Dev" 	

	printk(KERN_INFO "%u\n",filp->f_flags);	

	ldev=container_of( inodep->i_cdev , Dev , c_dev );
	
	printk(KERN_INFO "%u\n",filp->f_flags);	

	//CROSSCHECK:
#ifdef DEBUG
	printk(KERN_INFO "ldev = %p",ldev);	
#endif 

	filp->private_data=(void*)ldev;// saving for further usage
	if(((filp->f_flags) & O_ACCMODE) == O_WRONLY)
	{
		trimDev();
	
	}
		

	printk(KERN_INFO "%s:End\n",__func__);

return 0;
}
