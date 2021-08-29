	.file	"problem_pp.c"
	.text
.Ltext0:
	.globl	Piz
	.type	Piz, @function
Piz:
.LVL0:
.LFB24:
	.file 1 "problem_pp.c"
	.loc 1 27 29 view -0
	.cfi_startproc
	.loc 1 27 29 is_stmt 0 view .LVU1
	endbr64
	.loc 1 29 3 is_stmt 1 view .LVU2
.LVL1:
	.loc 1 30 3 view .LVU3
	.loc 1 31 3 view .LVU4
	.loc 1 33 3 view .LVU5
	.loc 1 35 3 view .LVU6
	.loc 1 36 12 is_stmt 0 view .LVU7
	movl	%edi, %r8d
	.loc 1 35 6 view .LVU8
	cmpl	$1, %edi
	je	.L1
	.loc 1 33 12 view .LVU9
	movl	$1, %r8d
	.loc 1 30 12 view .LVU10
	movl	$1, %esi
	.loc 1 29 12 view .LVU11
	movl	$1, %ecx
.LVL2:
.L3:
	.loc 1 38 3 is_stmt 1 view .LVU12
	.loc 1 40 5 view .LVU13
	.loc 1 40 20 is_stmt 0 view .LVU14
	leal	(%rcx,%rsi), %eax
	movl	%esi, %ecx
.LVL3:
	.loc 1 40 11 view .LVU15
	movl	$0, %edx
	divl	%edi
	movl	%edx, %esi
.LVL4:
	.loc 1 41 5 is_stmt 1 view .LVU16
	.loc 1 42 5 view .LVU17
	.loc 1 44 5 view .LVU18
	.loc 1 44 11 is_stmt 0 view .LVU19
	addl	$1, %r8d
.LVL5:
	.loc 1 46 5 is_stmt 1 view .LVU20
	.loc 1 46 15 is_stmt 0 view .LVU21
	testl	%ecx, %ecx
	sete	%r9b
	.loc 1 46 30 view .LVU22
	cmpl	$1, %edx
	sete	%al
	.loc 1 46 8 view .LVU23
	testb	%al, %r9b
	je	.L3
