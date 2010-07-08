/*  Bei _start soll die Ausfuehrung losgehen */
ENTRY(start)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)
OUTPUT(..\..\img\apps\test.elf)
/*
 * Hier wird festgelegt, in welcher Reihenfolge welche Sektionen in die Binary
 * geschrieben werden sollen
 */
SECTIONS
{
    /* Das Programm wird an 2 MB geladen */
    . = 0x200000;

    .text : {
        *(.text)
    }
    .data ALIGN(4096) : {
		start_ctors = .;
		*(.ctors)
		end_ctors = .;

		start_dtors = .;
		*(.dtors)
		end_dtors = .;

		*(.data)
    }
    .rodata ALIGN(4096) : {
        *(.rodata)
    }
    .bss ALIGN(4096) : {
        *(.bss)
    }
}

