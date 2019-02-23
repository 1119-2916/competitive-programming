	.file	"kochi.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	_Z5mmnmmx
	.type	_Z5mmnmmx, @function
_Z5mmnmmx:
.LFB12855:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L4
	movq	%rdi, %rax
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%rax, %rdx
	addq	$1, %rcx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	jne	.L3
	movl	$1, %eax
	salq	%cl, %rax
.L2:
	subq	%rdi, %rax
	ret
.L4:
	movl	$1, %eax
	jmp	.L2
	.cfi_endproc
.LFE12855:
	.size	_Z5mmnmmx, .-_Z5mmnmmx
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,comdat
	.align 2
.LCOLDB1:
	.section	.text._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,comdat
.LHOTB1:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E, @function
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E:
.LFB13599:
	.cfi_startproc
	testq	%rsi, %rsi
	je	.L17
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rsi, %rbx
	.p2align 4,,10
	.p2align 3
.L13:
	movq	24(%rbx), %rsi
	movq	%r12, %rdi
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	16(%rbx), %rbp
	movq	%rbx, %rdi
	call	_ZdlPv
	testq	%rbp, %rbp
	movq	%rbp, %rbx
	jne	.L13
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 8
.L17:
	rep ret
	.cfi_endproc
.LFE13599:
	.size	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E, .-_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	.section	.text.unlikely._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,comdat
.LCOLDE1:
	.section	.text._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,comdat
.LHOTE1:
	.section	.text.unlikely._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,comdat
	.align 2
.LCOLDB2:
	.section	.text._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,comdat
.LHOTB2:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_
	.type	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_, @function
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB13961:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	leaq	8(%rdi), %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	16(%rdi), %rdx
	testq	%rdx, %rdx
	je	.L20
	movq	(%rsi), %r8
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L31:
	movq	16(%rdx), %rax
	testq	%rax, %rax
	je	.L22
.L32:
	movq	%rax, %rdx
.L21:
	movq	32(%rdx), %rcx
	cmpq	%r8, %rcx
	jg	.L31
	movq	24(%rdx), %rax
	testq	%rax, %rax
	jne	.L32
.L22:
	cmpq	%r8, %rcx
	movq	%rdx, %rbx
	movq	%rdx, %rax
	jg	.L20
.L25:
	xorl	%edx, %edx
	cmpq	%rcx, %r8
	cmovg	%rdx, %rax
	cmovg	%rbx, %rdx
.L27:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L20:
	.cfi_restore_state
	xorl	%eax, %eax
	cmpq	24(%rdi), %rbx
	movq	%rbx, %rdx
	je	.L27
	movq	%rsi, %rbp
	movq	%rbx, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	0(%rbp), %r8
	movq	32(%rax), %rcx
	jmp	.L25
	.cfi_endproc
.LFE13961:
	.size	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_, .-_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_
	.section	.text.unlikely._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,comdat
.LCOLDE2:
	.section	.text._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,comdat
.LHOTE2:
	.section	.text.unlikely._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,comdat
	.align 2
.LCOLDB3:
	.section	.text._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,comdat
.LHOTB3:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	.type	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_, @function
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_:
.LFB13803:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	leaq	8(%rdi), %rax
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbp
	movq	%rdx, %r13
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	cmpq	%rax, %rsi
	je	.L46
	movq	(%rdx), %r12
	cmpq	32(%rsi), %r12
	movq	%rsi, %rbx
	jge	.L37
	movq	24(%rdi), %rax
	cmpq	%rsi, %rax
	movq	%rax, %rdx
	je	.L44
	movq	%rsi, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpq	32(%rax), %r12
	movq	%rax, %rdx
	jle	.L35
	cmpq	$0, 24(%rax)
	movl	$0, %ecx
	movq	%rcx, %rax
	cmovne	%rbx, %rax
	cmovne	%rbx, %rdx
.L44:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L37:
	.cfi_restore_state
	jle	.L41
	movq	32(%rdi), %rdx
	xorl	%eax, %eax
	cmpq	%rsi, %rdx
	je	.L44
	movq	%rsi, %rdi
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpq	32(%rax), %r12
	movq	%rax, %rdx
	jge	.L35
	cmpq	$0, 24(%rbx)
	movl	$0, %ecx
	movq	%rcx, %rax
	cmovne	%rdx, %rax
	cmove	%rbx, %rdx
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L46:
	.cfi_restore_state
	cmpq	$0, 40(%rdi)
	je	.L35
	movq	32(%rdi), %rbx
	movq	(%rdx), %rax
	cmpq	%rax, 32(%rbx)
	jl	.L36
