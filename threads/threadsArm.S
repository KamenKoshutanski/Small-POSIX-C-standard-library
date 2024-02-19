.section .text

.global getpid1

getpid1:
    mov w8, #172
    svc #0
    ret

.global getppid1

getppid1:
    mov w8, #173
    svc #0
    ret

.global clone1

clone1:

    mov w8, #220 //435
    svc #0
    ret
