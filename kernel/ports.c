#include "ports.h"

void outb(uint16_t port, uint8_t data)
{
    asm volatile ("outb %0, %1" : : "a" (data), "Nd" (port));
}

void outw(uint16_t port, uint16_t data)
{
    asm volatile ("outw %0, %1" : : "a" (data), "Nd" (port));
}

void outl(uint16_t port, uint32_t data)
{
    asm volatile ("outl %0, %1" : : "a" (data), "Nd" (port));
}

uint8_t inb(uint16_t port)
{
    unsigned char result;
	asm volatile ("inb %1, %0" : "=a" (result) : "d" (port));
    return result;
}

uint16_t inw(uint16_t port)
{
    unsigned short result;
	asm volatile ("inw %1, %0" : "=a" (result) : "d" (port));
    return result;
}

uint32_t inl(uint16_t port)
{
    unsigned int result;
	asm volatile ("inl %1, %0" : "=a" (result) : "d" (port));
    return result;
}