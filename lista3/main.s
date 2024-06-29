	.file	"main.cpp"
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNKSt5ctypeIcE8do_widenEc
	.def	__ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
__ZNKSt5ctypeIcE8do_widenEc:
LFB1246:
	.cfi_startproc
	movzbl	4(%esp), %eax
	ret	$4
	.cfi_endproc
LFE1246:
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1933:
	.cfi_startproc
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.cfi_endproc
LFE1933:
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "basic_string::_M_construct null not valid\0"
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag.isra.26;	.scl	3;	.type	32;	.endef
__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag.isra.26:
LFB1961:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	movl	%ecx, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %edi
	movl	52(%esp), %ebx
	testl	%edi, %edi
	jne	L6
	testl	%ebx, %ebx
	je	L6
	movl	$LC0, (%esp)
	call	__ZSt19__throw_logic_errorPKc
	.p2align 4,,10
L6:
	subl	%edi, %ebx
	cmpl	$15, %ebx
	movl	%ebx, 28(%esp)
	ja	L23
	movl	(%esi), %edx
	cmpl	$1, %ebx
	movl	%edx, %eax
	je	L24
	testl	%ebx, %ebx
	jne	L7
L9:
	movl	28(%esp), %eax
	movl	%eax, 4(%esi)
	movb	$0, (%edx,%eax)
	addl	$32, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret	$8
L23:
	.cfi_restore_state
	leal	28(%esp), %eax
	movl	$0, 4(%esp)
	movl	%esi, %ecx
	movl	%eax, (%esp)
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj
	.cfi_def_cfa_offset 40
	pushl	%edx
	.cfi_def_cfa_offset 44
	pushl	%edx
	.cfi_def_cfa_offset 48
	movl	28(%esp), %edx
	movl	%eax, (%esi)
	movl	%edx, 8(%esi)
L7:
	movl	%ebx, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	movl	(%esi), %edx
	jmp	L9
L24:
	movzbl	(%edi), %eax
	movb	%al, (%edx)
	movl	(%esi), %edx
	jmp	L9
	.cfi_endproc
LFE1961:
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.21;	.scl	3;	.type	32;	.endef
	.set	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.21,__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag.isra.26
	.section	.text$_ZN5Osoba13wirtualnaInfoEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN5Osoba13wirtualnaInfoEv
	.def	__ZN5Osoba13wirtualnaInfoEv;	.scl	2;	.type	32;	.endef
__ZN5Osoba13wirtualnaInfoEv:
LFB1493:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	8(%ecx), %eax
	movl	%eax, 8(%esp)
	movl	4(%ecx), %eax
	movl	$__ZSt4cout, (%esp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%eax, %esi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%esi,%eax), %ebx
	testl	%ebx, %ebx
	je	L32
	cmpb	$0, 28(%ebx)
	je	L27
	movsbl	39(%ebx), %eax
L28:
	movl	%esi, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	.cfi_def_cfa_offset 28
	subl	$4, %esp
	.cfi_def_cfa_offset 32
	movl	%eax, %ecx
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	__ZNSo5flushEv
	.p2align 4,,10
L27:
	.cfi_restore_state
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L28
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	.cfi_def_cfa_offset 28
	subl	$4, %esp
	.cfi_def_cfa_offset 32
	movsbl	%al, %eax
	jmp	L28
L32:
	call	__ZSt16__throw_bad_castv
	.cfi_endproc
LFE1493:
	.text
	.p2align 4,,15
	.globl	__Z19wywolajNiewirtualnaP5Osoba
	.def	__Z19wywolajNiewirtualnaP5Osoba;	.scl	2;	.type	32;	.endef
__Z19wywolajNiewirtualnaP5Osoba:
LFB1494:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movl	8(%eax), %edx
	movl	%edx, 8(%esp)
	movl	4(%eax), %eax
	movl	$__ZSt4cout, (%esp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%eax, %esi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%esi,%eax), %ebx
	testl	%ebx, %ebx
	je	L40
	cmpb	$0, 28(%ebx)
	je	L35
	movsbl	39(%ebx), %eax
L36:
	movl	%esi, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	.cfi_def_cfa_offset 28
	subl	$4, %esp
	.cfi_def_cfa_offset 32
	movl	%eax, %ecx
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	__ZNSo5flushEv
	.p2align 4,,10
L35:
	.cfi_restore_state
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L36
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	.cfi_def_cfa_offset 28
	subl	$4, %esp
	.cfi_def_cfa_offset 32
	movsbl	%al, %eax
	jmp	L36
L40:
	call	__ZSt16__throw_bad_castv
	.cfi_endproc
LFE1494:
	.p2align 4,,15
	.globl	__Z16wywolajWirtualnaP5Osoba
	.def	__Z16wywolajWirtualnaP5Osoba;	.scl	2;	.type	32;	.endef