.L35:
	movq	%r13, %rsi
	movq	%rbp, %rdi
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L41:
	.cfi_restore_state
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%rsi, %rax
	xorl	%edx, %edx
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L36:
	.cfi_restore_state
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	movq	%rbx, %rdx
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE13803:
	.size	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_, .-_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	.section	.text.unlikely._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,comdat
.LCOLDE3:
	.section	.text._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,comdat
.LHOTE3:
	.section	.text.unlikely._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,comdat
	.align 2
.LCOLDB4:
	.section	.text._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,comdat
.LHOTB4:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.type	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_, @function
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_:
.LFB13627:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rcx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbp
	movl	$48, %edi
	movq	%rsi, %r12
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	call	_Znwm
	movq	%rax, %rbx
	movq	0(%r13), %rax
	movq	%r12, %rsi
	leaq	32(%rbx), %rdx
	movq	%rbp, %rdi
	movq	(%rax), %rax
	movq	$0, 40(%rbx)
	movq	%rax, 32(%rbx)
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	testq	%rdx, %rdx
	je	.L48
	testq	%rax, %rax
	leaq	8(%rbp), %rcx
	je	.L49
.L51:
	movl	$1, %edi
.L50:
	movq	%rbx, %rsi
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%rbp)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L48:
	.cfi_restore_state
	movq	%rbx, %rdi
	movq	%rax, 8(%rsp)
	call	_ZdlPv
	movq	8(%rsp), %rax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L49:
	.cfi_restore_state
	cmpq	%rcx, %rdx
	je	.L51
	xorl	%edi, %edi
	movq	32(%rdx), %rax
	cmpq	%rax, 32(%rbx)
	setl	%dil
	jmp	.L50
	.cfi_endproc
.LFE13627:
	.size	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_, .-_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.section	.text.unlikely._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,comdat
.LCOLDE4:
	.section	.text._ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,comdat
.LHOTE4:
	.weak	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.set	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.section	.text.unlikely._ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,"axG",@progbits,_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,comdat
.LCOLDB5:
	.section	.text._ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,"axG",@progbits,_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,comdat
.LHOTB5:
	.p2align 4,,15
	.weak	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_
	.type	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_, @function
_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_:
.LFB13975:
	.cfi_startproc
	cmpq	%rdi, %rsi
	je	.L71
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	leaq	8(%rdi), %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	cmpq	%rsi, %rbp
	je	.L54
	movq	%rsi, %r14
	movq	%rdi, %r13
	movl	$8, %r12d
	.p2align 4,,10
	.p2align 3
.L62:
	movq	0(%rbp), %rbx
	cmpq	0(%r13), %rbx
	jl	.L73
	movq	-8(%rbp), %rdx
	leaq	-8(%rbp), %rax
	cmpq	%rdx, %rbx
	jl	.L61
	jmp	.L74
	.p2align 4,,10
	.p2align 3
.L64:
	movq	%rcx, %rax
.L61:
	movq	%rdx, 8(%rax)
	movq	-8(%rax), %rdx
	leaq	-8(%rax), %rcx
	cmpq	%rdx, %rbx
	jl	.L64
.L60:
	movq	%rbx, (%rax)
.L59:
	addq	$8, %rbp
	cmpq	%rbp, %r14
	jne	.L62
.L54:
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_restore 13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_restore 14
	.cfi_def_cfa_offset 8
.L71:
	rep ret
	.p2align 4,,10
	.p2align 3
.L73:
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	.cfi_offset 14, -16
	movq	%rbp, %rdx
	subq	%r13, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	je	.L58
	movq	%r12, %rdi
	movq	%r13, %rsi
	subq	%rdx, %rdi
	addq	%rbp, %rdi
	call	memmove
.L58:
	movq	%rbx, 0(%r13)
	jmp	.L59
.L74:
	movq	%rbp, %rax
	jmp	.L60
	.cfi_endproc
.LFE13975:
	.size	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_, .-_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_
	.section	.text.unlikely._ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,"axG",@progbits,_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,comdat
.LCOLDE5:
	.section	.text._ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,"axG",@progbits,_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,comdat
