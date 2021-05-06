section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup: 		;	str = rdi
	mov rdx, rdi 	;	str = rdx
	call _ft_strlen ;	len = rax
	inc rax
	push rdi
	mov rdi, rax
	call _malloc
	pop rdi
	cmp rax, 0      ;   check malloc
	je .return
	mov rsi, rdi	;	rsi = str
	mov rdi, rax
	call _ft_strcpy ; 	rdi = dst, rsi = src
	mov rax, rdi
	ret
	
.return:
	ret
