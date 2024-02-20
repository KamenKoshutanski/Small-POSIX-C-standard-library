.section .text

.global putToStdOut

putToStdOut:
    mov x1, x0
    mov x0, #1
    mov x2, #1
    mov w8, #64 
    svc #0

    ret

.global getFromStdIn

getFromStdIn:
    //mov x1, #0
    //mov x2, #1
    //mov w8, #63
    //svc #0

    mov x0, #0
    ldr x1, =buffer	
    mov x2, #1
    mov w8, #63
    svc #0
    ret
    
.section .data
    buffer: .space 100
