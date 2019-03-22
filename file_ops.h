struct file_operations fops={

open:		openDev,
release:	releaseDev,
read:		readDev,
write:		writeDev

};
