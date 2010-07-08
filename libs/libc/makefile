SRCS = $(shell find -name '*.[cS]')
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CC = i586-elf-gcc
AR = i586-elf-ar

ASFLAGS = -m32
CFLAGS = -m32 -Wall -g -ffreestanding -fno-stack-protector -nostdinc -I include
ARFLAGS = -rcs

libc: $(OBJS)
	$(AR) $(ARFLAGS) libc.a $^

%.o: %.S
	$(CC) $(ASFLAGS) -c -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(OBJS)

.PHONY: clean