.LHOTE5:
	.section	.text.unlikely._ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_,"axG",@progbits,_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_,comdat
.LCOLDB6:
	.section	.text._ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_,"axG",@progbits,_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_,comdat
.LHOTB6:
	.p2align 4,,15
	.weak	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_
	.type	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_, @function
_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_:
.LFB14242:
	.cfi_startproc
	leaq	-1(%rdx), %rax
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rax, %r12
	shrq	$63, %r12
	addq	%rax, %r12
	sarq	%r12
	cmpq	%r12, %rsi
	jge	.L76
	movq	%rsi, %r10
	jmp	.L78
	.p2align 4,,10
	.p2align 3
.L86:
	movq	%r8, %r10
.L78:
	leaq	1(%r10), %rax
	leaq	(%rax,%rax), %r8
	salq	$4, %rax
	addq	%rdi, %rax
	leaq	-1(%r8), %r11
	movq	(%rax), %r9
	leaq	(%rdi,%r11,8), %rbp
	movq	0(%rbp), %rbx
	cmpq	%r9, %rbx
	jle	.L77
	movq	%rbp, %rax
	movq	%rbx, %r9
	movq	%r11, %r8
.L77:
	cmpq	%r12, %r8
	movq	%r9, (%rdi,%r10,8)
	jl	.L86
	testb	$1, %dl
	jne	.L79
.L85:
	subq	$2, %rdx
	movq	%rdx, %r9
	shrq	$63, %r9
	addq	%r9, %rdx
	sarq	%rdx
	cmpq	%r8, %rdx
	je	.L90
.L79:
	cmpq	%rsi, %r8
	jle	.L80
	leaq	-1(%r8), %rdx
	movq	%rdx, %r9
	shrq	$63, %r9
	addq	%rdx, %r9
	sarq	%r9
	movq	(%rdi,%r9,8), %r10
	cmpq	%r10, %rcx
	jle	.L80
	cmpq	%r9, %rsi
	leaq	(%rdi,%r9,8), %rax
	movq	%r10, (%rdi,%r8,8)
	jge	.L80
.L83:
	leaq	-1(%r9), %rdx
	movq	%rdx, %r8
	shrq	$63, %r8
	addq	%r8, %rdx
	movq	%r9, %r8
	sarq	%rdx
	movq	(%rdi,%rdx,8), %r10
	cmpq	%r10, %rcx
	jle	.L80
	movq	%rdx, %r9
	movq	%r10, (%rdi,%r8,8)
	cmpq	%r9, %rsi
	leaq	(%rdi,%r9,8), %rax
	jl	.L83
.L80:
	movq	%rcx, (%rax)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L90:
	.cfi_restore_state
	leaq	1(%r8,%r8), %r8
	leaq	(%rdi,%r8,8), %rdx
	movq	(%rdx), %r9
	movq	%r9, (%rax)
	movq	%rdx, %rax
	jmp	.L79
.L76:
	testb	$1, %dl
	leaq	(%rdi,%rsi,8), %rax
	movq	%rsi, %r8
	je	.L85
	jmp	.L80
	.cfi_endproc
.LFE14242:
	.size	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_, .-_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_
	.section	.text.unlikely._ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_,"axG",@progbits,_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_,comdat
.LCOLDE6:
	.section	.text._ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_,"axG",@progbits,_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_,comdat
.LHOTE6:
	.section	.text.unlikely
.LCOLDB7:
	.text
.LHOTB7:
	.p2align 4,,15
	.type	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_.isra.54, @function
_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_.isra.54:
.LFB14384:
	.cfi_startproc
	movq	%rsi, %rax
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movq	%rsi, %r14
	subq	%rdi, %rax
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	cmpq	$135, %rax
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	jle	.L91
	testq	%rdx, %rdx
	movq	%rdi, %r12
	movq	%rdx, %r13
	je	.L93
	leaq	16(%rdi), %rbx
	movq	%rsi, %rbp
.L94:
	subq	%r12, %rbp
	movq	8(%r12), %rdi
	subq	$1, %r13
	sarq	$3, %rbp
	movq	-8(%rsi), %rcx
	movq	%rbp, %rax
	shrq	$63, %rax
	addq	%rax, %rbp
	sarq	%rbp
	leaq	(%r12,%rbp,8), %rdx
	movq	(%rdx), %rax
	cmpq	%rax, %rdi
	jge	.L99
	cmpq	%rcx, %rax
	jl	.L105
	cmpq	%rcx, %rdi
	jge	.L117
