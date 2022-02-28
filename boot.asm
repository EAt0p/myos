[bits 16]
[org 0x7c00]
mov [DRIVE], dl
xor ax, ax
mov es, ax
mov bx, 0x1000
mov dh, 20
call Read

mov ah, 0
mov al, 3
int 0x10

cli
lgdt [toc]
mov eax, cr0
or al, 1
mov cr0, eax
jmp 0x8:init_pm
Read:
 mov ah, 2
 mov al, dh
 mov ch, 0
 mov dh, 0
 mov cl, 2
 int 0x13
 ret
gdt:
 dq 0
gdt_code:
 dw 0xffff
 dw 0
 db 0
 db 10011010b
 db 11001111b
 db 0
gdt_data:
 dw 0xffff
 dw 0
 db 0
 db 10010010b
 db 11001111b
 db 0
gdt_end:
toc:
 dw gdt_end - gdt
 dd gdt
[bits 32]
init_pm:
 mov ax, 0x10
 mov es, ax
 mov ds, ax
 mov ss, ax
 mov fs, ax
 mov gs, ax
 mov ebp, 0x90000
 mov esp, ebp
 jmp 0x1000
DRIVE db 0
times 510-($-$$) db 0
dw 0xaa55
