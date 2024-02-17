.section .text

.global mmap1

mmap1:
    mov w8, #222
    svc #0
    ret

.global munmap

munmap:
    mov w8, #215
    svc #0
    ret
    