.L118:
	movq	(%r12), %rdx
	movq	%rcx, (%r12)
	movq	%rdx, -8(%rsi)
	movq	8(%r12), %r9
	movq	(%r12), %rdi
.L101:
	movq	%rbx, %r8
	movq	%rsi, %rcx
	.p2align 4,,10
	.p2align 3
.L103:
	leaq	-8(%r8), %rbp
	cmpq	%rdi, %r9
	movq	%rbp, %r14
	jl	.L106
	cmpq	%rdi, %rdx
	leaq	-8(%rcx), %rax
	jle	.L113
	leaq	-16(%rcx), %rax
	.p2align 4,,10
	.p2align 3
.L108:
	movq	%rax, %rcx
	subq	$8, %rax
	movq	8(%rax), %rdx
	cmpq	%rdi, %rdx
	jg	.L108
	cmpq	%rcx, %rbp
	jnb	.L119
.L109:
	movq	%rdx, -8(%r8)
	movq	%r9, (%rcx)
	movq	-8(%rcx), %rdx
	movq	(%r12), %rdi
.L106:
	movq	(%r8), %r9
	addq	$8, %r8
	jmp	.L103
.L113:
	movq	%rax, %rcx
	cmpq	%rcx, %rbp
	jb	.L109
.L119:
	movq	%r13, %rdx
	movq	%rbp, %rdi
	call	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_.isra.54
	movq	%rbp, %rax
	subq	%r12, %rax
	cmpq	$135, %rax
	jle	.L91
	testq	%r13, %r13
	je	.L93
	movq	%rbp, %rsi
	jmp	.L94
.L99:
	cmpq	%rcx, %rdi
	jl	.L117
	cmpq	%rcx, %rax
	jl	.L118
.L105:
	movq	(%r12), %rcx
	movq	%rax, (%r12)
	movq	%rcx, (%rdx)
	movq	8(%r12), %r9
	movq	(%r12), %rdi
	movq	-8(%rsi), %rdx
	jmp	.L101
.L117:
	movq	(%r12), %r9
	movq	%rdi, (%r12)
	movq	%r9, 8(%r12)
	movq	-8(%rsi), %rdx
	jmp	.L101
.L93:
	sarq	$3, %rax
	leaq	-2(%rax), %rbp
	movq	%rax, %rbx
	sarq	%rbp
	jmp	.L96
.L120:
	subq	$1, %rbp
.L96:
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	movq	(%r12,%rbp,8), %rcx
	movq	%rbp, %rsi
	pushq	$0
	.cfi_def_cfa_offset 64
	movq	%rbx, %rdx
	movq	%r12, %rdi
	call	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_
	testq	%rbp, %rbp
	popq	%rcx
	.cfi_def_cfa_offset 56
	popq	%rsi
	.cfi_def_cfa_offset 48
	jne	.L120
	subq	$8, %r14
.L97:
	movq	(%r12), %rax
	movq	%r14, %rbx
	movq	(%r14), %rcx
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	subq	%r12, %rbx
	xorl	%esi, %esi
	movq	%rbx, %rdx
	movq	%r12, %rdi
	subq	$8, %r14
	movq	%rax, 8(%r14)
	pushq	$0
	.cfi_def_cfa_offset 64
	sarq	$3, %rdx
	call	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElxNS0_5__ops15_Iter_less_iterEEvT_T0_SA_T1_T2_
	cmpq	$15, %rbx
	popq	%rax
	.cfi_def_cfa_offset 56
	popq	%rdx
	.cfi_def_cfa_offset 48
	jg	.L97
.L91:
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE14384:
	.size	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_.isra.54, .-_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_.isra.54
	.section	.text.unlikely
.LCOLDE7:
	.text
.LHOTE7:
	.section	.text.unlikely
.LCOLDB8:
	.section	.text.startup,"ax",@progbits
.LHOTB8:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB12856:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA12856
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	xorl	%edi, %edi
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$160, %rsp
	.cfi_def_cfa_offset 208
	movq	%fs:40, %rax
	movq	%rax, 152(%rsp)
	xorl	%eax, %eax
