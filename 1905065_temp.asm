	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	PUSH 3
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
	PUSH 8
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
	PUSH 6
	POP AX
	MOV [BP-6], AX
	PUSH AX
	POP AX
	PUSH [BP-2]
	PUSH 3
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
	MOV AX, [BP-4]
	CALL print_output
	L2:

	PUSH [BP-4]
	PUSH 8
	POP BX
	POP AX
	CMP AX, BX
	JL L3
	PUSH 0
	JMP L4
	L3:
	PUSH 1
	L4:

	POP AX
	CMP AX, 0
	JE L5
	MOV AX, [BP-2]
	CALL print_output
	JMP L6
	L5:

	MOV AX, [BP-6]
	CALL print_output
	L6:

	PUSH [BP-6]
	PUSH 6
	POP BX
	POP AX
	CMP AX, BX
	JNE L7
	PUSH 0
	JMP L8
	L7:
	PUSH 1
	L8:

	POP AX
	CMP AX, 0
	JE L9
	MOV AX, [BP-6]
	CALL print_output
	JMP L10
	L9:

	PUSH [BP-4]
	PUSH 8
	POP BX
	POP AX
	CMP AX, BX
	JG L11
	PUSH 0
	JMP L12
	L11:
	PUSH 1
	L12:

	POP AX
	CMP AX, 0
	JE L13
	MOV AX, [BP-4]
	CALL print_output
	JMP L14
	L13:

	PUSH [BP-2]
	PUSH 5
	POP BX
	POP AX
	CMP AX, BX
	JL L15
	PUSH 0
	JMP L16
	L15:
	PUSH 1
	L16:

	POP AX
	CMP AX, 0
	JE L17
	MOV AX, [BP-2]
	CALL print_output
	JMP L18
	L17:

	PUSH 0
	POP AX
	MOV [BP-6], AX
	PUSH AX
	POP AX
	MOV AX, [BP-6]
	CALL print_output
	L18:

	L14:

	L10:

	PUSH 0
MOV AX, 0
JMP L36
L36:
ADD SP,6
POP BP
MOV AX,4CH
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