	main PROC		 ;Line# 2
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP		 ;Line# 2
	MOV BP, SP
		 ;Line# 2
	SUB SP, 2
	PUSH 6		 ;Line# 4
	POP AX		 ;Line# 4
	MOV W. [BP-2], AX		 ;Line# 4
	PUSH AX		 ;Line# 4
	POP AX		 ;Line# 4
	PUSH 2		 ;Line# 5
	POP AX		 ;Line# 5
	SHL AX, 1		 ;Line# 5
	LEA SI, a		 ;Line# 5
	SUB SI, AX		 ;Line# 5
	ADD SI, BP		 ;Line# 5
	PUSH SI
		 ;Line# 5
	PUSH 5		 ;Line# 5
	POP AX		 ;Line# 5
	POP SI		 ;Line# 5
	MOV [SI], AX		 ;Line# 5
	PUSH AX		 ;Line# 5
	POP AX		 ;Line# 5
	MOV AX, W. [BP-2]		 ;Line# 7
	CALL print_output		 ;Line# 7
	POP BP		 ;Line# 8

	L0:
		 ;Line# 8
	MOV AH, 4CH
	INT 21H
	main ENDP
		 ;Line# 8
new_line proc 
	push ax
	push dx
	mov ah,2
	mov dl,cr
	int 21h
	mov ah,2
	mov dl,lf
	int 21h
	pop dx
	pop ax
	ret
	new_line endp
print_output proc  ;print what is in ax
	push ax
	push bx
	push cx
	push dx
	push si
	lea si,number
	mov bx,10
	add si,4
	cmp ax,0
	jnge negate
	print:
	xor dx,dx
	div bx
	mov [si],dl
	add [si],'0'
	dec si
	cmp ax,0
	jne print
	inc si
	lea dx,si
	mov ah,9
	int 21h
	call new_line
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret
	negate:
	push ax
	mov ah,2
	mov dl,'-'
	int 21h
	pop ax
	neg ax
	jmp print
	print_output endp
END main