.LEHB0:
	call	_ZNSt8ios_base15sync_with_stdioEb
	leaq	72(%rsp), %rsi
	movl	$_ZSt3cin, %edi
	movq	$0, _ZSt3cin+232(%rip)
	call	_ZNSi10_M_extractIxEERSiRT_
.LEHE0:
	movq	72(%rsp), %rbx
	leaq	104(%rsp), %rax
	movl	$0, 104(%rsp)
	movq	$0, 112(%rsp)
	movq	$0, 136(%rsp)
	movq	%rax, 120(%rsp)
	movq	%rax, 128(%rsp)
	testq	%rbx, %rbx
	je	.L122
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rbx
	ja	.L235
	leaq	0(,%rbx,8), %r13
	movq	%r13, %rdi
.LEHB1:
	call	_Znwm
.LEHE1:
	movq	%rax, %r12
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L124:
	movq	$0, (%r12,%rax,8)
	addq	$1, %rax
	cmpq	%rax, %rbx
	jne	.L124
	addq	%r12, %r13
	cmpq	$0, 72(%rsp)
	jle	.L125
	movq	%r12, %rbx
	xorl	%ebp, %ebp
	.p2align 4,,10
	.p2align 3
.L132:
	movq	%rbx, %rsi
	movl	$_ZSt3cin, %edi
.LEHB2:
	call	_ZNSi10_M_extractIxEERSiRT_
	movq	112(%rsp), %rdx
	testq	%rdx, %rdx
	je	.L189
	movq	(%rbx), %rcx
	leaq	104(%rsp), %rax
	jmp	.L127
	.p2align 4,,10
	.p2align 3
.L236:
	movq	%rdx, %rax
	movq	16(%rdx), %rdx
	testq	%rdx, %rdx
	je	.L128
.L127:
	cmpq	32(%rdx), %rcx
	jle	.L236
	movq	24(%rdx), %rdx
	testq	%rdx, %rdx
	jne	.L127
.L128:
	leaq	104(%rsp), %rdx
	cmpq	%rdx, %rax
	je	.L126
	cmpq	32(%rax), %rcx
	jge	.L131
.L126:
	leaq	11(%rsp), %r8
	leaq	16(%rsp), %rcx
	leaq	96(%rsp), %rdi
	movl	$_ZStL19piecewise_construct, %edx
	movq	%rax, %rsi
	movq	%rbx, 16(%rsp)
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
.L131:
	addq	$1, 40(%rax)
	addq	$1, %rbp
	addq	$8, %rbx
	cmpq	%rbp, 72(%rsp)
	jg	.L132
.L125:
	cmpq	%r13, %r12
	je	.L133
	movq	%r13, %rbx
	movl	$63, %edx
	movq	%r13, %rsi
	subq	%r12, %rbx
	movq	%r12, %rdi
	movq	%rbx, %rax
	sarq	$3, %rax
	bsrq	%rax, %rax
	xorq	$63, %rax
	cltq
	subq	%rax, %rdx
	addq	%rdx, %rdx
	call	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_.isra.54
	cmpq	$135, %rbx
	jle	.L134
	leaq	128(%r12), %rbx
	pushq	%rsi
	.cfi_def_cfa_offset 216
	pushq	$0
	.cfi_def_cfa_offset 224
	movq	%r12, %rdi
	movq	%rbx, %rsi
	call	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_
	cmpq	%r13, %rbx
	popq	%rdi
	.cfi_def_cfa_offset 216
	popq	%r8
	.cfi_def_cfa_offset 208
	je	.L139
	movq	%rbx, %rdi
	movq	(%rdi), %rsi
	movq	-8(%rdi), %rdx
	leaq	-8(%rdi), %rax
	cmpq	%rdx, %rsi
	jl	.L137
	jmp	.L237
	.p2align 4,,10
	.p2align 3
.L193:
	movq	%rcx, %rax
.L137:
	movq	%rdx, 8(%rax)
	movq	-8(%rax), %rdx
	leaq	-8(%rax), %rcx
	cmpq	%rdx, %rsi
	jl	.L193
.L136:
	addq	$8, %rdi
	movq	%rsi, (%rax)
	cmpq	%rdi, %r13
	je	.L139
	movq	(%rdi), %rsi
	movq	-8(%rdi), %rdx
	leaq	-8(%rdi), %rax
	cmpq	%rdx, %rsi
	jl	.L137
