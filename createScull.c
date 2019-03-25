#include"headers.h"
#include"declarations.h"

/*QSET STRUCTURE:
 *
 * 	struct Qset *next
 * 	void **data
 *
 */
struct Qset* createScull(int size, struct Dev* ldev)
{
	int pageSize=0;
	int noItems;
	struct Qset *temp,*first,*last;
	first=last=temp=NULL;
	printk(KERN_INFO "%s:Begin\n",__func__);

	/* This will be responsibe for 
	 * Creating the Linked List of the Qset Structure
	 * Also allocates the array Data
	 */
	
	
	
	pageSize=(size/(ldev->noReg*(ldev->regSize)));	
	if ( (size % (ldev->noReg*(ldev->regSize))) != 0)
		pageSize++;
	
	noItems=pageSize;
#ifdef DEBUG
	printk(KERN_INFO "pageSize=%d\n",pageSize);
#endif
	
	/*creating linked list*/
	while(noItems--)
	{
		/*this loop works like this:
		 * Allocates a new member 
		 * if there was no member initially then make it as the first member
		 * if there was a member before then join the node to the end
		 */


		temp=kmalloc(sizeof(struct Qset),GFP_KERNEL);
		if(!temp)
		{
			#ifdef DEBUG
			printk(KERN_ERR "Kmalloc allocation failed\n");
			#endif
			return 0;
		
		}
		
		if(!first) //first member/node
		{
			first=temp;
			last=first;
			first->next=NULL;
			
		
		}

		else //now first isn't null
		{
			last->next=temp; //address of new node
			last=temp; //movement
			last->next = NULL; // ending list
		
		}

	}
	
	
		
	

		


	printk(KERN_INFO "%s:End\n",__func__);


return first;
}
