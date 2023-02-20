	func_a PROC
	PUSH BP
	MOV BP, SP

	PUSH 7
	POP AX
	MOV a, AX
	PUSH AX
	POP AX
	ADD SP,0
	POP BP
	RET
	func_a ENDP

	foo PROC
	PUSH BP
	MOV BP, SP

	PUSH W. [BP+6]
	PUSH 3
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV W. [BP+6], AX
	PUSH AX
	POP AX
	PUSH W. [BP+6]
	POP AX
	MOV [BP+4], AX
	ADD SP,0
	POP BP
	RET
	foo ENDP

	bar PROC
	PUSH BP
	MOV BP, SP

	PUSH 4
	PUSH W. [BP+8]
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	PUSH 2
	PUSH W. [BP+6]
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV c, AX
	PUSH AX
	POP AX
	PUSH c
	POP AX
	MOV [BP+4], AX
	ADD SP,0
	POP BP
	RET
	bar ENDP

	main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP

	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	PUSH 5
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	PUSH 6
	POP AX
	MOV W. [BP-4], AX
	PUSH AX
	POP AX
	PUSH 0
	CALL func_a
	POP AX
	ADD SP,0
	PUSH AX
	POP AX
	MOV AX, a
	CALL print_output
	PUSH W. [BP-2]
	PUSH 0
	CALL foo
	POP AX
	ADD SP,2
	PUSH AX
	POP AX
	MOV W. [BP-6], AX
	PUSH AX
	POP AX
	MOV AX, W. [BP-6]
	CALL print_output
	PUSH W. [BP-2]
	PUSH W. [BP-4]
	PUSH 0
	CALL bar
	POP AX
	ADD SP,4
	PUSH AX
	POP AX
	MOV W. [BP-8], AX
	PUSH AX
	POP AX
	MOV AX, W. [BP-8]
	CALL print_output
	PUSH 6
	PUSH W. [BP-2]
	PUSH W. [BP-4]
	PUSH 0
	CALL bar
	POP AX
	ADD SP,4
	PUSH AX
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	PUSH 2
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	PUSH 3
	PUSH W. [BP-2]
	PUSH 0
	CALL foo
	POP AX
	ADD SP,2
	PUSH AX
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP AX
	MOV W. [BP-4], AX
	PUSH AX
	POP AX
	MOV AX, W. [BP-4]
	CALL print_output
	PUSH 0
	POP AX
	MOV [BP+4], AX
	ADD SP,8
	POP BP

	L0:

	MOV AH, 4CH
	INT 21H
	main ENDP

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