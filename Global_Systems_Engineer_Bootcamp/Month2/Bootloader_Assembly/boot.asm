; Simple boot sector that prints a message via BIOS teletype (for v86)
org 0x7c00
    mov si, msg
.print:
    lodsb
    cmp al, 0
    je .done
    mov ah, 0x0e
    mov bh, 0x00
    mov bl, 0x07
    int 0x10
    jmp .print
.done:
    cli
    hlt
msg db 'Hello from bootloader!',0
times 510-($-$$) db 0
dw 0xAA55
