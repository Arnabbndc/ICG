.MODEL SMALL
.STACK 1000H
.DATA
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
.CODE
	 ;func_definition f starts			 ;Line# 1
	f PROC		 ;Line# 1
	PUSH BP		 ;Line# 1
	MOV BP, SP
		 ;Line# 1
	 ;var_declaration starts			 ;Line# 2
	SUB SP, 2
	 ;var_declaration ends			 ;Line# 2
	PUSH 5		 ;Line# 3
	POP AX		 ;Line# 3
	MOV W. [BP-2], AX		 ;Line# 3
	PUSH AX		 ;Line# 3
	POP AX		 ;Line# 3
	; while loop starts
	L0:		 ;Line# 4
	PUSH W. [BP-2]		 ;Line# 4
	PUSH 0		 ;Line# 4
	POP BX		 ;Line# 4
	POP AX		 ;Line# 4
	CMP AX, BX		 ;Line# 4
	JG L2		 ;Line# 4
	PUSH 0
	JMP L3		 ;Line# 4
	L2:
	PUSH 1		 ;Line# 4
	L3:
		 ;Line# 4
	POP AX		 ;Line# 4
	CMP AX,0		 ;Line# 4
	JE L1		 ;Line# 4
	PUSH W. [BP+6]		 ;Line# 5
	INC W. [BP+6]		 ;Line# 5
	POP AX		 ;Line# 5
	PUSH W. [BP-2]		 ;Line# 6
	DEC W. [BP-2]		 ;Line# 6
	POP AX		 ;Line# 6
	JMP L0		 ;Line# 7
	L1:
		 ;Line# 7
	 ;while statement ends			 ;Line# 7
	; return statement 
	PUSH 3		 ;Line# 8
	PUSH W. [BP+6]		 ;Line# 8
	POP BX		 ;Line# 8
	POP AX		 ;Line# 8
	XOR DX, DX		 ;Line# 8
	IMUL BX		 ;Line# 8
	PUSH AX		 ;Line# 8
	PUSH 7		 ;Line# 8
	POP BX		 ;Line# 8
	POP AX		 ;Line# 8
	SUB AX, BX		 ;Line# 8
	PUSH AX		 ;Line# 8
	POP AX		 ;Line# 8
	MOV [BP+4], AX		 ;Line# 8
	ADD SP, 2		 ;Line# 8
	POP BP		 ;Line# 8
	RET		 ;Line# 8
	 ;return statement ends			 ;Line# 8
	PUSH 9		 ;Line# 9
	POP AX		 ;Line# 9
	MOV W. [BP+6], AX		 ;Line# 9
	PUSH AX		 ;Line# 9
	POP AX		 ;Line# 9
	POP BP		 ;Line# 10
	RET		 ;Line# 10
	f ENDP
		 ;Line# 10
	 ;func_definition f ends			 ;Line# 10
	 ;func_definition g starts			 ;Line# 12
	g PROC		 ;Line# 12
	PUSH BP		 ;Line# 12
	MOV BP, SP
		 ;Line# 12
	 ;var_declaration starts			 ;Line# 14
	SUB SP, 2
	SUB SP, 2
	 ;var_declaration ends			 ;Line# 14
	PUSH W. [BP+8]		 ;Line# 15
	PUSH 0		 ;Line# 15
	CALL f		 ;Line# 15
	POP AX		 ;Line# 15
	ADD SP,2		 ;Line# 15
	PUSH AX		 ;Line# 15
	PUSH W. [BP+8]		 ;Line# 15
	POP BX		 ;Line# 15
	POP AX		 ;Line# 15
	ADD AX, BX		 ;Line# 15
	PUSH AX		 ;Line# 15
	PUSH W. [BP+6]		 ;Line# 15
	POP BX		 ;Line# 15
	POP AX		 ;Line# 15
	ADD AX, BX		 ;Line# 15
	PUSH AX		 ;Line# 15
	POP AX		 ;Line# 15
	MOV W. [BP-2], AX		 ;Line# 15
	PUSH AX		 ;Line# 15
	POP AX		 ;Line# 15
	; for loop starts
	PUSH 0		 ;Line# 17
	POP AX		 ;Line# 17
	MOV W. [BP-4], AX		 ;Line# 17
	PUSH AX		 ;Line# 17
	POP AX		 ;Line# 17
	L4:		 ;Line# 17
	PUSH W. [BP-4]		 ;Line# 17
	PUSH 7		 ;Line# 17
	POP BX		 ;Line# 17
	POP AX		 ;Line# 17
	CMP AX, BX		 ;Line# 17
	JL L8		 ;Line# 17
	PUSH 0
	JMP L9		 ;Line# 17
	L8:
	PUSH 1		 ;Line# 17
	L9:
		 ;Line# 17
	POP AX		 ;Line# 17
	CMP AX, 0		 ;Line# 17
	JE L7		 ;Line# 17
	JMP L5		 ;Line# 17
	L6:		 ;Line# 17
	PUSH W. [BP-4]		 ;Line# 17
	INC W. [BP-4]		 ;Line# 17
	POP AX		 ;Line# 17
	JMP L4		 ;Line# 17
	L5:		 ;Line# 17
	; if statement starts
	PUSH W. [BP-4]		 ;Line# 18
	PUSH 3		 ;Line# 18
	POP BX		 ;Line# 18
	POP AX		 ;Line# 18
	XOR DX, DX		 ;Line# 18
	IDIV BX		 ;Line# 18
	PUSH DX		 ;Line# 18
	PUSH 0		 ;Line# 18
	POP BX		 ;Line# 18
	POP AX		 ;Line# 18
	CMP AX, BX		 ;Line# 18
	JE L10		 ;Line# 18
	PUSH 0
	JMP L11		 ;Line# 18
	L10:
	PUSH 1		 ;Line# 18
	L11:
		 ;Line# 18
	POP AX		 ;Line# 18
	CMP AX, 0		 ;Line# 18
	JE L12		 ;Line# 18
	PUSH W. [BP-2]		 ;Line# 19
	PUSH 5		 ;Line# 19
	POP BX		 ;Line# 19
	POP AX		 ;Line# 19
	ADD AX, BX		 ;Line# 19
	PUSH AX		 ;Line# 19
	POP AX		 ;Line# 19
	MOV W. [BP-2], AX		 ;Line# 19
	PUSH AX		 ;Line# 19
	POP AX		 ;Line# 19
	; if ends --- else statement starts
	JMP L13		 ;Line# 21
	L12:
		 ;Line# 21
	PUSH W. [BP-2]		 ;Line# 22
	PUSH 1		 ;Line# 22
	POP BX		 ;Line# 22
	POP AX		 ;Line# 22
	SUB AX, BX		 ;Line# 22
	PUSH AX		 ;Line# 22
	POP AX		 ;Line# 22
	MOV W. [BP-2], AX		 ;Line# 22
	PUSH AX		 ;Line# 22
	POP AX		 ;Line# 22
	L13:
		 ;Line# 23
	 ;else statement ends			 ;Line# 23
	JMP L6		 ;Line# 24
	L7:		 ;Line# 24
	; for ends			 ;Line# 24
	; return statement 
	PUSH W. [BP-2]		 ;Line# 26
	POP AX		 ;Line# 26
	MOV [BP+4], AX		 ;Line# 26
	ADD SP, 4		 ;Line# 26
	POP BP		 ;Line# 26
	RET		 ;Line# 26
	 ;return statement ends			 ;Line# 26
	POP BP		 ;Line# 27
	RET		 ;Line# 27
	g ENDP
		 ;Line# 27
	 ;func_definition g ends			 ;Line# 27
	 ;func_definition main starts			 ;Line# 29
	main PROC		 ;Line# 29
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP		 ;Line# 29
	MOV BP, SP
		 ;Line# 29
	 ;var_declaration starts			 ;Line# 30
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	 ;var_declaration ends			 ;Line# 30
	PUSH 1		 ;Line# 31
	POP AX		 ;Line# 31
	MOV W. [BP-2], AX		 ;Line# 31
	PUSH AX		 ;Line# 31
	POP AX		 ;Line# 31
	PUSH 2		 ;Line# 32
	POP AX		 ;Line# 32
	MOV W. [BP-4], AX		 ;Line# 32
	PUSH AX		 ;Line# 32
	POP AX		 ;Line# 32
	PUSH W. [BP-2]		 ;Line# 33
	PUSH W. [BP-4]		 ;Line# 33
	PUSH 0		 ;Line# 33
	CALL g		 ;Line# 33
	POP AX		 ;Line# 33
	ADD SP,4		 ;Line# 33
	PUSH AX		 ;Line# 33
	POP AX		 ;Line# 33
	MOV W. [BP-2], AX		 ;Line# 33
	PUSH AX		 ;Line# 33
	POP AX		 ;Line# 33
	; println statement 
	MOV AX, W. [BP-2]		 ;Line# 34
	CALL print_output		 ;Line# 34
	 ;println statement ends			 ;Line# 34
	; for loop starts
	PUSH 0		 ;Line# 35
	POP AX		 ;Line# 35
	MOV W. [BP-6], AX		 ;Line# 35
	PUSH AX		 ;Line# 35
	POP AX		 ;Line# 35
	L15:		 ;Line# 35
	PUSH W. [BP-6]		 ;Line# 35
	PUSH 4		 ;Line# 35
	POP BX		 ;Line# 35
	POP AX		 ;Line# 35
	CMP AX, BX		 ;Line# 35
	JL L19		 ;Line# 35
	PUSH 0
	JMP L20		 ;Line# 35
	L19:
	PUSH 1		 ;Line# 35
	L20:
		 ;Line# 35
	POP AX		 ;Line# 35
	CMP AX, 0		 ;Line# 35
	JE L18		 ;Line# 35
	JMP L16		 ;Line# 35
	L17:		 ;Line# 35
	PUSH W. [BP-6]		 ;Line# 35
	INC W. [BP-6]		 ;Line# 35
	POP AX		 ;Line# 35
	JMP L15		 ;Line# 35
	L16:		 ;Line# 35
	PUSH 3		 ;Line# 36
	POP AX		 ;Line# 36
	MOV W. [BP-2], AX		 ;Line# 36
	PUSH AX		 ;Line# 36
	POP AX		 ;Line# 36
	; while loop starts
	L21:		 ;Line# 37
	PUSH W. [BP-2]		 ;Line# 37
	PUSH 0		 ;Line# 37
	POP BX		 ;Line# 37
	POP AX		 ;Line# 37
	CMP AX, BX		 ;Line# 37
	JG L23		 ;Line# 37
	PUSH 0
	JMP L24		 ;Line# 37
	L23:
	PUSH 1		 ;Line# 37
	L24:
		 ;Line# 37
	POP AX		 ;Line# 37
	CMP AX,0		 ;Line# 37
	JE L22		 ;Line# 37
	PUSH W. [BP-4]		 ;Line# 38
	INC W. [BP-4]		 ;Line# 38
	POP AX		 ;Line# 38
	PUSH W. [BP-2]		 ;Line# 39
	DEC W. [BP-2]		 ;Line# 39
	POP AX		 ;Line# 39
	JMP L21		 ;Line# 40
	L22:
		 ;Line# 40
	 ;while statement ends			 ;Line# 40
	JMP L17		 ;Line# 41
	L18:		 ;Line# 41
	; for ends			 ;Line# 41
	; println statement 
	MOV AX, W. [BP-2]		 ;Line# 42
	CALL print_output		 ;Line# 42
	 ;println statement ends			 ;Line# 42
	; println statement 
	MOV AX, W. [BP-4]		 ;Line# 43
	CALL print_output		 ;Line# 43
	 ;println statement ends			 ;Line# 43
	; println statement 
	MOV AX, W. [BP-6]		 ;Line# 44
	CALL print_output		 ;Line# 44
	 ;println statement ends			 ;Line# 44
	; return statement 
	PUSH 0		 ;Line# 45
	POP BP		 ;Line# 46

	L14:
		 ;Line# 46
	MOV AH, 4CH
	INT 21H
	main ENDP
		 ;Line# 46
	 ;func_definition main ends			 ;Line# 46
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