.L237:
	movq	%rdi, %rax
	jmp	.L136
.L189:
	leaq	104(%rsp), %rax
	jmp	.L126
.L122:
	xorl	%r12d, %r12d
.L133:
	cmpq	$0, 72(%rsp)
	jle	.L238
	leaq	80(%rsp), %r13
	movq	%r12, %rbx
	xorl	%ebp, %ebp
	xorl	%r14d, %r14d
	.p2align 4,,10
	.p2align 3
.L172:
	movq	112(%rsp), %rdx
	testq	%rdx, %rdx
	movq	%rdx, %rax
	je	.L195
	movq	(%rbx), %rcx
	leaq	104(%rsp), %rsi
	jmp	.L144
	.p2align 4,,10
	.p2align 3
.L239:
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L145
.L144:
	cmpq	%rcx, 32(%rax)
	jge	.L239
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L144
.L145:
	leaq	104(%rsp), %rax
	cmpq	%rax, %rsi
	je	.L143
	cmpq	%rcx, 32(%rsi)
	jg	.L143
	cmpq	$0, 40(%rsi)
	jne	.L184
.L149:
	addq	$1, %rbp
	addq	$8, %rbx
	cmpq	%rbp, 72(%rsp)
	jg	.L172
.L140:
	movq	%r14, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIxEERSoT_
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	testq	%r12, %r12
	je	.L173
	movq	%r12, %rdi
	call	_ZdlPv
