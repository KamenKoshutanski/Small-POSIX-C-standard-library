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

.global clone2

clone2:
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
