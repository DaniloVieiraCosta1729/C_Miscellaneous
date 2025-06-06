	.file	"testPtF.c"
	.intel_syntax noprefix
	.text
	.globl	_power
_power:
LFB10:
	
	push ebp
	
	mov	ebp, esp
	
	sub	esp, 24
	cmp	DWORD PTR [ebp+12], 1
	jne	L2
	mov	eax, DWORD PTR [ebp+8]
	jmp	L3
L2:
	mov	eax, DWORD PTR [ebp+12]
	sub	eax, 1
	mov	DWORD PTR [esp+4], eax
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [esp], eax
	call	_power
	imul	eax, DWORD PTR [ebp+8]
L3:
	leave
	
	ret
	
LFE10:
	
	.section .rdata,"dr"
LC0:
	.ascii "2 ^ 4 = %d\12\0"
LC1:
	.ascii "3 ^ 3 = %d\12\0"
	.text
	.globl	_main
_main:
LFB11:
	
	push	ebp
	
	
	mov	ebp, esp
	
	and	esp, -16
	sub	esp, 32
	call	___main
	mov	DWORD PTR [esp+28], OFFSET FLAT:_power
	mov	DWORD PTR [esp+4], 4
	mov	DWORD PTR [esp], 2
	mov	eax, DWORD PTR [esp+28]
	call	eax
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_printf
	mov	DWORD PTR [esp+4], 3
	mov	DWORD PTR [esp], 3
	mov	eax, DWORD PTR [esp+28]
	call	eax
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	_printf
	mov	eax, 0
	leave
	
	ret
