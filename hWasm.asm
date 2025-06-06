.intel_syntax noprefix

.section .rodata

textao:
    .asciz "Escrevendo o primeiro texto no assembly.\n"



.text
.extern _printf
.globl _main
_main:
    push ebp
    mov ebp, esp
    push offset textao
    call _printf
    add esp, 4

    mov esp, ebp
    pop ebp
    ret
