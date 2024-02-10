.section .text

.global putToStdOut

putToStdOut:
    mov x1, x0
    mov x0, #1
    mov x2, #1
    mov w8, #64 
    svc #0

    ret
    