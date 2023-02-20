	func PROC
	PUSH BP
	MOV BP, SP

	SUB SP, 2
	PUSH W. [BP+6]
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JE L0
	PUSH 0
	JMP L1
	L0:
	PUSH 1
	L1:

	POP AX
	CMP AX, 0
	JE L2
	PUSH 0
	POP AX
	MOV [BP+4], AX
	ADD SP, 2
	POP BP
	RET
	L2:

	PUSH W. [BP+6]
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	PUSH W. [BP+6]
	PUSH 1
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	PUSH 0
	CALL func
	POP AX
	ADD SP,2
	PUSH AX
	PUSH W. [BP-2]
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV [BP+4], AX
	ADD SP, 2
	POP BP
	RET
	POP BP
	RET
	func ENDP

	func2 PROC
	PUSH BP
	MOV BP, SP

	SUB SP, 2
	PUSH W. [BP+6]
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JE L3
	PUSH 0
	JMP L4
	L3:
	PUSH 1
	L4:

	POP AX
	CMP AX, 0
	JE L5
	PUSH 0
	POP AX
	MOV [BP+4], AX
	ADD SP, 2
	POP BP
	RET
	L5:

	PUSH W. [BP+6]
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	PUSH W. [BP+6]
	PUSH 1
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	PUSH 0
	CALL func
	POP AX
	ADD SP,2
	PUSH AX
	PUSH W. [BP-2]
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV [BP+4], AX
	ADD SP, 2
	POP BP
	RET
	POP BP
	RET
	func2 ENDP

	main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP

	SUB SP, 2
	PUSH 7
	PUSH 0
	CALL func
	POP AX
	ADD SP,2
	PUSH AX
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	MOV AX, W. [BP-2]
	CALL print_output
	PUSH 0
	POP BP

	L6:

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