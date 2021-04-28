
crackme.1.elf64.x:     формат файла elf64-x86-64


Дизассемблирование раздела .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Дизассемблирование раздела .plt:

0000000000001020 <.plt>:
    1020:	ff 35 6a 2f 00 00    	pushq  0x2f6a(%rip)        # 3f90 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 6b 2f 00 00 	bnd jmpq *0x2f6b(%rip)        # 3f98 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	pushq  $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmpq 1020 <.plt>
    109f:	90                   	nop

Дизассемблирование раздела .plt.got:

00000000000010a0 <__cxa_finalize@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 4d 2f 00 00 	bnd jmpq *0x2f4d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Дизассемблирование раздела .plt.sec:

00000000000010b0 <abort@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 e5 2e 00 00 	bnd jmpq *0x2ee5(%rip)        # 3fa0 <abort@GLIBC_2.2.5>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010c0 <__stack_chk_fail@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 dd 2e 00 00 	bnd jmpq *0x2edd(%rip)        # 3fa8 <__stack_chk_fail@GLIBC_2.4>
    10cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010d0 <__assert_fail@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 d5 2e 00 00 	bnd jmpq *0x2ed5(%rip)        # 3fb0 <__assert_fail@GLIBC_2.2.5>
    10db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010e0 <__printf_chk@plt>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	f2 ff 25 cd 2e 00 00 	bnd jmpq *0x2ecd(%rip)        # 3fb8 <__printf_chk@GLIBC_2.3.4>
    10eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010f0 <__isoc99_scanf@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 c5 2e 00 00 	bnd jmpq *0x2ec5(%rip)        # 3fc0 <__isoc99_scanf@GLIBC_2.7>
    10fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001100 <fwrite@plt>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	f2 ff 25 bd 2e 00 00 	bnd jmpq *0x2ebd(%rip)        # 3fc8 <fwrite@GLIBC_2.2.5>
    110b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001110 <__fprintf_chk@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 b5 2e 00 00 	bnd jmpq *0x2eb5(%rip)        # 3fd0 <__fprintf_chk@GLIBC_2.3.4>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Дизассемблирование раздела .text:

0000000000001120 <_start>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	31 ed                	xor    %ebp,%ebp
    1126:	49 89 d1             	mov    %rdx,%r9
    1129:	5e                   	pop    %rsi
    112a:	48 89 e2             	mov    %rsp,%rdx
    112d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1131:	50                   	push   %rax
    1132:	54                   	push   %rsp
    1133:	4c 8d 05 86 02 00 00 	lea    0x286(%rip),%r8        # 13c0 <__libc_csu_fini>
    113a:	48 8d 0d 0f 02 00 00 	lea    0x20f(%rip),%rcx        # 1350 <__libc_csu_init>
    1141:	48 8d 3d c1 00 00 00 	lea    0xc1(%rip),%rdi        # 1209 <main>
    1148:	ff 15 92 2e 00 00    	callq  *0x2e92(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    114e:	f4                   	hlt    
    114f:	90                   	nop

0000000000001150 <deregister_tm_clones>:
    1150:	48 8d 3d c9 2e 00 00 	lea    0x2ec9(%rip),%rdi        # 4020 <stdout@@GLIBC_2.2.5>
    1157:	48 8d 05 c2 2e 00 00 	lea    0x2ec2(%rip),%rax        # 4020 <stdout@@GLIBC_2.2.5>
    115e:	48 39 f8             	cmp    %rdi,%rax
    1161:	74 15                	je     1178 <deregister_tm_clones+0x28>
    1163:	48 8b 05 6e 2e 00 00 	mov    0x2e6e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    116a:	48 85 c0             	test   %rax,%rax
    116d:	74 09                	je     1178 <deregister_tm_clones+0x28>
    116f:	ff e0                	jmpq   *%rax
    1171:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1178:	c3                   	retq   
    1179:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001180 <register_tm_clones>:
    1180:	48 8d 3d 99 2e 00 00 	lea    0x2e99(%rip),%rdi        # 4020 <stdout@@GLIBC_2.2.5>
    1187:	48 8d 35 92 2e 00 00 	lea    0x2e92(%rip),%rsi        # 4020 <stdout@@GLIBC_2.2.5>
    118e:	48 29 fe             	sub    %rdi,%rsi
    1191:	48 89 f0             	mov    %rsi,%rax
    1194:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1198:	48 c1 f8 03          	sar    $0x3,%rax
    119c:	48 01 c6             	add    %rax,%rsi
    119f:	48 d1 fe             	sar    %rsi
    11a2:	74 14                	je     11b8 <register_tm_clones+0x38>
    11a4:	48 8b 05 45 2e 00 00 	mov    0x2e45(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    11ab:	48 85 c0             	test   %rax,%rax
    11ae:	74 08                	je     11b8 <register_tm_clones+0x38>
    11b0:	ff e0                	jmpq   *%rax
    11b2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    11b8:	c3                   	retq   
    11b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011c0 <__do_global_dtors_aux>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	80 3d 7d 2e 00 00 00 	cmpb   $0x0,0x2e7d(%rip)        # 4048 <completed.8055>
    11cb:	75 2b                	jne    11f8 <__do_global_dtors_aux+0x38>
    11cd:	55                   	push   %rbp
    11ce:	48 83 3d 22 2e 00 00 	cmpq   $0x0,0x2e22(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    11d5:	00 
    11d6:	48 89 e5             	mov    %rsp,%rbp
    11d9:	74 0c                	je     11e7 <__do_global_dtors_aux+0x27>
    11db:	48 8b 3d 26 2e 00 00 	mov    0x2e26(%rip),%rdi        # 4008 <__dso_handle>
    11e2:	e8 b9 fe ff ff       	callq  10a0 <__cxa_finalize@plt>
    11e7:	e8 64 ff ff ff       	callq  1150 <deregister_tm_clones>
    11ec:	c6 05 55 2e 00 00 01 	movb   $0x1,0x2e55(%rip)        # 4048 <completed.8055>
    11f3:	5d                   	pop    %rbp
    11f4:	c3                   	retq   
    11f5:	0f 1f 00             	nopl   (%rax)
    11f8:	c3                   	retq   
    11f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001200 <frame_dummy>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	e9 77 ff ff ff       	jmpq   1180 <register_tm_clones>

0000000000001209 <main>:
    1209:	f3 0f 1e fa          	endbr64 
    120d:	48 83 ec 18          	sub    $0x18,%rsp
    1211:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1218:	00 00 
    121a:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    121f:	31 c0                	xor    %eax,%eax
    1221:	48 8d 35 dc 0d 00 00 	lea    0xddc(%rip),%rsi        # 2004 <_IO_stdin_used+0x4>
    1228:	bf 01 00 00 00       	mov    $0x1,%edi
    122d:	e8 ae fe ff ff       	callq  10e0 <__printf_chk@plt>
    1232:	48 8d 74 24 04       	lea    0x4(%rsp),%rsi
    1237:	48 8d 3d db 0d 00 00 	lea    0xddb(%rip),%rdi        # 2019 <_IO_stdin_used+0x19>
    123e:	b8 00 00 00 00       	mov    $0x0,%eax
    1243:	e8 a8 fe ff ff       	callq  10f0 <__isoc99_scanf@plt>
    1248:	83 f8 01             	cmp    $0x1,%eax
    124b:	75 6a                	jne    12b7 <main+0xae>
    124d:	8b 54 24 04          	mov    0x4(%rsp),%edx
    1251:	8b 05 c1 2d 00 00    	mov    0x2dc1(%rip),%eax        # 4018 <orig_code>
    1257:	89 d1                	mov    %edx,%ecx
    1259:	31 c1                	xor    %eax,%ecx
    125b:	84 c9                	test   %cl,%cl
    125d:	74 77                	je     12d6 <main+0xcd>
    125f:	39 c2                	cmp    %eax,%edx
    1261:	0f 83 98 00 00 00    	jae    12ff <main+0xf6>
    1267:	0f 85 bb 00 00 00    	jne    1328 <main+0x11f>
    126d:	8b 0d 9d 2d 00 00    	mov    0x2d9d(%rip),%ecx        # 4010 <treasure_number_p2>
    1273:	c1 e1 10             	shl    $0x10,%ecx
    1276:	0b 0d 98 2d 00 00    	or     0x2d98(%rip),%ecx        # 4014 <treasure_number_p1>
    127c:	48 8d 15 d6 0d 00 00 	lea    0xdd6(%rip),%rdx        # 2059 <_IO_stdin_used+0x59>
    1283:	be 01 00 00 00       	mov    $0x1,%esi
    1288:	48 8b 3d 91 2d 00 00 	mov    0x2d91(%rip),%rdi        # 4020 <stdout@@GLIBC_2.2.5>
    128f:	b8 00 00 00 00       	mov    $0x0,%eax
    1294:	e8 77 fe ff ff       	callq  1110 <__fprintf_chk@plt>
    1299:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    129e:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    12a5:	00 00 
    12a7:	0f 85 9d 00 00 00    	jne    134a <main+0x141>
    12ad:	b8 00 00 00 00       	mov    $0x0,%eax
    12b2:	48 83 c4 18          	add    $0x18,%rsp
    12b6:	c3                   	retq   
    12b7:	48 8d 0d be 0d 00 00 	lea    0xdbe(%rip),%rcx        # 207c <__PRETTY_FUNCTION__.3159>
    12be:	ba 0e 00 00 00       	mov    $0xe,%edx
    12c3:	48 8d 35 52 0d 00 00 	lea    0xd52(%rip),%rsi        # 201c <_IO_stdin_used+0x1c>
    12ca:	48 8d 3d 59 0d 00 00 	lea    0xd59(%rip),%rdi        # 202a <_IO_stdin_used+0x2a>
    12d1:	e8 fa fd ff ff       	callq  10d0 <__assert_fail@plt>
    12d6:	48 8d 0d 56 0d 00 00 	lea    0xd56(%rip),%rcx        # 2033 <_IO_stdin_used+0x33>
    12dd:	48 8d 15 64 0d 00 00 	lea    0xd64(%rip),%rdx        # 2048 <_IO_stdin_used+0x48>
    12e4:	be 01 00 00 00       	mov    $0x1,%esi
    12e9:	48 8b 3d 50 2d 00 00 	mov    0x2d50(%rip),%rdi        # 4040 <stderr@@GLIBC_2.2.5>
    12f0:	b8 00 00 00 00       	mov    $0x0,%eax
    12f5:	e8 16 fe ff ff       	callq  1110 <__fprintf_chk@plt>
    12fa:	e8 b1 fd ff ff       	callq  10b0 <abort@plt>
    12ff:	48 8d 0d 46 0d 00 00 	lea    0xd46(%rip),%rcx        # 204c <_IO_stdin_used+0x4c>
    1306:	48 8d 15 3b 0d 00 00 	lea    0xd3b(%rip),%rdx        # 2048 <_IO_stdin_used+0x48>
    130d:	be 01 00 00 00       	mov    $0x1,%esi
    1312:	48 8b 3d 27 2d 00 00 	mov    0x2d27(%rip),%rdi        # 4040 <stderr@@GLIBC_2.2.5>
    1319:	b8 00 00 00 00       	mov    $0x0,%eax
    131e:	e8 ed fd ff ff       	callq  1110 <__fprintf_chk@plt>
    1323:	e8 88 fd ff ff       	callq  10b0 <abort@plt>
    1328:	48 8b 0d 11 2d 00 00 	mov    0x2d11(%rip),%rcx        # 4040 <stderr@@GLIBC_2.2.5>
    132f:	ba 0e 00 00 00       	mov    $0xe,%edx
    1334:	be 01 00 00 00       	mov    $0x1,%esi
    1339:	48 8d 3d 2d 0d 00 00 	lea    0xd2d(%rip),%rdi        # 206d <_IO_stdin_used+0x6d>
    1340:	e8 bb fd ff ff       	callq  1100 <fwrite@plt>
    1345:	e8 66 fd ff ff       	callq  10b0 <abort@plt>
    134a:	e8 71 fd ff ff       	callq  10c0 <__stack_chk_fail@plt>
    134f:	90                   	nop

0000000000001350 <__libc_csu_init>:
    1350:	f3 0f 1e fa          	endbr64 
    1354:	41 57                	push   %r15
    1356:	4c 8d 3d 2b 2a 00 00 	lea    0x2a2b(%rip),%r15        # 3d88 <__frame_dummy_init_array_entry>
    135d:	41 56                	push   %r14
    135f:	49 89 d6             	mov    %rdx,%r14
    1362:	41 55                	push   %r13
    1364:	49 89 f5             	mov    %rsi,%r13
    1367:	41 54                	push   %r12
    1369:	41 89 fc             	mov    %edi,%r12d
    136c:	55                   	push   %rbp
    136d:	48 8d 2d 1c 2a 00 00 	lea    0x2a1c(%rip),%rbp        # 3d90 <__do_global_dtors_aux_fini_array_entry>
    1374:	53                   	push   %rbx
    1375:	4c 29 fd             	sub    %r15,%rbp
    1378:	48 83 ec 08          	sub    $0x8,%rsp
    137c:	e8 7f fc ff ff       	callq  1000 <_init>
    1381:	48 c1 fd 03          	sar    $0x3,%rbp
    1385:	74 1f                	je     13a6 <__libc_csu_init+0x56>
    1387:	31 db                	xor    %ebx,%ebx
    1389:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1390:	4c 89 f2             	mov    %r14,%rdx
    1393:	4c 89 ee             	mov    %r13,%rsi
    1396:	44 89 e7             	mov    %r12d,%edi
    1399:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    139d:	48 83 c3 01          	add    $0x1,%rbx
    13a1:	48 39 dd             	cmp    %rbx,%rbp
    13a4:	75 ea                	jne    1390 <__libc_csu_init+0x40>
    13a6:	48 83 c4 08          	add    $0x8,%rsp
    13aa:	5b                   	pop    %rbx
    13ab:	5d                   	pop    %rbp
    13ac:	41 5c                	pop    %r12
    13ae:	41 5d                	pop    %r13
    13b0:	41 5e                	pop    %r14
    13b2:	41 5f                	pop    %r15
    13b4:	c3                   	retq   
    13b5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    13bc:	00 00 00 00 

00000000000013c0 <__libc_csu_fini>:
    13c0:	f3 0f 1e fa          	endbr64 
    13c4:	c3                   	retq   

Дизассемблирование раздела .fini:

00000000000013c8 <_fini>:
    13c8:	f3 0f 1e fa          	endbr64 
    13cc:	48 83 ec 08          	sub    $0x8,%rsp
    13d0:	48 83 c4 08          	add    $0x8,%rsp
    13d4:	c3                   	retq   
