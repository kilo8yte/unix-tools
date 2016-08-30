;----------------------------------------------------------------------------
;"THE BEER-WARE LICENSE" (Revision 42):
;<benni@include-benni.de> wrote this file. As long as you retain this notice you
;can do whatever you want with this stuff. If we meet some day, and you think
;this stuff is worth it, you can buy me a beer in return Benjamin Hartmann
; ----------------------------------------------------------------------------


section .text
	global _start
_start:
	pop ebp
	pop ecx
	dec ebp
	jz end
loop:
	mov eax,4
	mov ebx,1
	pop ecx
	call strlen
	int 0x80
	dec ebp
	jnz loop

end:	
	push 0xa
	mov eax,4
	mov ecx,esp
	mov edx,1
	int 0x80

	mov eax,1
	xor ebx,ebx
	int 0x80

strlen:
	xor edx,edx
loop1:	
	add edx,1
	cmp byte [ecx+edx],0x0
	jnz loop1
	mov byte[ecx+edx],0x20
	add edx,1
	ret


