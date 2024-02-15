.section .text

.global nanosleep

nanosleep:
    mov w8, #101
    svc #0
    