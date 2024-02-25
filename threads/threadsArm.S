.section .text

.global getpid

getpid:
    mov w8, #172
    svc #0
    ret

.global getppid

getppid:
    mov w8, #173
    svc #0
    ret

.global clone_kernel

clone_kernel:
    mov w8, #220 //435
    svc #0
    ret

.global kill

kill:
    mov w8, #129
    svc #0
    ret

.global wait

wait:
    mov w8, #260
    svc #0
    ret
