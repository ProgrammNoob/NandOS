SRCS = $(shell find -name '*.[cS]')
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CC = i586-elf-gcc
LD = i586-elf-ld

ASFLAGS = -m32
CFLAGS = -m32 -Wall -g -ffreestanding -fno-stack-protector -nostdinc -I include
LDFLAGS = -melf_i386 -T kernel.ld -Map ..\doc\kernel\Kernel.map

kernel: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

%.o: %.S
	$(CC) $(ASFLAGS) -c -o $@ $^

clean:
	rm $(OBJS)

.PHONY: clean
