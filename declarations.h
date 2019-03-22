/**********************************************Module Registration*************************************************/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jatin Batra");
MODULE_DESCRIPTION("Character Device Driver");


/**********************************************Standard Values******************************************************/

/*Standard value for major number*/
#ifndef MINORSTART
#define MINORSTART 0
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

/*Number of minors*/
#ifndef NODEV
#define NODEV 1
#endif

/* Char Device Driver Name*/
#ifndef DDNAME
#define DDNAME "cdd"
#endif
/******************************************Debug***************************************************************************/

#ifndef DEBUG
#define DEBUG
#endif

/*******************************************Some Device Specific************************************************************/

#ifndef NOREG
#define NOREG 4
#endif

#ifndef REGSIZE
#define REGSIZE 32
#endif

#ifndef DEVSIZE
#define DEVSIZE 1024
#endif

/**********************************************Structures***********************************************************/


typedef struct
{
	struct Qset *next;
	void ** data;


}Qset;



typedef struct
{
	
	struct Qset * ptr;  /*Though "Qset" was enough and there was no need of 'struct' keyword but this makes code more readable*/
	struct cdev c_dev;
	int noReg;
	int regSize;
	int devSize;



}Dev;


/**********************************************Shareable Variable **************************************************/
extern dev_t devNo;
extern int majorNo;
extern int minorNo;
extern Dev * devParam;
extern int noDev;

/*******************************************Device Opertions********************************************************/
int openDev(struct inode *, struct file *);
int releaseDev(struct inode *, struct file *);
int trimDev(void);
ssize_t readDev (struct file *, char __user *, size_t, loff_t *);
ssize_t writeDev (struct file *, const char __user *, size_t, loff_t *);






