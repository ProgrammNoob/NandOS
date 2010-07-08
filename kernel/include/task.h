#ifndef TASK_H
#define TASK_H

struct cpu_state {
    // Von Hand gesicherte Register
	uint32_t   es;
	uint32_t   ds;
    uint32_t   eax;
    uint32_t   ebx;
    uint32_t   ecx;
    uint32_t   edx;
    uint32_t   esi;
    uint32_t   edi;
    uint32_t   ebp;

    uint32_t   intr;
    uint32_t   error;

    // Von der CPU gesichert
    uint32_t   eip;
    uint32_t   cs;
    uint32_t   eflags;
    uint32_t   esp;
    uint32_t   ss;
};

struct task* init_task_ring3(void* entry);
struct task* init_task_ring0(void* entry);
struct cpu_state* schedule(struct cpu_state* cpu);

#endif