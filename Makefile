.PHONY: clean doc kernel libs apps

all: kernel libs apps

kernel:
	$(MAKE) -C kernel

libs:
	$(MAKE) -C libs

apps: libs
	 $(MAKE) -C apps

doc:
	doxygen Kernel.dox
	doxygen LibC.dox
	
clean:
	$(MAKE) -C kernel clean
	$(MAKE) -C apps clean
	$(MAKE) -C libs clean

image: kernel
	vfd open C:\OS-DEV_Tools\GRUB2.img
	cp kernel\kernel B:\kernel
	vfd close 

bochs_debug: image
	bochsdbg bochs.bxrc
	
bochs: image
	bochs bochs.bxrc