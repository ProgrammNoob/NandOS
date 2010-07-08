#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#include "ports.h"
#include "task.h"

struct cpu_state *timer_handler(struct cpu_state *cpu);
void init_timer(uint32_t frequency);

#endif