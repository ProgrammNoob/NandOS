#include <stddef.h>
#include <string.h>

#include "console.h"
#include "intr.h"
#include "mm.h"
#include "multiboot.h"
#include "elf.h"

struct task {
    struct cpu_state*   cpu_state;
    struct task*        next;
};

static struct task* first_task = NULL;
static struct task* current_task = NULL;

/*
 * Jeder Task braucht seinen eigenen Stack, auf dem er beliebig arbeiten kann,
 * ohne dass ihm andere Tasks Dinge ueberschreiben. Ausserdem braucht ein Task
 * einen Einsprungspunkt.
 */
struct task* init_task_ring3(void* entry)
{
    uint8_t* stack = pmm_alloc();
    uint8_t* user_stack = pmm_alloc();

    /*
     * CPU-Zustand fuer den neuen Task festlegen
     */
    struct cpu_state new_state = {
        .eax = 0,
        .ebx = 0,
        .ecx = 0,
        .edx = 0,
        .esi = 0,
        .edi = 0,
        .ebp = 0,
        .esp = (uint32_t) user_stack + 4096,
        .eip = (uint32_t) entry,
		
		.ds  = 0x23,
		.es  = 0x23,
		
        /* Ring-3-Segmentregister */
        .cs  = 0x18 | 0x03,
        .ss  = 0x20 | 0x03,

        /* IRQs einschalten (IF = 1) */
        .eflags = 0x200,
	};
	
    /*
     * Den angelegten CPU-Zustand auf den Stack des Tasks kopieren, damit es am
     * Ende so aussieht als waere der Task durch einen Interrupt unterbrochen
     * worden. So kann man dem Interrupthandler den neuen Task unterschieben
     * und er stellt einfach den neuen Prozessorzustand "wieder her".
     */
    struct cpu_state* state = (void*) (stack + 4096 - sizeof(new_state));
    *state = new_state;

    /*
     * Neue Taskstruktur anlegen und in die Liste einhaengen
     */
    struct task* task = pmm_alloc();
    task->cpu_state = state;
    task->next = first_task;
    first_task = task;
    return task;
}

struct task* init_task_ring0(void* entry)
{
    uint8_t* stack = pmm_alloc();
    uint8_t* user_stack = pmm_alloc();

    /*
     * CPU-Zustand fuer den neuen Task festlegen
     */
    struct cpu_state new_state = {
        .eax = 0,
        .ebx = 0,
        .ecx = 0,
        .edx = 0,
        .esi = 0,
        .edi = 0,
        .ebp = 0,
        .esp = (uint32_t) user_stack + 4096,
        .eip = (uint32_t) entry,
		
		.ds  = 0x10,
		.es  = 0x10,
		
        /* Ring-0-Segmentregister */
        .cs  = 0x08 | 0x00,
        .ss  = 0x10 | 0x00,

        /* IRQs einschalten (IF = 1) */
        .eflags = 0x200,
	};
	
    /*
     * Den angelegten CPU-Zustand auf den Stack des Tasks kopieren, damit es am
     * Ende so aussieht als waere der Task durch einen Interrupt unterbrochen
     * worden. So kann man dem Interrupthandler den neuen Task unterschieben
     * und er stellt einfach den neuen Prozessorzustand "wieder her".
     */
    struct cpu_state* state = (void*) (stack + 4096 - sizeof(new_state));
    *state = new_state;

    /*
     * Neue Taskstruktur anlegen und in die Liste einhaengen
     */
    struct task* task = pmm_alloc();
    task->cpu_state = state;
    task->next = first_task;
    first_task = task;
    return task;
}

struct task* init_task_vm86(void* entry)
{
    uint8_t* stack = pmm_alloc();
    uint8_t* user_stack = pmm_alloc();

    /*
     * CPU-Zustand fuer den neuen Task festlegen
     */
    struct cpu_state new_state = {
        .eax = 0,
        .ebx = 0,
        .ecx = 0,
        .edx = 0,
        .esi = 0,
        .edi = 0,
        .ebp = 0,
        .esp = (uint32_t) user_stack + 4096,
        .eip = (uint32_t) entry,
		
		.ds  = 0x23,
		.es  = 0x23,
		
        /* Ring-3-Segmentregister */
        .cs  = 0x18 | 0x03,
        .ss  = 0x20 | 0x03,

        /* IRQs einschalten (IF = 1) */
        .eflags = 0x20202,
	};
	
    /*
     * Den angelegten CPU-Zustand auf den Stack des Tasks kopieren, damit es am
     * Ende so aussieht als waere der Task durch einen Interrupt unterbrochen
     * worden. So kann man dem Interrupthandler den neuen Task unterschieben
     * und er stellt einfach den neuen Prozessorzustand "wieder her".
     */
    struct cpu_state* state = (void*) (stack + 4096 - sizeof(new_state));
    *state = new_state;

    /*
     * Neue Taskstruktur anlegen und in die Liste einhaengen
     */
    struct task* task = pmm_alloc();
    task->cpu_state = state;
    task->next = first_task;
    first_task = task;
    return task;
}

void init_elf(void* image)
{
    /*
     * FIXME Wir muessen eigentlich die Laenge vom Image pruefen, damit wir bei
     * korrupten ELF-Dateien nicht ueber das Dateiende hinauslesen.
     */

    struct elf_header* header = image;
    struct elf_program_header* ph;
    int i;

    /* Ist es ueberhaupt eine ELF-Datei? */
    if (header->magic != ELF_MAGIC) {
        kprintf("Keine gueltige ELF-Magic!\n");
        return;
    }

    /*
     * Alle Program Header durchgehen und den Speicher an die passende Stelle
     * kopieren.
     *
     * FIXME Wir erlauben der ELF-Datei hier, jeden beliebigen Speicher zu
     * ueberschreiben, einschliesslich dem Kernel selbst.
     */
    ph = (struct elf_program_header*) (((char*) image) + header->ph_offset);
    for (i = 0; i < header->ph_entry_count; i++, ph++)
	{
        void* dest = (void*) ph->virt_addr;
        void* src = ((char*) image) + ph->offset;

        /* Nur Program Header vom Typ LOAD laden */
        if (ph->type != 1)
		{
            continue;
        }

        memset(dest, 0, ph->mem_size);
        memcpy(dest, src, ph->file_size);
    }

    init_task_ring3((void*) header->entry);
}

/*
 * Gibt den Prozessorzustand des naechsten Tasks zurueck. Der aktuelle
 * Prozessorzustand wird als Parameter uebergeben und gespeichert, damit er
 * beim naechsten Aufruf des Tasks wiederhergestellt werden kann
 */
struct cpu_state* schedule(struct cpu_state* cpu)
{
    /*
     * Wenn schon ein Task laeuft, Zustand sichern. Wenn nicht, springen wir
     * gerade zum ersten Mal in einen Task. Diesen Prozessorzustand brauchen
     * wir spaeter nicht wieder.
     */
    if (current_task != NULL)
	{
        current_task->cpu_state = cpu;
    }

    /*
     * Naechsten Task auswaehlen. Wenn alle durch sind, geht es von vorne los
     */
    if (current_task == NULL)
	{
        current_task = first_task;
    }
	else
	{
        current_task = current_task->next;
        if (current_task == NULL)
		{
            current_task = first_task;
        }
    }

    /* Prozessorzustand des neuen Tasks aktivieren */
    cpu = current_task->cpu_state;

    return cpu;
}
