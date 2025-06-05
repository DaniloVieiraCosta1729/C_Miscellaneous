	.file	"register.c"
	.intel_syntax noprefix
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB0:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	push	ebx
	and	esp, -16
	sub	esp, 16
	.cfi_offset 3, -12
	call	___main
	mov	ebx, 3
	lea	eax, [ebx+1]
	mov	DWORD PTR [esp+12], eax
	lea	eax, [ebx-1]
	mov	DWORD PTR [esp+8], eax
	mov	edx, DWORD PTR [esp+12]
	mov	eax, DWORD PTR [esp+8]
	add	eax, edx
	mov	DWORD PTR [esp+4], eax
	mov	eax, 0
	mov	ebx, DWORD PTR [ebp-4]
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
