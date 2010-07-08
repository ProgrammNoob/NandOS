all: libc zlib bzip2 libmaumau

libc:
	$(MAKE) -C libc
	
#zlib: libc
#	$(MAKE) -C zlib

#bzip2: libc
#	$(MAKE) -C bzip2	

#libmaumau: libc
#	$(MAKE) -C libmaumau
	
clean:
	$(MAKE) -C libc clean
	#$(MAKE) -C zlib clean
	#$(MAKE) -C bzip2 clean	
	#$(MAKE) -C libmaumau clean
	
.PHONY: all libc zlib bzip2 libmaumau
