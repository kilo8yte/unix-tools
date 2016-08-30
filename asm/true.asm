;----------------------------------------------------------------------------
;"THE BEER-WARE LICENSE" (Revision 42):
;<benni@include-benni.de> wrote this file. As long as you retain this notice you
;can do whatever you want with this stuff. If we meet some day, and you think
;this stuff is worth it, you can buy me a beer in return Benjamin Hartmann
; ----------------------------------------------------------------------------

section .text
	global _start

_start:
	mov eax,1
	xor ebx,ebx
	int 0x80
