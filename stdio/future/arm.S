section .text
global x86_div64_32
x86_div64_32:

    // make new call frame
    stp x29, x30, [sp, -16]!    // save old call frame
    mov x29, sp                  // initialize new call frame

    stp x19, x20, [sp, -16]!    // save registers
    stp x21, x22, [sp, -16]!
    stp x23, x24, [sp, -16]!
    stp x25, x26, [sp, -16]!
    stp x27, x28, [sp, -16]!

    // divide upper 32 bits
    ldr x19, [x29, 8]            // x19 <- upper 32 bits of dividend
    ldr x20, [x29, 12]           // x20 <- divisor
    mov x21, 0                   // clear x21 (equivalent to xor edx, edx)
    udiv x22, x19, x20           // x22 - quot, x21 - remainder

    // store upper 32 bits of quotient
    ldr x23, [x29, 16]
    str x22, [x23, 4]

    // divide lower 32 bits
    ldr x19, [x29, 4]            // x19 <- lower 32 bits of dividend
                                 // x21 <- old remainder
    udiv x22, x19, x20           // x22 - quot, x21 - remainder

    // store results
    str x22, [x23]
    ldr x23, [x29, 18]
    str x21, [x23]

    // restore registers
    ldp x19, x20, [sp], 16
    ldp x21, x22, [sp], 16
    ldp x23, x24, [sp], 16
    ldp x25, x26, [sp], 16
    ldp x27, x28, [sp], 16

    // restore old call frame
    mov sp, x29
    ldp x29, x30, [sp], 16
    ret

section .text
global x86_Video_WriteCharTeletype
x86_Video_WriteCharTeletype:

    // make new call frame
    stp x29, x30, [sp, -16]!    // save old call frame
    mov x29, sp                  // initialize new call frame

    stp x19, x20, [sp, -16]!    // save registers

    // [x29 + 0] - old call frame
    // [x29 + 8] - return address
    // [x29 + 16] - first argument (character)
    // [x29 + 24] - second argument (page)
    ldrb w0, [x29, 16]           // w0 <- character
    ldrb w1, [x29, 24]           // w1 <- page

    mov w8, 0xE                  // AH register value
    svc 0x10                      // int 10h

    // restore registers
    ldp x19, x20, [sp], 16

    // restore old call frame
    mov sp, x29
    ldp x29, x30, [sp], 16
    ret
