#include "console.h"
#include "intr.h"
#include "mm.h"
#include "multiboot.h"
#include "dis.h"
#include "timer.h"

struct task* init_task_ring0(void* entry);
struct task* init_task_ring3(void* entry);

void kernel_task(struct multiboot_info *mb_info)
{
	kprintf("Kernel");
	while(1);
}

void dis_task(void)
{
	dis_init();
	kprintf("DIS");
	while(1);
}

/**
 * 	
 *  @param multiboot_info Die Multiboot Info Struktur wird von Grub übergeben
 *  @param magic Die Magic Number wird von Grub übergeben. 
 *  @return Sollte nicht zurückehren.
 */
void init(struct multiboot_info *mb_info, uint32_t magic)
{
	clrscr();
	kprintf("Hello World!\n");
	
	pmm_init(mb_info);
	
	init_gdt();
	init_intr();
	init_task_ring0(kernel_task);
	init_task_ring3(dis_task);
	init_timer(100);
	asm volatile("sti");
}
