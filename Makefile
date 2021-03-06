INSTALL_DIR=modules

ifneq (${KERNELRELEASE},)
	obj-m := CharDD.o

CharDD-objs := start.o ending.o openDev.o releaseDev.o trimDev.o writeDev.o readDev.o createScull.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
	rm modules.order
	rm Module.symvers
endif