.L173:
	movq	112(%rsp), %rsi
	leaq	96(%rsp), %rdi
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	xorl	%eax, %eax
	movq	152(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L240
	addq	$160, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L195:
	.cfi_restore_state
	leaq	96(%rsp), %rax
	leaq	8(%rax), %rsi
	.p2align 4,,10
	.p2align 3
.L143:
	leaq	12(%rsp), %r8
	leaq	32(%rsp), %rcx
	leaq	96(%rsp), %rdi
	movl	$_ZStL19piecewise_construct, %edx
	movq	%rbx, 32(%rsp)
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	cmpq	$0, 40(%rax)
	je	.L149
	movq	112(%rsp), %rdx
	testq	%rdx, %rdx
	je	.L197
	movq	(%rbx), %rcx
.L184:
	movq	%rdx, %rax
	leaq	104(%rsp), %rsi
	jmp	.L151
	.p2align 4,,10
	.p2align 3
.L241:
	movq	%rax, %rsi
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L152
.L151:
	cmpq	32(%rax), %rcx
	jle	.L241
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L151
.L152:
	leaq	104(%rsp), %rax
	cmpq	%rax, %rsi
	je	.L150
	cmpq	32(%rsi), %rcx
	jl	.L150
	subq	$1, 40(%rsi)
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L242
.L187:
	movq	%rdi, %rax
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L157:
	movq	%rax, %rsi
	addq	$1, %rcx
	shrq	$63, %rsi
	addq	%rsi, %rax
	sarq	%rax
	jne	.L157
	movl	$1, %eax
	salq	%cl, %rax
	movq	%rax, %rcx
	subq	%rdi, %rcx
	testq	%rdx, %rdx
	movq	%rcx, 80(%rsp)
	je	.L243
.L159:
	leaq	104(%rsp), %rax
	jmp	.L161
	.p2align 4,,10
	.p2align 3
.L245:
	movq	%rdx, %rax
	movq	16(%rdx), %rdx
	testq	%rdx, %rdx
	je	.L244
.L161:
	cmpq	32(%rdx), %rcx
	jle	.L245
	movq	24(%rdx), %rdx
	testq	%rdx, %rdx
	jne	.L161
.L244:
	leaq	104(%rsp), %rdx
	cmpq	%rdx, %rax
	je	.L158
	cmpq	32(%rax), %rcx
	jge	.L164
.L158:
	leaq	14(%rsp), %r8
	leaq	48(%rsp), %rcx
	leaq	96(%rsp), %rdi
	movl	$_ZStL19piecewise_construct, %edx
	movq	%rax, %rsi
	movq	%r13, 48(%rsp)
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
.L164:
	cmpq	$0, 40(%rax)
	je	.L149
	movq	112(%rsp), %rdx
	testq	%rdx, %rdx
	je	.L202
	movq	80(%rsp), %rcx
	leaq	104(%rsp), %rax
	jmp	.L167
	.p2align 4,,10
	.p2align 3
.L246:
	movq	%rdx, %rax
	movq	16(%rdx), %rdx
	testq	%rdx, %rdx
	je	.L168
.L167:
	cmpq	32(%rdx), %rcx
	jle	.L246
	movq	24(%rdx), %rdx
	testq	%rdx, %rdx
	jne	.L167
.L168:
	leaq	104(%rsp), %rdx
	cmpq	%rdx, %rax
	je	.L166
	cmpq	32(%rax), %rcx
	jge	.L171
.L166:
	leaq	15(%rsp), %r8
	leaq	64(%rsp), %rcx
	leaq	96(%rsp), %rdi
	movl	$_ZStL19piecewise_construct, %edx
	movq	%rax, %rsi
	movq	%r13, 64(%rsp)
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
.L171:
	subq	$1, 40(%rax)
	addq	$1, %r14
	jmp	.L149
.L197:
	leaq	96(%rsp), %rax
	leaq	8(%rax), %rsi
	.p2align 4,,10
	.p2align 3
.L150:
	leaq	13(%rsp), %r8
	leaq	96(%rsp), %rdi
	movq	%r13, %rcx
	movl	$_ZStL19piecewise_construct, %edx
	movq	%rbx, 80(%rsp)
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
.LEHE2:
	subq	$1, 40(%rax)
	movq	112(%rsp), %rdx
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	jne	.L187
	movl	$1, %ecx
	subq	%rdi, %rcx
	testq	%rdx, %rdx
	movq	%rcx, 80(%rsp)
	jne	.L159
.L243:
	leaq	104(%rsp), %rax
	jmp	.L158
.L242:
	movq	$1, 80(%rsp)
	movl	$1, %ecx
	jmp	.L159
.L134:
	pushq	%rax
	.cfi_def_cfa_offset 216
	pushq	$0
	.cfi_def_cfa_offset 224
	movq	%r13, %rsi
	movq	%r12, %rdi
	call	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_
	popq	%rdx
	.cfi_def_cfa_offset 216
	popq	%rcx
	.cfi_def_cfa_offset 208
.L139:
	subq	$8, %r13
	movq	%r12, %rax
	cmpq	%r12, %r13
	jbe	.L133
	.p2align 4,,10
	.p2align 3
.L211:
	movq	(%rax), %rdx
	movq	0(%r13), %rcx
	addq	$8, %rax
	subq	$8, %r13
	movq	%rcx, -8(%rax)
	movq	%rdx, 8(%r13)
	cmpq	%r13, %rax
	jb	.L211
	jmp	.L133
.L202:
	leaq	104(%rsp), %rax
	jmp	.L166
.L238:
	xorl	%r14d, %r14d
	jmp	.L140
.L240:
	call	__stack_chk_fail
.L235:
.LEHB3:
	call	_ZSt17__throw_bad_allocv
.LEHE3:
.L205:
	movq	%rax, %rbx
.L176:
	movq	112(%rsp), %rsi
	leaq	96(%rsp), %rdi
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	%rbx, %rdi
.LEHB4:
	call	_Unwind_Resume
.LEHE4:
.L206:
	testq	%r12, %r12
	movq	%rax, %rbx
	je	.L176
	movq	%r12, %rdi
	call	_ZdlPv
	jmp	.L176
	.cfi_endproc
.LFE12856:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA12856:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE12856-.LLSDACSB12856
.LLSDACSB12856:
	.uleb128 .LEHB0-.LFB12856
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB12856
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L205-.LFB12856
	.uleb128 0
	.uleb128 .LEHB2-.LFB12856
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L206-.LFB12856
	.uleb128 0
	.uleb128 .LEHB3-.LFB12856
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L205-.LFB12856
	.uleb128 0
	.uleb128 .LEHB4-.LFB12856
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE12856:
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE8:
	.section	.text.startup
.LHOTE8:
	.section	.text.unlikely
.LCOLDB9:
	.section	.text.startup
.LHOTB9:
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z5mmnmmx, @function
_GLOBAL__sub_I__Z5mmnmmx:
.LFB14329:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE14329:
	.size	_GLOBAL__sub_I__Z5mmnmmx, .-_GLOBAL__sub_I__Z5mmnmmx
	.section	.text.unlikely
.LCOLDE9:
	.section	.text.startup
.LHOTE9:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z5mmnmmx
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
