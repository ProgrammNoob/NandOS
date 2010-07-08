
    .global setjmp
    .global longjmp
setjmp:
    pushl %ebp
    movl %esp, %ebp

    pushl %edi
    movl 8(%ebp), %edi

    //edi = Sprungdaten (jmp_buf)
    //Sichere Register

    movl %eax, 0(%edi)
    movl %ebx, 4(%edi)
    movl %ecx, 8(%edi)
    movl %edx, 12(%edi)
    movl %esi, 16(%edi)

    //Sichere edi
    movl -4(%ebp), %eax
    movl %eax, 20(%edi)

    //Sichere Rest des Stack Frames
    //Vorheriger ebp
    movl 0(%ebp), %eax
    movl %eax, 24(%edi)
    //Beginn des Stack Frames
    movl %esp, %eax
    addl $12, %eax
    movl %eax, 28(%edi)
    //Rücksprungaddresse
    movl 4(%ebp), %eax
    movl %eax, 32(%edi)

    popl %edi
    movl $0, %eax
    leave
    ret

longjmp:
    pushl %ebp
    movl %esp, %ebp

    //edi = Sprungdaten (jmp_buf)
    movl 8(%ebp), %edi
    //Rückgabewert in die Sprungdaten schreiben
    movl 12(%ebp), %eax
    movl %eax, 0(%edi)

    //Register wiederherstellen
    movl 24(%edi), %ebp

    movl 28(%edi), %esp

    pushl 32(%edi)

    movl 0(%edi), %eax
    movl 4(%edi), %ebx
    movl 8(%edi), %ecx
    movl 12(%edi), %edx
    movl 16(%edi), %esi
    movl 20(%edi), %edi

    ret
	