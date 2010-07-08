#include "timer.h"
#include "intr.h"

extern uint32_t tss[32];
uint64_t timer_ticks=0;

struct cpu_state *timer_handler(struct cpu_state *cpu)
{
	struct cpu_state *new_cpu;
	timer_ticks++;
	new_cpu = schedule(cpu);
    tss[1] = (uint32_t) (new_cpu + 1);
	return new_cpu;
}

void init_timer(uint32_t frequency)
{
	irq_install_handler(0, timer_handler);
	uint32_t divisor = 1193180 / frequency;
	outb(0x43, 0x36);
	uint8_t l = (uint8_t)(divisor & 0xFF);
	uint8_t h = (uint8_t)( (divisor>>8) & 0xFF );
	outb(0x40, l);
	outb(0x40, h);
} 