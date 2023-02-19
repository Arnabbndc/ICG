.MODEL SMALL
.STACK 1000H
.DATA
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
	i DW 1 DUP (0000H)
	j DW 1 DUP (0000H)
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
	SUB SP, 2
	SUB SP, 2
	PUSH 1
	POP AX
	MOV i, AX
	PUSH AX
	POP AX
	MOV AX, i
	CALL print_output
	PUSH 5
	PUSH 8
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV j, AX
	PUSH AX
	POP AX
	MOV AX, j
	CALL print_output
	PUSH i
	PUSH 2
	PUSH j
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
	MOV [BP-2], AX
	PUSH AX
	POP AX
	MOV AX, [BP-2]
	CALL print_output
	PUSH [BP-2]
	PUSH 9
	POP BX
	POP AX
	XOR DX, DX
	IDIV BX
	PUSH DX
	POP AX
	MOV [BP-6], AX
	PUSH AX
	POP AX
	MOV AX, [BP-6]
	CALL print_output
	PUSH [BP-6]
	PUSH [BP-4]
	POP BX
	POP AX
	CMP AX, BX
	JLE L0
	PUSH 0
	JMP L1
	L0:
	PUSH 1
	L1:

	POP AX
	MOV [BP-8], AX
	PUSH AX
	POP AX
	MOV AX, [BP-8]
	CALL print_output
	PUSH i
	PUSH j
	POP BX
	POP AX
	CMP AX, BX
	JNE L2
	PUSH 0
	JMP L3
	L2:
	PUSH 1
	L3:

	POP AX
	MOV [BP-10], AX
	PUSH AX
	POP AX
	MOV AX, [BP-10]
	CALL print_output
	PUSH [BP-8]
	POP AX
	CMP AX, 0
	JNE L4
	PUSH [BP-10]
	POP AX
	CMP AX, 0
	JNE L4
	PUSH 0
	JMP L5
	L4:
	PUSH 1
	L5:

	POP AX
	MOV [BP-12], AX
	PUSH AX
	POP AX
	MOV AX, [BP-12]
	CALL print_output
	PUSH [BP-8]
	POP AX
	CMP AX, 1
	JNE L6
	PUSH [BP-10]
	POP AX
	CMP AX, 1
	JNE L6
	PUSH 1
	JMP L7
	L6:
	PUSH 0
	L7:

	POP AX
	MOV [BP-12], AX
	PUSH AX
	POP AX
	MOV AX, [BP-12]
	CALL print_output
	PUSH [BP-12]
	INC [BP-12]
	POP AX
	MOV AX, [BP-12]
	CALL print_output
	PUSH [BP-12]
	POP AX
	NEG AX
	PUSH AX

	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
	MOV AX, [BP-2]
	CALL print_output
	PUSH 0
MOV AX, 0
JMP L36
L36:
ADD SP,12
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
