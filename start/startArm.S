.section .text

.global _start

_start:
    bl main

    mov w8, #93
    svc #0
    ret
