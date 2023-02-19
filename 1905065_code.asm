.MODEL SMALL
.STACK 1000H
.DATA
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
	a DW 1 DUP (0000H)
	b DW 10 DUP (0000H)
	c DW 1 DUP (0000H)
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 20
	SUB SP, 2
	PUSH 1
	PUSH 5
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	PUSH 7
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV a, AX
	PUSH AX
	POP AX
	PUSH a
	PUSH 2
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
	PUSH 4
	POP AX
	SHL AX, 1
	LEA SI, [BP-4]
	SUB SI, AX
	PUSH SI

	PUSH 10
	POP AX
	POP SI
	MOV [SI], AX
	PUSH AX
	POP AX
	MOV AX, a
	CALL print_output
	MOV AX, [BP-2]
	CALL print_output
MOV AX, 0
JMP L36
L36:
ADD SP, 24
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