__Z16wywolajWirtualnaP5Osoba:
LFB1495:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ecx
	movl	(%ecx), %eax
	movl	(%eax), %eax
	cmpl	$__ZN5Osoba13wirtualnaInfoEv, %eax
	jne	L42
	movl	8(%ecx), %eax
	movl	%eax, 8(%esp)
	movl	4(%ecx), %eax
	movl	$__ZSt4cout, (%esp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%eax, %esi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%esi,%eax), %ebx
	testl	%ebx, %ebx
	je	L49
	cmpb	$0, 28(%ebx)
	je	L44
	movsbl	39(%ebx), %eax
L45:
	movl	%esi, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	.cfi_def_cfa_offset 28
	subl	$4, %esp
	.cfi_def_cfa_offset 32
	movl	%eax, %ecx
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	__ZNSo5flushEv
	.p2align 4,,10
L44:
	.cfi_restore_state
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L45
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	.cfi_def_cfa_offset 28
	subl	$4, %esp
	.cfi_def_cfa_offset 32
	movsbl	%al, %eax
	jmp	L45
	.p2align 4,,10
L42:
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	*%eax
L49:
	.cfi_restore_state
	call	__ZSt16__throw_bad_castv
	.cfi_endproc
LFE1495:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Jan\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1496:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1496
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x74,0x6
	.cfi_escape 0x10,0x6,0x2,0x75,0x7c
	.cfi_escape 0x10,0x3,0x2,0x75,0x78
	leal	-68(%ebp), %esi
	leal	-40(%ebp), %ebx
	subl	$92, %esp
	call	___main
	leal	-76(%ebp), %ecx
	movl	$LC1+3, 4(%esp)
	movl	$LC1, (%esp)
	movl	%esi, -76(%ebp)
LEHB0:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.21
LEHE0:
	movl	-76(%ebp), %eax
	movl	-72(%ebp), %edx
	subl	$8, %esp
	leal	-48(%ebp), %ecx
	movl	$__ZTV5Osoba+8, -52(%ebp)
	movl	%ebx, -48(%ebp)
	addl	%eax, %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
LEHB1:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag.isra.26
LEHE1:
	movl	-76(%ebp), %eax
	subl	$8, %esp
	cmpl	%esi, %eax
	je	L51
	movl	%eax, (%esp)
	call	__ZdlPv
L51:
	leal	-52(%ebp), %ecx
LEHB2:
	call	__ZN5Osoba13wirtualnaInfoEv
	leal	-52(%ebp), %ecx
	call	__ZN5Osoba13wirtualnaInfoEv
LEHE2:
	movl	-48(%ebp), %eax
	movl	$__ZTV5Osoba+8, -52(%ebp)
	cmpl	%ebx, %eax
	je	L59
	movl	%eax, (%esp)
	call	__ZdlPv
L59:
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_remember_state
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
L57:
	.cfi_restore_state
	movl	-76(%ebp), %edx
	movl	%eax, %ebx
	cmpl	%esi, %edx
	je	L54
	movl	%edx, (%esp)
	call	__ZdlPv
L54:
	movl	%ebx, (%esp)
LEHB3:
	call	__Unwind_Resume
L58:
	movl	-48(%ebp), %edx
	movl	%eax, %esi
	movl	$__ZTV5Osoba+8, -52(%ebp)
	cmpl	%ebx, %edx
	je	L56
	movl	%edx, (%esp)
	call	__ZdlPv
L56:
	movl	%esi, (%esp)
	call	__Unwind_Resume
LEHE3:
	.cfi_endproc
LFE1496:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1496:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1496-LLSDACSB1496
LLSDACSB1496:
	.uleb128 LEHB0-LFB1496
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB1496
	.uleb128 LEHE1-LEHB1
	.uleb128 L57-LFB1496
	.uleb128 0
	.uleb128 LEHB2-LFB1496
	.uleb128 LEHE2-LEHB2
	.uleb128 L58-LFB1496
	.uleb128 0
	.uleb128 LEHB3-LFB1496
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE1496:
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z19wywolajNiewirtualnaP5Osoba;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z19wywolajNiewirtualnaP5Osoba:
LFB1934:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1934:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z19wywolajNiewirtualnaP5Osoba
	.globl	__ZTS5Osoba
	.section	.rdata$_ZTS5Osoba,"dr"
	.linkonce same_size
	.align 4
__ZTS5Osoba:
	.ascii "5Osoba\0"
	.globl	__ZTI5Osoba
	.section	.rdata$_ZTI5Osoba,"dr"
	.linkonce same_size
	.align 4
__ZTI5Osoba:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS5Osoba
	.globl	__ZTV5Osoba
	.section	.rdata$_ZTV5Osoba,"dr"
	.linkonce same_size
	.align 4
__ZTV5Osoba:
	.long	0
	.long	__ZTI5Osoba
	.long	__ZN5Osoba13wirtualnaInfoEv
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZSt19__throw_logic_errorPKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i;	.scl	2;	.type	32;	.endef
	.def	__ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	__ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
