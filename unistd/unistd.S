.section .text

.global write

write:   	
	mov w8, #64 //Syscall number for write for ARM64
    svc #0

    ret

.global _exit

_exit:
    mov w8, #93
    svc #0

.global read

read:
    //ldr x1, =buffer
    mov w8, #63
    svc #0
    
.section .data
buffer: .space 100