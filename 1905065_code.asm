.MODEL SMALL
.STACK 1000H
.DATA
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	PUSH 0
	POP AX
	MOV W. [BP-2], AX
	PUSH AX
	POP AX
	L0:
	PUSH W. [BP-2]
	PUSH 6
	POP BX
	POP AX
	CMP AX, BX
	JL L4
	PUSH 0
	JMP L5
	L4:
	PUSH 1
	L5:

	POP AX
	CMP AX, 0
	JE L3
	JMP L1
	L2:
	PUSH W. [BP-2]
	INC W. [BP-2]
	POP AX
	JMP L0
	L1:
	MOV AX, W. [BP-2]
	CALL print_output
	JMP L2
	L3:
	PUSH 4
	POP AX
	MOV W. [BP-6], AX
	PUSH AX
	POP AX
	PUSH 6
	POP AX
	MOV W. [BP-8], AX
	PUSH AX
	POP AX
	L6:
	PUSH W. [BP-6]
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JG L8
	PUSH 0
	JMP L9
	L8:
	PUSH 1
	L9:

	POP AX
	CMP AX,0
	JE L7
	PUSH W. [BP-8]
	PUSH 3
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV W. [BP-8], AX
	PUSH AX
	POP AX
	PUSH W. [BP-6]
	DEC W. [BP-6]
	POP AX
	JMP L6
	L7:

	MOV AX, W. [BP-8]
	CALL print_output
	MOV AX, W. [BP-6]
	CALL print_output
	PUSH 4
	POP AX
	MOV W. [BP-6], AX
	PUSH AX
	POP AX
	PUSH 6
	POP AX
	MOV W. [BP-8], AX
	PUSH AX
	POP AX
	L10:
	PUSH W. [BP-6]
	DEC W. [BP-6]
	POP AX
	CMP AX,0
	JE L11
	PUSH W. [BP-8]
	PUSH 3
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV W. [BP-8], AX
	PUSH AX
	POP AX
	JMP L10
	L11:

	MOV AX, W. [BP-8]
	CALL print_output
	MOV AX, W. [BP-6]
	CALL print_output
	PUSH 0
MOV AX, 0
JMP L36
L36:
ADD SP,8
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
