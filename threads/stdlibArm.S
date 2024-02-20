.section .text

.global mmap

mmap:
    mov w8, #222
    svc #0
    ret

.global munmap

munmap:
    mov w8, #215
    svc #0
    ret
    