.LVL6:
.L1:
	.loc 1 51 1 view .LVU24
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	Piz, .-Piz
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%llu%u"
.LC1:
	.string	"problem_pp.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"(scanf (\"%llu%u\", &num, &mod)) == 2"
	.section	.rodata.str1.1
.LC3:
	.string	"%u %u\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.loc 1 10 13 is_stmt 1 view -0
	.cfi_startproc
	endbr64
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	.loc 1 10 13 is_stmt 0 view .LVU26
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	.loc 1 12 3 is_stmt 1 view .LVU27
	.loc 1 12 22 is_stmt 0 view .LVU28
	movq	$0, 16(%rsp)
	.loc 1 13 3 is_stmt 1 view .LVU29
	.loc 1 13 12 is_stmt 0 view .LVU30
	movl	$0, 12(%rsp)
	.loc 1 14 3 is_stmt 1 view .LVU31
.LVL7:
	.loc 1 15 3 view .LVU32
	.loc 1 17 3 view .LVU33
	leaq	12(%rsp), %rdx
	leaq	16(%rsp), %rsi
	leaq	.LC0(%rip), %rdi
	call	__isoc99_scanf@PLT
.LVL8:
	cmpl	$2, %eax
	jne	.L10
	.loc 1 19 3 view .LVU34
	.loc 1 19 12 is_stmt 0 view .LVU35
	movl	12(%rsp), %edi
	call	Piz
.LVL9:
	movl	%eax, %ecx
.LVL10:
	.loc 1 21 3 is_stmt 1 view .LVU36
	.loc 1 56 3 view .LVU37
	.loc 1 57 3 view .LVU38
	.loc 1 59 3 view .LVU39
	.loc 1 61 3 view .LVU40
	.loc 1 23 3 view .LVU41
.LBB8:
.LBI8:
	.file 2 "/usr/include/x86_64-linux-gnu/bits/stdio2.h"
	.loc 2 105 1 view .LVU42
.LBB9:
	.loc 2 107 3 view .LVU43
	.loc 2 107 10 is_stmt 0 view .LVU44
	movl	$0, %edx
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
.LVL11:
	.loc 2 107 10 view .LVU45
	call	__printf_chk@PLT
.LVL12:
	.loc 2 107 10 view .LVU46
.LBE9:
.LBE8:
	.loc 1 24 1 view .LVU47
	movq	24(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L11
	movl	$0, %eax
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.LVL13:
.L10:
	.cfi_restore_state
	.loc 1 17 3 is_stmt 1 discriminator 1 view .LVU48
	leaq	__PRETTY_FUNCTION__.2539(%rip), %rcx
	movl	$17, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	__assert_fail@PLT
.LVL14:
.L11:
	.loc 1 24 1 is_stmt 0 view .LVU49
	call	__stack_chk_fail@PLT
.LVL15:
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.globl	Result
	.type	Result, @function
Result:
.LVL16:
.LFB25:
	.loc 1 54 73 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 54 73 is_stmt 0 view .LVU51
	endbr64
	.loc 1 56 3 is_stmt 1 view .LVU52
.LVL17:
	.loc 1 57 3 view .LVU53
	.loc 1 59 3 view .LVU54
	.loc 1 61 3 view .LVU55
	.loc 1 63 1 is_stmt 0 view .LVU56
	ret
	.cfi_endproc
.LFE25:
	.size	Result, .-Result
	.globl	Fib_Mod
	.type	Fib_Mod, @function
Fib_Mod:
.LVL18:
.LFB26:
	.loc 1 66 51 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 66 51 is_stmt 0 view .LVU58
	endbr64
	.loc 1 68 3 is_stmt 1 view .LVU59
.LVL19:
	.loc 1 69 3 view .LVU60
	.loc 1 70 3 view .LVU61
	.loc 1 72 3 view .LVU62
	.loc 1 73 12 is_stmt 0 view .LVU63
	movl	%edi, %edx
	.loc 1 72 6 view .LVU64
	testl	%edi, %edi
	je	.L13
	.loc 1 75 3 is_stmt 1 view .LVU65
	.loc 1 75 6 is_stmt 0 view .LVU66
	cmpl	$1, %edi
	je	.L13
.LBB10:
	.loc 1 80 17 view .LVU67
	movl	$1, %ecx
.LBE10:
	.loc 1 69 12 view .LVU68
	movl	$1, %edx
	.loc 1 68 12 view .LVU69
	movl	$0, %r8d
.LVL20:
.L15:
.LBB11:
	.loc 1 82 5 is_stmt 1 discriminator 3 view .LVU70
	.loc 1 82 20 is_stmt 0 discriminator 3 view .LVU71
	leal	(%r8,%rdx), %eax
	movl	%edx, %r8d
.LVL21:
	.loc 1 82 11 discriminator 3 view .LVU72
	movl	$0, %edx
.LVL22:
	.loc 1 82 11 discriminator 3 view .LVU73
	divl	%esi
.LVL23:
	.loc 1 83 5 is_stmt 1 discriminator 3 view .LVU74
	.loc 1 84 5 discriminator 3 view .LVU75
	.loc 1 80 37 discriminator 3 view .LVU76
	.loc 1 80 38 is_stmt 0 discriminator 3 view .LVU77
	addl	$1, %ecx
.LVL24:
	.loc 1 80 24 is_stmt 1 discriminator 3 view .LVU78
	.loc 1 80 3 is_stmt 0 discriminator 3 view .LVU79
	cmpl	%ecx, %edi
	ja	.L15
.LVL25:
.L13:
	.loc 1 80 3 discriminator 3 view .LVU80
.LBE11:
	.loc 1 88 1 view .LVU81
	movl	%edx, %eax
	ret
	.cfi_endproc
.LFE26:
	.size	Fib_Mod, .-Fib_Mod
	.section	.rodata
	.type	__PRETTY_FUNCTION__.2539, @object
	.size	__PRETTY_FUNCTION__.2539, 5
__PRETTY_FUNCTION__.2539:
	.string	"main"
	.text
.Letext0:
	.file 3 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h"
	.file 4 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 5 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h"
	.file 6 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h"
	.file 7 "/usr/include/stdio.h"
	.file 8 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
	.file 9 "/usr/include/assert.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x651
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF61
	.byte	0xc
	.long	.LASF62
	.long	.LASF63
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF7
	.byte	0x3
	.byte	0xd1
	.byte	0x17
	.long	0x39
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF1
	.uleb128 0x4
	.byte	0x8
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF2
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.long	.LASF8
	.byte	0x4
	.byte	0x98
	.byte	0x19
	.long	0x6c
	.uleb128 0x2
	.long	.LASF9
	.byte	0x4
	.byte	0x99
	.byte	0x1b
	.long	0x6c
	.uleb128 0x6
	.byte	0x8
	.long	0x91
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF10
	.uleb128 0x7
	.long	0x91
	.uleb128 0x8
	.long	.LASF64
	.byte	0xd8
	.byte	0x5
	.byte	0x31
	.byte	0x8
	.long	0x224
	.uleb128 0x9
	.long	.LASF11
	.byte	0x5
	.byte	0x33
	.byte	0x7
	.long	0x65
	.byte	0
	.uleb128 0x9
	.long	.LASF12
	.byte	0x5
	.byte	0x36
	.byte	0x9
	.long	0x8b
	.byte	0x8
	.uleb128 0x9
	.long	.LASF13
	.byte	0x5
	.byte	0x37
	.byte	0x9
	.long	0x8b
	.byte	0x10
	.uleb128 0x9
	.long	.LASF14
	.byte	0x5
	.byte	0x38
	.byte	0x9
	.long	0x8b
	.byte	0x18
	.uleb128 0x9
	.long	.LASF15
	.byte	0x5
	.byte	0x39
	.byte	0x9
	.long	0x8b
	.byte	0x20
	.uleb128 0x9
	.long	.LASF16
	.byte	0x5
	.byte	0x3a
	.byte	0x9
	.long	0x8b
	.byte	0x28
	.uleb128 0x9
	.long	.LASF17
	.byte	0x5
	.byte	0x3b
	.byte	0x9
	.long	0x8b
	.byte	0x30
	.uleb128 0x9
	.long	.LASF18
	.byte	0x5
	.byte	0x3c
	.byte	0x9
	.long	0x8b
	.byte	0x38
	.uleb128 0x9
	.long	.LASF19
	.byte	0x5
	.byte	0x3d
	.byte	0x9
	.long	0x8b
	.byte	0x40
	.uleb128 0x9
	.long	.LASF20
	.byte	0x5
	.byte	0x40
	.byte	0x9
	.long	0x8b
	.byte	0x48
	.uleb128 0x9
	.long	.LASF21
	.byte	0x5
	.byte	0x41
	.byte	0x9
	.long	0x8b
	.byte	0x50
	.uleb128 0x9
	.long	.LASF22
	.byte	0x5
	.byte	0x42
	.byte	0x9
	.long	0x8b
	.byte	0x58
	.uleb128 0x9
	.long	.LASF23
	.byte	0x5
	.byte	0x44
	.byte	0x16
	.long	0x23d
	.byte	0x60
	.uleb128 0x9
	.long	.LASF24
	.byte	0x5
	.byte	0x46
	.byte	0x14
	.long	0x243
	.byte	0x68
	.uleb128 0x9
	.long	.LASF25
	.byte	0x5
	.byte	0x48
	.byte	0x7
	.long	0x65
	.byte	0x70
	.uleb128 0x9
	.long	.LASF26
	.byte	0x5
	.byte	0x49
	.byte	0x7
	.long	0x65
	.byte	0x74
	.uleb128 0x9
	.long	.LASF27
	.byte	0x5
	.byte	0x4a
	.byte	0xb
	.long	0x73
	.byte	0x78
	.uleb128 0x9
	.long	.LASF28
	.byte	0x5
	.byte	0x4d
	.byte	0x12
	.long	0x50
	.byte	0x80
	.uleb128 0x9
	.long	.LASF29
	.byte	0x5
	.byte	0x4e
	.byte	0xf
	.long	0x57
	.byte	0x82
	.uleb128 0x9
	.long	.LASF30
	.byte	0x5
	.byte	0x4f
	.byte	0x8
	.long	0x249
	.byte	0x83
	.uleb128 0x9
	.long	.LASF31
	.byte	0x5
	.byte	0x51
	.byte	0xf
	.long	0x259
	.byte	0x88
	.uleb128 0x9
	.long	.LASF32
	.byte	0x5
	.byte	0x59
	.byte	0xd
	.long	0x7f
	.byte	0x90
	.uleb128 0x9
	.long	.LASF33
	.byte	0x5
	.byte	0x5b
	.byte	0x17
	.long	0x264
	.byte	0x98
	.uleb128 0x9
	.long	.LASF34
	.byte	0x5
	.byte	0x5c
	.byte	0x19
	.long	0x26f
	.byte	0xa0
	.uleb128 0x9
	.long	.LASF35
	.byte	0x5
	.byte	0x5d
	.byte	0x14
	.long	0x243
	.byte	0xa8
	.uleb128 0x9
	.long	.LASF36
	.byte	0x5
	.byte	0x5e
	.byte	0x9
	.long	0x47
	.byte	0xb0
	.uleb128 0x9
	.long	.LASF37
	.byte	0x5
	.byte	0x5f
	.byte	0xa
	.long	0x2d
	.byte	0xb8
	.uleb128 0x9
	.long	.LASF38
	.byte	0x5
	.byte	0x60
	.byte	0x7
	.long	0x65
	.byte	0xc0
	.uleb128 0x9
	.long	.LASF39
	.byte	0x5
	.byte	0x62
	.byte	0x8
	.long	0x275
	.byte	0xc4
	.byte	0
	.uleb128 0x2
	.long	.LASF40
	.byte	0x6
	.byte	0x7
	.byte	0x19
	.long	0x9d
	.uleb128 0xa
	.long	.LASF65
	.byte	0x5
	.byte	0x2b
	.byte	0xe
	.uleb128 0xb
	.long	.LASF41
	.uleb128 0x6
	.byte	0x8
	.long	0x238
	.uleb128 0x6
	.byte	0x8
	.long	0x9d
	.uleb128 0xc
	.long	0x91
	.long	0x259
	.uleb128 0xd
	.long	0x39
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x230
	.uleb128 0xb
	.long	.LASF42
	.uleb128 0x6
	.byte	0x8
	.long	0x25f
	.uleb128 0xb
	.long	.LASF43
	.uleb128 0x6
	.byte	0x8
	.long	0x26a
	.uleb128 0xc
	.long	0x91
	.long	0x285
	.uleb128 0xd
	.long	0x39
	.byte	0x13
	.byte	0
	.uleb128 0xe
	.long	.LASF44
	.byte	0x7
	.byte	0x89
	.byte	0xe
	.long	0x291
	.uleb128 0x6
	.byte	0x8
	.long	0x224
	.uleb128 0xe
	.long	.LASF45
	.byte	0x7
	.byte	0x8a
	.byte	0xe
	.long	0x291
	.uleb128 0xe
	.long	.LASF46
	.byte	0x7
	.byte	0x8b
	.byte	0xe
	.long	0x291
	.uleb128 0xe
	.long	.LASF47
	.byte	0x8
	.byte	0x1a
	.byte	0xc
	.long	0x65
	.uleb128 0xc
	.long	0x2d1
	.long	0x2c6
	.uleb128 0xf
	.byte	0
	.uleb128 0x7
	.long	0x2bb
	.uleb128 0x6
	.byte	0x8
	.long	0x98
	.uleb128 0x7
	.long	0x2cb
	.uleb128 0x10
	.long	0x2cb
	.uleb128 0xe
	.long	.LASF48
	.byte	0x8
	.byte	0x1b
	.byte	0x1a
	.long	0x2c6
	.uleb128 0x11
	.long	.LASF55
	.byte	0x1
	.byte	0x42
	.byte	0xa
	.long	0x40
	.quad	.LFB26
	.quad	.LFE26-.LFB26
	.uleb128 0x1
	.byte	0x9c
	.long	0x37a
	.uleb128 0x12
	.long	.LASF49
	.byte	0x1
	.byte	0x42
	.byte	0x1c
	.long	0x40
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x13
	.string	"mod"
	.byte	0x1
	.byte	0x42
	.byte	0x2e
	.long	0x40
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x14
	.long	.LASF50
	.byte	0x1
	.byte	0x44
	.byte	0xc
	.long	0x40
	.long	.LLST9
	.long	.LVUS9
	.uleb128 0x14
	.long	.LASF51
	.byte	0x1
	.byte	0x45
	.byte	0xc
	.long	0x40
	.long	.LLST10
	.long	.LVUS10
	.uleb128 0x14
	.long	.LASF52
	.byte	0x1
	.byte	0x46
	.byte	0xc
	.long	0x40
	.long	.LLST11
	.long	.LVUS11
	.uleb128 0x15
	.long	.Ldebug_ranges0+0
	.uleb128 0x16
	.string	"i"
	.byte	0x1
	.byte	0x50
	.byte	0x11
	.long	0x40
	.long	.LLST12
	.long	.LVUS12
	.byte	0
	.byte	0
	.uleb128 0x17
	.long	.LASF66
	.byte	0x1
	.byte	0x36
	.byte	0xa
	.long	0x40
	.byte	0x1
	.long	0x3c8
	.uleb128 0x18
	.string	"num"
	.byte	0x1
	.byte	0x36
	.byte	0x25
	.long	0x3c8
	.uleb128 0x18
	.string	"mod"
	.byte	0x1
	.byte	0x36
	.byte	0x33
	.long	0x40
	.uleb128 0x19
	.long	.LASF53
	.byte	0x1
	.byte	0x36
	.byte	0x41
	.long	0x40
	.uleb128 0x1a
	.string	"res"
	.byte	0x1
	.byte	0x38
	.byte	0xc
	.long	0x40
	.uleb128 0x1b
	.long	.LASF49
	.byte	0x1
	.byte	0x39
	.byte	0xc
	.long	0x40
	.byte	0
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF54
	.uleb128 0x1c
	.string	"Piz"
	.byte	0x1
	.byte	0x1b
	.byte	0xa
	.long	0x40
	.quad	.LFB24
	.quad	.LFE24-.LFB24
	.uleb128 0x1
	.byte	0x9c
	.long	0x450
	.uleb128 0x13
	.string	"mod"
	.byte	0x1
	.byte	0x1b
	.byte	0x18
	.long	0x40
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x14
	.long	.LASF50
	.byte	0x1
	.byte	0x1d
	.byte	0xc
	.long	0x40
	.long	.LLST0
	.long	.LVUS0
	.uleb128 0x14
	.long	.LASF51
	.byte	0x1
	.byte	0x1e
	.byte	0xc
	.long	0x40
	.long	.LLST1
	.long	.LVUS1
	.uleb128 0x14
	.long	.LASF52
	.byte	0x1
	.byte	0x1f
	.byte	0xc
	.long	0x40
	.long	.LLST2
	.long	.LVUS2
	.uleb128 0x14
	.long	.LASF53
	.byte	0x1
	.byte	0x21
	.byte	0xc
	.long	0x40
	.long	.LLST3
	.long	.LVUS3
	.byte	0
	.uleb128 0x1d
	.long	.LASF67
	.byte	0x1
	.byte	0xa
	.byte	0x5
	.long	0x65
	.quad	.LFB23
	.quad	.LFE23-.LFB23
	.uleb128 0x1
	.byte	0x9c
	.long	0x5a7
	.uleb128 0x1e
	.string	"num"
	.byte	0x1
	.byte	0xc
	.byte	0x16
	.long	0x3c8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x1e
	.string	"mod"
	.byte	0x1
	.byte	0xd
	.byte	0xc
	.long	0x40
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x16
	.string	"res"
	.byte	0x1
	.byte	0xe
	.byte	0xc
	.long	0x40
	.long	.LLST4
	.long	.LVUS4
	.uleb128 0x14
	.long	.LASF53
	.byte	0x1
	.byte	0xf
	.byte	0xc
	.long	0x40
	.long	.LLST5
	.long	.LVUS5
	.uleb128 0x1f
	.long	.LASF68
	.long	0x5b7
	.uleb128 0x9
	.byte	0x3
	.quad	__PRETTY_FUNCTION__.2539
	.uleb128 0x20
	.long	0x5bc
	.quad	.LBI8
	.byte	.LVU42
	.quad	.LBB8
	.quad	.LBE8-.LBB8
	.byte	0x1
	.byte	0x17
	.byte	0x3
	.long	0x523
	.uleb128 0x21
	.long	0x5cd
	.long	.LLST6
	.long	.LVUS6
	.uleb128 0x22
	.quad	.LVL12
	.long	0x626
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x9
	.byte	0x3
	.quad	.LC3
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x1
	.byte	0x30
	.byte	0
	.byte	0
	.uleb128 0x24
	.quad	.LVL8
	.long	0x632
	.long	0x54e
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x9
	.byte	0x3
	.quad	.LC0
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.byte	0
	.uleb128 0x25
	.quad	.LVL9
	.long	0x3cf
	.uleb128 0x24
	.quad	.LVL14
	.long	0x63f
	.long	0x599
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x9
	.byte	0x3
	.quad	.LC2
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x9
	.byte	0x3
	.quad	.LC1
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x1
	.byte	0x41
	.uleb128 0x23
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	__PRETTY_FUNCTION__.2539
	.byte	0
	.uleb128 0x25
	.quad	.LVL15
	.long	0x64b
	.byte	0
	.uleb128 0xc
	.long	0x98
	.long	0x5b7
	.uleb128 0xd
	.long	0x39
	.byte	0x4
	.byte	0
	.uleb128 0x7
	.long	0x5a7
	.uleb128 0x26
	.long	.LASF69
	.byte	0x2
	.byte	0x69
	.byte	0x1
	.long	0x65
	.byte	0x3
	.long	0x5db
	.uleb128 0x19
	.long	.LASF56
	.byte	0x2
	.byte	0x69
	.byte	0x20
	.long	0x2d6
	.uleb128 0x27
	.byte	0
	.uleb128 0x28
	.long	0x37a
	.quad	.LFB25
	.quad	.LFE25-.LFB25
	.uleb128 0x1
	.byte	0x9c
	.long	0x626
	.uleb128 0x29
	.long	0x38b
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x29
	.long	0x397
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x29
	.long	0x3a3
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2a
	.long	0x3af
	.long	.LLST7
	.long	.LVUS7
	.uleb128 0x2a
	.long	0x3bb
	.long	.LLST8
	.long	.LVUS8
	.byte	0
	.uleb128 0x2b
	.long	.LASF57
	.long	.LASF57
	.byte	0x2
	.byte	0x5a
	.byte	0xc
	.uleb128 0x2c
	.long	.LASF58
	.long	.LASF59
	.byte	0x7
	.value	0x19a
	.byte	0xc
	.uleb128 0x2b
	.long	.LASF60
	.long	.LASF60
	.byte	0x9
	.byte	0x45
	.byte	0xd
	.uleb128 0x2d
	.long	.LASF70
	.long	.LASF70
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x37
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x2138
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x57
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x27
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x28
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x29
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2a
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2b
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2c
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2d
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LVUS9:
	.uleb128 .LVU60
	.uleb128 .LVU70
	.uleb128 .LVU70
	.uleb128 .LVU72
	.uleb128 .LVU75
	.uleb128 .LVU80
.LLST9:
	.quad	.LVL19-.Ltext0
	.quad	.LVL20-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL20-.Ltext0
	.quad	.LVL21-.Ltext0
	.value	0x1
	.byte	0x58
	.quad	.LVL23-.Ltext0
	.quad	.LVL25-.Ltext0
	.value	0x1
	.byte	0x58
	.quad	0
	.quad	0
.LVUS10:
	.uleb128 .LVU61
	.uleb128 .LVU70
	.uleb128 .LVU70
	.uleb128 .LVU73
	.uleb128 .LVU73
	.uleb128 .LVU76
	.uleb128 .LVU76
	.uleb128 .LVU80
.LLST10:
	.quad	.LVL19-.Ltext0
	.quad	.LVL20-.Ltext0
	.value	0x2
	.byte	0x31
	.byte	0x9f
	.quad	.LVL20-.Ltext0
	.quad	.LVL22-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL22-.Ltext0
	.quad	.LVL23-.Ltext0
	.value	0x1
	.byte	0x58
	.quad	.LVL23-.Ltext0
	.quad	.LVL25-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	0
	.quad	0
.LVUS11:
	.uleb128 .LVU62
	.uleb128 .LVU74
	.uleb128 .LVU74
	.uleb128 .LVU80
.LLST11:
	.quad	.LVL19-.Ltext0
	.quad	.LVL23-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL23-.Ltext0
	.quad	.LVL25-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	0
	.quad	0
.LVUS12:
	.uleb128 .LVU70
	.uleb128 .LVU80
.LLST12:
	.quad	.LVL20-.Ltext0
	.quad	.LVL25-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	0
	.quad	0
.LVUS0:
	.uleb128 .LVU3
	.uleb128 .LVU12
	.uleb128 .LVU12
	.uleb128 .LVU15
	.uleb128 .LVU17
	.uleb128 .LVU24
.LLST0:
	.quad	.LVL1-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x2
	.byte	0x31
	.byte	0x9f
	.quad	.LVL2-.Ltext0
	.quad	.LVL3-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL4-.Ltext0
	.quad	.LVL6-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	0
	.quad	0
.LVUS1:
	.uleb128 .LVU4
	.uleb128 .LVU12
	.uleb128 .LVU12
	.uleb128 .LVU16
	.uleb128 .LVU16
	.uleb128 .LVU18
	.uleb128 .LVU18
	.uleb128 .LVU24
.LLST1:
	.quad	.LVL1-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x2
	.byte	0x31
	.byte	0x9f
	.quad	.LVL2-.Ltext0
	.quad	.LVL4-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL4-.Ltext0
	.quad	.LVL4-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL4-.Ltext0
	.quad	.LVL6-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	0
	.quad	0
.LVUS2:
	.uleb128 .LVU5
	.uleb128 .LVU12
	.uleb128 .LVU16
	.uleb128 .LVU24
.LLST2:
	.quad	.LVL1-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x2
	.byte	0x31
	.byte	0x9f
	.quad	.LVL4-.Ltext0
	.quad	.LVL6-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	0
	.quad	0
.LVUS3:
	.uleb128 .LVU6
	.uleb128 .LVU12
	.uleb128 .LVU12
	.uleb128 .LVU24
.LLST3:
	.quad	.LVL1-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x2
	.byte	0x31
	.byte	0x9f
	.quad	.LVL2-.Ltext0
	.quad	.LVL6-.Ltext0
	.value	0x1
	.byte	0x58
	.quad	0
	.quad	0
.LVUS4:
	.uleb128 .LVU32
	.uleb128 .LVU41
	.uleb128 .LVU44
	.uleb128 0
.LLST4:
	.quad	.LVL7-.Ltext0
	.quad	.LVL10-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL10-.Ltext0
	.quad	.LFE23-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS5:
	.uleb128 .LVU33
	.uleb128 .LVU36
	.uleb128 .LVU36
	.uleb128 .LVU45
	.uleb128 .LVU45
	.uleb128 .LVU46
	.uleb128 .LVU48
	.uleb128 .LVU49
.LLST5:
	.quad	.LVL7-.Ltext0
	.quad	.LVL10-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL10-.Ltext0
	.quad	.LVL11-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL11-.Ltext0
	.quad	.LVL12-1-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL13-.Ltext0
	.quad	.LVL14-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS6:
	.uleb128 .LVU42
	.uleb128 .LVU46
.LLST6:
	.quad	.LVL10-.Ltext0
	.quad	.LVL12-.Ltext0
	.value	0xa
	.byte	0x3
	.quad	.LC3
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS7:
	.uleb128 .LVU53
	.uleb128 .LVU56
.LLST7:
	.quad	.LVL17-.Ltext0
	.quad	.LVL17-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS8:
	.uleb128 .LVU54
	.uleb128 .LVU55
	.uleb128 .LVU55
	.uleb128 0
.LLST8:
	.quad	.LVL17-.Ltext0
	.quad	.LVL17-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL17-.Ltext0
	.quad	.LFE25-.Ltext0
	.value	0xc
	.byte	0x75
	.sleb128 0
	.byte	0x71
	.sleb128 0
	.byte	0xc
	.long	0xffffffff
	.byte	0x1a
	.byte	0x1d
	.byte	0x9f
	.quad	0
	.quad	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.quad	.LBB10-.Ltext0
	.quad	.LBE10-.Ltext0
	.quad	.LBB11-.Ltext0
	.quad	.LBE11-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF19:
	.string	"_IO_buf_end"
.LASF27:
	.string	"_old_offset"
.LASF57:
	.string	"__printf_chk"
.LASF47:
	.string	"sys_nerr"
.LASF22:
	.string	"_IO_save_end"
.LASF5:
	.string	"short int"
.LASF7:
	.string	"size_t"
.LASF58:
	.string	"__isoc99_scanf"
.LASF32:
	.string	"_offset"
.LASF68:
	.string	"__PRETTY_FUNCTION__"
.LASF16:
	.string	"_IO_write_ptr"
.LASF11:
	.string	"_flags"
.LASF18:
	.string	"_IO_buf_base"
.LASF23:
	.string	"_markers"
.LASF13:
	.string	"_IO_read_end"
.LASF36:
	.string	"_freeres_buf"
.LASF66:
	.string	"Result"
.LASF59:
	.string	"scanf"
.LASF51:
	.string	"second"
.LASF28:
	.string	"_cur_column"
.LASF46:
	.string	"stderr"
.LASF63:
	.string	"/home/kolobaka2000/\320\240\320\260\320\261\320\276\321\207\320\270\320\271 \321\201\321\202\320\276\320\273/mipt_contests/1_sem/1_th/Problem_PP"
.LASF31:
	.string	"_lock"
.LASF6:
	.string	"long int"
.LASF55:
	.string	"Fib_Mod"
.LASF69:
	.string	"printf"
.LASF53:
	.string	"period"
.LASF61:
	.string	"GNU C17 9.3.0 -mtune=generic -march=x86-64 -g -O1 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection"
.LASF64:
	.string	"_IO_FILE"
.LASF2:
	.string	"unsigned char"
.LASF52:
	.string	"third"
.LASF49:
	.string	"counter"
.LASF4:
	.string	"signed char"
.LASF33:
	.string	"_codecvt"
.LASF54:
	.string	"long long unsigned int"
.LASF1:
	.string	"unsigned int"
.LASF41:
	.string	"_IO_marker"
.LASF30:
	.string	"_shortbuf"
.LASF15:
	.string	"_IO_write_base"
.LASF39:
	.string	"_unused2"
.LASF70:
	.string	"__stack_chk_fail"
.LASF12:
	.string	"_IO_read_ptr"
.LASF3:
	.string	"short unsigned int"
.LASF10:
	.string	"char"
.LASF67:
	.string	"main"
.LASF34:
	.string	"_wide_data"
.LASF35:
	.string	"_freeres_list"
.LASF37:
	.string	"__pad5"
.LASF42:
	.string	"_IO_codecvt"
.LASF56:
	.string	"__fmt"
.LASF0:
	.string	"long unsigned int"
.LASF17:
	.string	"_IO_write_end"
.LASF9:
	.string	"__off64_t"
.LASF8:
	.string	"__off_t"
.LASF24:
	.string	"_chain"
.LASF43:
	.string	"_IO_wide_data"
.LASF21:
	.string	"_IO_backup_base"
.LASF44:
	.string	"stdin"
.LASF26:
	.string	"_flags2"
.LASF38:
	.string	"_mode"
.LASF14:
	.string	"_IO_read_base"
.LASF29:
	.string	"_vtable_offset"
.LASF20:
	.string	"_IO_save_base"
.LASF48:
	.string	"sys_errlist"
.LASF25:
	.string	"_fileno"
.LASF40:
	.string	"FILE"
.LASF62:
	.string	"problem_pp.c"
.LASF60:
	.string	"__assert_fail"
.LASF45:
	.string	"stdout"
.LASF65:
	.string	"_IO_lock_t"
.LASF50:
	.string	"first"
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
