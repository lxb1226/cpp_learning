	.text
	.file	"test8.cpp"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	movl	$5, -4(%rbp)  # 把5给到%rbp - 4
	leaq	-4(%rbp), %rcx # 根据括号里的源操作数计算地址，然后把地址加载到目标寄存器中
	movq	%rcx, -16(%rbp) # 把5的地址赋给 %rbp - 4
	movq	-16(%rbp), %rcx
	movl	$8, (%rcx)
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 10.0.0-4ubuntu1 "
	.section	".note.GNU-stack","",@progbits
	.addrsig
