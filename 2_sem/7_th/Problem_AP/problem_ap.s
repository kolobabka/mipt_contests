	.file	"problem_ap.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"%u"
.LC1:
	.string	"problem_ap.c"
.LC2:
	.string	"check == 1"
.LC3:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	mov	DWORD PTR -12[rbp], 0
	mov	DWORD PTR -20[rbp], 0
	mov	DWORD PTR -16[rbp], 2
	lea	rax, -20[rbp]
	mov	rsi, rax
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	__isoc99_scanf@PLT
	mov	DWORD PTR -12[rbp], eax
	cmp	DWORD PTR -12[rbp], 1
	je	.L3
	lea	rcx, __PRETTY_FUNCTION__.2332[rip]
	mov	edx, 11
	lea	rsi, .LC1[rip]
	lea	rdi, .LC2[rip]
	call	__assert_fail@PLT
.L5:
	mov	eax, DWORD PTR -20[rbp]
	mov	edx, 0
	div	DWORD PTR -16[rbp]
	mov	eax, edx
	mov	DWORD PTR -12[rbp], eax
	cmp	DWORD PTR -12[rbp], 0
	jne	.L4
	mov	esi, 0
	lea	rdi, .LC3[rip]
	mov	eax, 0
	call	printf@PLT
.L4:
	add	DWORD PTR -16[rbp], 1
.L3:
	mov	eax, DWORD PTR -16[rbp]
	imul	eax, eax
	mov	edx, eax
	mov	eax, DWORD PTR -20[rbp]
	cmp	edx, eax
	jb	.L5
	mov	esi, 1
	lea	rdi, .LC3[rip]
	mov	eax, 0
	call	printf@PLT
	mov	eax, 0
	mov	rcx, QWORD PTR -8[rbp]
	xor	rcx, QWORD PTR fs:40
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.type	__PRETTY_FUNCTION__.2332, @object
	.size	__PRETTY_FUNCTION__.2332, 5
__PRETTY_FUNCTION__.2332:
	.string	"main"
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
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
