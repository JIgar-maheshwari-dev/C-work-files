	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"In main() program:"
	.align 8
.LC1:
	.string	"x value is %d and is stored at address %p.\n"
	.align 8
.LC2:
	.string	"xptr pointer points to address %p which holds a value of %d.\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$5, -20(%rbp)
	leaq	-20(%rbp), %rax
	movq	%rax, -16(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	-20(%rbp), %eax
	leaq	-20(%rbp), %rdx
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	display
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC3:
	.string	"In display() function:"
	.align 8
.LC4:
	.string	"y value is %d and is stored at address %p.\n"
	.align 8
.LC5:
	.string	"yptr pointer points to address %p which holds a value of %d.\n"
	.text
	.type	display, @function
display:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1145258561, -15(%rbp)
	movw	$17989, -11(%rbp)
	movb	$0, -9(%rbp)
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	movl	-20(%rbp), %eax
	leaq	-20(%rbp), %rdx
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	display, .-display
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
