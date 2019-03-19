#include"headers.h"
#include"declarations.h"

static void __exit stop(void)
{
	int i=0;
	
	printk(KERN_INFO "Value of dev in ending: %d\n",devNo);

	
	

	for(i=MINORSTART;i<noDev;i++)
	{
		printk(KERN_INFO "Device Unregistering: %d-%d\n",MAJOR((devParam+i)->c_dev.dev),MINOR((devParam+i)->c_dev.dev));	
		
		cdev_del(&((devParam+i)->c_dev));
			

	
	}
		kfree(devParam);
		unregister_chrdev_region(devNo,noDev);
		
	
	printk(KERN_INFO"Bye from exit\n");
}


module_exit(stop);


