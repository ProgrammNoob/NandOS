#include <stdint.h>
#include <stdio.h>



int main(void)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		asm("int $0x30" : : "a" (0), "b" ('0' + i));
	}
    while(1);
}
