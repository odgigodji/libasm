section .text
	global _ft_strcpy

_ft_strcpy: ; rdi = dst, rsi = src
	mov rcx, 0
.loop:
	cmp byte [rsi + rcx], 0
	je .return 
	mov dl, [rsi + rcx]
	mov byte [rdi + rcx], dl
	inc rcx
	jmp .loop
.return:
	mov byte [rdi + rcx], 0
	mov rax, rdi
	ret 
