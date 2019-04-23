/*This is responsible for freeing the memory 
 * this example cleans the buffer*/
#include"headers.h"
#include"declarations.h"
int trimDev(Dev* ldev)
	{

	struct Qset *last,*slast;
	int i;
	printk(KERN_INFO "%s:Begin\n",__func__);
	slast=last=ldev->ptr;
	printk(KERN_INFO "ldev->ptr=%p\n",ldev->ptr);
	while(ldev->ptr){ //ptr=start of Qset linked list
		slast=last=ldev->ptr;
	
		while(last->next){ //The flow will not enter into this if onlu one element is left (!)
			slast=last;
			last=last->next; //moving to the end
			printk(KERN_INFO "moved one step\n");
		}

		for(i=ldev->noReg-1 ; i>=0 ; i--){
			if(*((last->data)+i))
			{
				printk(KERN_INFO "i=%d;addressHolded:%p\n",i,(*(last->data)+i));
				kfree(*(last->data+i));//removing register
				*(last->data+i)=NULL;//Resetting
			}
			
			else
				printk(KERN_INFO "i=%d did not entered the flow\n",i);
		}

			kfree(last->data);//deleting whole array of register present on a page
			last->data=NULL;
			kfree(last);
			
			if(slast == last){
				ldev->ptr=NULL;
				
			}
			else{
				slast->next=NULL;
			}
	}
	
	
		

	printk(KERN_INFO "%s:End\n",__func__);

return 0;
}
