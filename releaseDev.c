#include"headers.h"
#include"declarations.h"
int releaseDev(struct inode * a, struct file * b)
{
	printk(KERN_INFO "%s:Begin\n",__func__);

	printk(KERN_INFO "%s:End\n",__func__);


return 0;
}
