.section .text

.global write

write:   	
	mov w8, #64 
    svc #0

    ret

.global _exit

_exit:
    mov w8, #93
    svc #0
