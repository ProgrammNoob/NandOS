.global start						//Einsprungspunkt des Moduls
.extern main						//main-Funktion des Moduls

.section .text

 
start:
//Constructoren aufrufen
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$start_ctors, -12(%ebp)
	jmp	.L2
.L3:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	call	*%eax
	addl	$4, -12(%ebp)
.L2:
	cmpl	$end_ctors, -12(%ebp)
	jne	.L3
	leave
call main						//Main-Funktion des Moduls aufrufen
//Destructoren aufrufen
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$start_dtors, -12(%ebp)
	jmp	.L6
.L7:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	call	*%eax
	addl	$4, -12(%ebp)
.L6:
	cmpl	$end_dtors, -12(%ebp)
	jne	.L7
	leave
ret