global loader

MAGIC_NUMBER equ 0x1BADB002
FLAGS        equ 0x0
CHECKSUM     equ -MAGIC_NUMBER

KERNEL_STACK_SIZE equ 4096

section .text

extern osmain

align 4
  dd MAGIC_NUMBER
  dd FLAGS
  dd CHECKSUM

loader:
  mov eax, 0xcafebabe
  mov esp, kernel_stack + KERNEL_STACK_SIZE

  call osmain

  .loop:
    jmp .loop

%include 'io.s'

section .bss
align 4
kernel_stack:
  resb KERNEL_STACK_SIZE
