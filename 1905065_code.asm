.MODEL SMALL
.STACK 1000H
.DATA
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
.CODE
	main PROC		 ;Line# 1
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP		 ;Line# 1
	MOV BP, SP
		 ;Line# 1
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	PUSH 3		 ;Line# 5
	POP AX		 ;Line# 5
	MOV W. [BP-2], AX		 ;Line# 5
	PUSH AX		 ;Line# 5
	POP AX		 ;Line# 5
	PUSH 8		 ;Line# 6
	POP AX		 ;Line# 6
	MOV W. [BP-4], AX		 ;Line# 6
	PUSH AX		 ;Line# 6
	POP AX		 ;Line# 6
	PUSH 6		 ;Line# 7
	POP AX		 ;Line# 7
	MOV W. [BP-6], AX		 ;Line# 7
	PUSH AX		 ;Line# 7
	POP AX		 ;Line# 7
	PUSH W. [BP-2]		 ;Line# 10
	PUSH 3		 ;Line# 10
	POP BX		 ;Line# 10
	POP AX		 ;Line# 10
	CMP AX, BX		 ;Line# 10
	JE L1		 ;Line# 10
	PUSH 0
	JMP L2		 ;Line# 10
	L1:
	PUSH 1		 ;Line# 10
	L2:
		 ;Line# 10
	POP AX		 ;Line# 10
	CMP AX, 0		 ;Line# 10
	JE L3		 ;Line# 10
	MOV AX, W. [BP-4]		 ;Line# 11
	CALL print_output		 ;Line# 11
	L3:
		 ;Line# 14
	PUSH W. [BP-4]		 ;Line# 14
	PUSH 8		 ;Line# 14
	POP BX		 ;Line# 14
	POP AX		 ;Line# 14
	CMP AX, BX		 ;Line# 14
	JL L4		 ;Line# 14
	PUSH 0
	JMP L5		 ;Line# 14
	L4:
	PUSH 1		 ;Line# 14
	L5:
		 ;Line# 14
	POP AX		 ;Line# 14
	CMP AX, 0		 ;Line# 14
	JE L6		 ;Line# 14
	MOV AX, W. [BP-2]		 ;Line# 15
	CALL print_output		 ;Line# 15
	JMP L7		 ;Line# 17
	L6:
		 ;Line# 17
	MOV AX, W. [BP-6]		 ;Line# 18
	CALL print_output		 ;Line# 18
	L7:
		 ;Line# 19
	PUSH W. [BP-6]		 ;Line# 21
	PUSH 6		 ;Line# 21
	POP BX		 ;Line# 21
	POP AX		 ;Line# 21
	CMP AX, BX		 ;Line# 21
	JNE L8		 ;Line# 21
	PUSH 0
	JMP L9		 ;Line# 21
	L8:
	PUSH 1		 ;Line# 21
	L9:
		 ;Line# 21
	POP AX		 ;Line# 21
	CMP AX, 0		 ;Line# 21
	JE L10		 ;Line# 21
	MOV AX, W. [BP-6]		 ;Line# 22
	CALL print_output		 ;Line# 22
	JMP L11		 ;Line# 24
	L10:
		 ;Line# 24
	PUSH W. [BP-4]		 ;Line# 24
	PUSH 8		 ;Line# 24
	POP BX		 ;Line# 24
	POP AX		 ;Line# 24
	CMP AX, BX		 ;Line# 24
	JG L12		 ;Line# 24
	PUSH 0
	JMP L13		 ;Line# 24
	L12:
	PUSH 1		 ;Line# 24
	L13:
		 ;Line# 24
	POP AX		 ;Line# 24
	CMP AX, 0		 ;Line# 24
	JE L14		 ;Line# 24
	MOV AX, W. [BP-4]		 ;Line# 25
	CALL print_output		 ;Line# 25
	JMP L15		 ;Line# 27
	L14:
		 ;Line# 27
	PUSH W. [BP-2]		 ;Line# 27
	PUSH 5		 ;Line# 27
	POP BX		 ;Line# 27
	POP AX		 ;Line# 27
	CMP AX, BX		 ;Line# 27
	JL L16		 ;Line# 27
	PUSH 0
	JMP L17		 ;Line# 27
	L16:
	PUSH 1		 ;Line# 27
	L17:
		 ;Line# 27
	POP AX		 ;Line# 27
	CMP AX, 0		 ;Line# 27
	JE L18		 ;Line# 27
	MOV AX, W. [BP-2]		 ;Line# 28
	CALL print_output		 ;Line# 28
	JMP L19		 ;Line# 30
	L18:
		 ;Line# 30
	PUSH 0		 ;Line# 31
	POP AX		 ;Line# 31
	MOV W. [BP-6], AX		 ;Line# 31
	PUSH AX		 ;Line# 31
	POP AX		 ;Line# 31
	MOV AX, W. [BP-6]		 ;Line# 32
	CALL print_output		 ;Line# 32
	L19:
		 ;Line# 33
	L15:
		 ;Line# 33
	L11:
		 ;Line# 33
	PUSH 0		 ;Line# 36
	POP BP		 ;Line# 37

	L0:
		 ;Line# 37
	MOV AH, 4CH
	INT 21H
	main ENDP
		 ;Line# 37
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
