.macro intr_stub nr
.global intr_stub_\nr
intr_stub_\nr:
    pushl $0
    pushl $\nr
    jmp intr_common_handler
.endm

.macro intr_stub_error_code nr
.global intr_stub_\nr
intr_stub_\nr:
    pushl $\nr
    jmp intr_common_handler
.endm

// Exceptions
intr_stub 0
intr_stub 1
intr_stub 2
intr_stub 3
intr_stub 4
intr_stub 5
intr_stub 6
intr_stub 7
intr_stub_error_code 8
intr_stub 9
intr_stub_error_code 10
intr_stub_error_code 11
intr_stub_error_code 12
intr_stub_error_code 13
intr_stub_error_code 14
intr_stub 15
intr_stub 16
intr_stub_error_code 17
intr_stub 18

// Syscall
intr_stub 48

.extern handle_interrupt
intr_common_handler:
    // CPU-Zustand sichern
    push %ebp
    push %edi
    push %esi
    push %edx
    push %ecx
    push %ebx
    push %eax
    push %ds
    push %es
    // Kernel-Datensegmente laden
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es

    // Handler aufrufen
    // Der Rueckgabewert ist der Prozessorzustand des moeglicherweise
    // gewechselten Tasks. Wir muessen also den Stack dorthin wechseln
    // um die Register wiederherzustellen.
    push %esp
    call handle_interrupt
    mov %eax, %esp

    // CPU-Zustand wiederherstellen
	pop %es
	pop %ds
    pop %eax
    pop %ebx
    pop %ecx
    pop %edx
    pop %esi
    pop %edi
    pop %ebp

    // Fehlercode und Interruptnummer vom Stack nehmen
    add $8, %esp

    iret
	
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////IRQ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

.macro irq_stub nr
.global irq_stub_\nr
irq_stub_\nr:
    pushl $0
    pushl $\nr
    jmp irq_common_handler
.endm

// IRQ
irq_stub 32 //IRQ 0
irq_stub 33 //IRQ 1
irq_stub 34 //IRQ 2
irq_stub 35 //IRQ 3
irq_stub 36 //IRQ 4
irq_stub 37 //IRQ 5
irq_stub 38 //IRQ 6
irq_stub 39 //IRQ 7
irq_stub 40 //IRQ 8
irq_stub 41 //IRQ 9
irq_stub 42 //IRQ 10
irq_stub 43 //IRQ 11
irq_stub 44 //IRQ 12
irq_stub 45 //IRQ 13
irq_stub 46 //IRQ 14
irq_stub 47 //IRQ 15

.extern handle_irq
irq_common_handler:
    // CPU-Zustand sichern
    push %ebp
    push %edi
    push %esi
    push %edx
    push %ecx
    push %ebx
    push %eax
    push %ds
    push %es
    // Kernel-Datensegmente laden
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es

    // Handler aufrufen
    // Der Rueckgabewert ist der Prozessorzustand des moeglicherweise
    // gewechselten Tasks. Wir muessen also den Stack dorthin wechseln
    // um die Register wiederherzustellen.
    push %esp
    call handle_irq
    mov %eax, %esp

    // CPU-Zustand wiederherstellen
	pop %es
	pop %ds
    pop %eax
    pop %ebx
    pop %ecx
    pop %edx
    pop %esi
    pop %edi
    pop %ebp

    // Fehlercode und Interruptnummer vom Stack nehmen
    add $8, %esp

    iret