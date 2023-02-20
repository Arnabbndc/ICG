	f PROC
	PUSH BP
	MOV BP, SP

	SUB SP, 2
	PUSH 5
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	L0:
	PUSH W. [BP-2]
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JG L2
	PUSH 0
	JMP L3
	L2:
	PUSH 1
	L3:

	POP AX
	CMP AX,0
	JE L1
	PUSH W. [BP+6]
	INC W. [BP+6]
	POP AX
	PUSH W. [BP-2]
	DEC W. [BP-2]
	POP AX
	JMP L0
	L1:

	PUSH 3
	PUSH W. [BP+6]
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	PUSH 7
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP AX
	MOV [BP+4], AX
	PUSH 9
	POP AX
	MOV W. [BP+6], AX
	PUSH AX
	POP AX
	ADD SP,2
	POP BP
	RET
	f ENDP

	g PROC
	PUSH BP
	MOV BP, SP

	SUB SP, 2
	SUB SP, 2
	PUSH W. [BP+8]
	PUSH 0
	CALL f
	POP AX
	ADD SP,2
	PUSH AX
	PUSH W. [BP+8]
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	PUSH W. [BP+6]
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	PUSH 0
	POP AX
	MOV W. [BP-4], AX
	PUSH AX
	POP AX
	L4:
	PUSH W. [BP-4]
	PUSH 7
	POP BX
	POP AX
	CMP AX, BX
	JL L8
	PUSH 0
	JMP L9
	L8:
	PUSH 1
	L9:

	POP AX
	CMP AX, 0
	JE L7
	JMP L5
	L6:
	PUSH W. [BP-4]
	INC W. [BP-4]
	POP AX
	JMP L4
	L5:
	PUSH W. [BP-4]
	PUSH 3
	POP BX
	POP AX
	XOR DX, DX
	IDIV BX
	PUSH DX
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JE L10
	PUSH 0
	JMP L11
	L10:
	PUSH 1
	L11:

	POP AX
	CMP AX, 0
	JE L12
	PUSH W. [BP-2]
	PUSH 5
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	JMP L13
	L12:

	PUSH W. [BP-2]
	PUSH 1
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	L13:

	JMP L6
	L7:
	PUSH W. [BP-2]
	POP AX
	MOV [BP+4], AX
	ADD SP,4
	POP BP
	RET
	g ENDP

	main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP

	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	PUSH 1
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	PUSH 2
	POP AX
	MOV W. [BP-4], AX
	PUSH AX
	POP AX
	PUSH W. [BP-2]
	PUSH W. [BP-4]
	PUSH 0
	CALL g
	POP AX
	ADD SP,4
	PUSH AX
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	MOV AX, W. [BP-2]
	CALL print_output
	PUSH 0
	POP AX
	MOV W. [BP-6], AX
	PUSH AX
	POP AX
	L15:
	PUSH W. [BP-6]
	PUSH 4
	POP BX
	POP AX
	CMP AX, BX
	JL L19
	PUSH 0
	JMP L20
	L19:
	PUSH 1
	L20:

	POP AX
	CMP AX, 0
	JE L18
	JMP L16
	L17:
	PUSH W. [BP-6]
	INC W. [BP-6]
	POP AX
	JMP L15
	L16:
	PUSH 3
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	L21:
	PUSH W. [BP-2]
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JG L23
	PUSH 0
	JMP L24
	L23:
	PUSH 1
	L24:

	POP AX
	CMP AX,0
	JE L22
	PUSH W. [BP-4]
	INC W. [BP-4]
	POP AX
	PUSH W. [BP-2]
	DEC W. [BP-2]
	POP AX
	JMP L21
	L22:

	JMP L17
	L18:
	MOV AX, W. [BP-2]
	CALL print_output
	MOV AX, W. [BP-4]
	CALL print_output
	MOV AX, W. [BP-6]
	CALL print_output
	PUSH 0
	POP AX
	MOV [BP+4], AX
	ADD SP,6
	POP BP

	L14:

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