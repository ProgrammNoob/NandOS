SRCS = $(shell find -name '*.[c]')
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CC = i586-elf-gcc
LD = i586-elf-ar

CFLAGS = -m32 -Wall -g -ffreestanding -fno-stack-protector -nostdinc -I include
ARFLAGS = -rcs

bzip2: $(OBJS)
	$(AR) $(ARFLAGS) zlib.a $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(OBJS)

.PHONY: clean
