section .text
	global _ft_strcmp

_ft_strcmp: ;s1 = rdi, s2 = rsi
	mov rcx, 0
.loop:
	cmp byte [rdi + rcx], 0 
	je .return
	cmp byte [rsi + rcx], 0 
	je .return
	mov dl, byte [rsi + rcx]
	cmp byte [rdi + rcx], dl	
	jne .return
	inc rcx
	jmp .loop
.return: 
	movzx rax, byte [rdi + rcx]
	movzx rdi, byte [rsi + rcx]
	sub rax, rdi
	ret 
