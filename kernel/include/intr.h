#ifndef INTR_H
#define INTR_H

#include <stdint.h>
#include "multiboot.h"
#include "task.h"

void init_gdt(void);
void init_intr(void);
void init_multitasking(struct multiboot_info* mb_info);
void irq_install_handler(int irq, struct cpu_state* (*handler)(struct cpu_state* cpu));
void irq_uninstall_handler(int irq);

#endif
