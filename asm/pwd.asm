;----------------------------------------------------------------------------
;"THE BEER-WARE LICENSE" (Revision 42):
;<benni@include-benni.de> wrote this file. As long as you retain this notice you
;can do whatever you want with this stuff. If we meet some day, and you think
;this stuff is worth it, you can buy me a beer in return Benjamin Hartmann
; ----------------------------------------------------------------------------

section .text
	global _start
_start:
;sys_brk get adress 
	mov eax,45
	xor ebx,ebx
	int 0x80

;second sys_brk allocate after application image
	add eax,4096
	mov ebx,eax
	mov eax,45
	int 0x80

;check for an error
	call error


	mov edi,eax
	sub edi,4096

;get current working directory
	mov eax,183
	mov ebx,edi
	mov ecx,4095
	int 0x80

	call error

;append newline to current working directory
	mov byte[edi+eax-1],0xa

	mov edx,eax
	mov eax,4
	mov ebx,1
	mov ecx,edi
	int 0x80

	call error
	ja return

return:
	mov eax,0
exit:
	mov ebx,eax
	mov eax,1
	int 0x80

error:
	cmp eax,0
	jl exit
	ret
