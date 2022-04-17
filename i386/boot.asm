[bits 16]
[org 0x7c00]
CODESEG equ gdt_code - gdt
DATASEG equ gdt_data - gdt
xor bx, bx
mov ax, 0x0100
mov es, ax

mov [DRIVE], dl
mov ah, 2
mov al, 20
mov ch, 0		;cylinder (there is 18 sectors per cylinder)
mov dh, 0		;head
mov cl, 2
mov dl, [DRIVE]
int 0x13
jc read_err

mov ah, 0
mov al, 3		;text mode
int 0x10

cli
lgdt [gdt_desc]
mov eax, cr0
or al, 1
mov cr0, eax
jmp CODESEG:init_pm
Print:
 lodsb
 or al, al
 jz pdone
 mov ah, 0x0e
 int 0x10
 jmp Print
pdone:
 ret
read_err:
 xor ax, ax
 mov ds, ax
 mov es, ax
 mov si, msg
 call Print
 cli
 hlt
gdt:
 dq 0		;define 8 bytes(64bits)
gdt_code:
 dw 0xffff		;limit low
 dw 0			;base low
 db 0			;base mid
 db 10011010b		;privilages
 db 11001111b		;flags(bit 4-7) and limit high(bit 0-3)
 db 0			;base high
gdt_data:
 dw 0xffff
 dw 0
 db 0
 db 10010010b
 db 11001111b
 db 0
gdt_end:
gdt_desc:
 dw gdt_end - gdt - 1		;size of gdt-1
 dd gdt
DRIVE db 0
[bits 32]
init_pm:
 mov ax, DATASEG
 mov ds, ax
 mov ss, ax
 mov es, ax
 mov fs, ax
 mov gs, ax
 mov ebp, 0x90000
 mov esp, ebp
 jmp 0x1000
msg db "Disk read error", 0x0d, 0x0a
times 510-($-$$) db 0
dw 0xaa55
