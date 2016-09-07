

section .text
	global _start

_start:
	mov eax,1
	xor ebx,eax
	int 0x80
