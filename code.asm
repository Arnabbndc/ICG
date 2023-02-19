.MODEL SMALL
.STACK 100h
.DATA

	a DW 0   			; variable a declared
	b DW 10 DUP(0)		; array b declared
	c DW 0   			; variable c declared

.CODE
	main PROC
		MOV AX, @DATA
		mov DS, AX
		; data segment loaded

		MOV BP, SP
	
		SUB SP, 2	;line 3: i declared: W. [BP-2]
		SUB SP, 20	;line 3: array j of size 10 declared
		; from [BP-4] to [BP-22]
		SUB SP, 2	;line 3: k declared: W. [BP-24]
	
		PUSH 1	;line 4: save 1

; line 4: a=1
		POP AX	;line 4: load 1
		MOV a, AX	;line 4: a=1
		PUSH AX	;line 4: save a

		POP AX	;line 4: evaluated exp: a=1;

		PUSH 3	;line 5: save 3

; line 5: i=3
		POP AX	;line 5: load 3
		MOV W. [BP-2], AX	;line 5: i=3
		PUSH AX	;line 5: save i

		POP AX	;line 5: evaluated exp: i=3;

		PUSH 2	;line 6: save 2

; line 6: b[2]
		POP AX	;line 6: pop index 2 of array b
		SHL AX, 1	;line 6: multiply by 2 to get offset
		LEA BX, b	;line 6: get array base address
		SUB BX, AX	;line 6: [BX]->b[2]
		PUSH BX
	
		PUSH 5	;line 6: save 5

; line 6: b[2]=5
		POP AX	;line 6: load 5
		POP BX	
		MOV [BX], AX	;line 6: b[2]=5
		PUSH AX	;line 6: save b[2]

		POP AX	;line 6: evaluated exp: b[2]=5;

		PUSH 4	;line 7: save 4

; line 7: j[4]
		POP AX	;line 7: pop index 4 of array j
		SHL AX, 1	;line 7: multiply by 2 to get offset
		LEA BX, W. [BP-4]	;line 7: get array base address
		SUB BX, AX	;line 7: [BX]->j[4]
		PUSH BX
	
		PUSH 10	;line 7: save 10

; line 7: j[4]=10
		POP AX	;line 7: load 10
		POP BX	
		MOV [BX], AX	;line 7: j[4]=10
		PUSH AX	;line 7: save j[4]

		POP AX	;line 7: evaluated exp: j[4]=10;


		@L_0:
		MOV AH, 4CH
		INT 21H
	main ENDP


	PRINT_NEWLINE PROC
        ; PRINTS A NEW LINE WITH CARRIAGE RETURN
        PUSH AX
        PUSH DX
        MOV AH, 2
        MOV DL, 0Dh
        INT 21h
        MOV DL, 0Ah
        INT 21h
        POP DX
        POP AX
        RET
    PRINT_NEWLINE ENDP

PRINT_NUM_FROM_BX PROC
    PUSH CX  
    ; push to stack to 
    ; check the end of the number  
    MOV AX, 'X'
    PUSH AX
    
    CMP BX, 0  
    JE ZERO_NUM
    JNL NON_NEGATIVE 
    
    NEG BX
    ; print - for negative number
    MOV DL, '-'
    MOV AH, 2
    INT 21H
    JMP NON_NEGATIVE  
    
    ZERO_NUM:
        MOV DX, 0
        PUSH DX
        JMP POP_PRINT_LOOP
    
    NON_NEGATIVE:
    
    MOV CX, 10 
    
    MOV AX, BX
    PRINT_LOOP:
        ; if AX == 0
        CMP AX, 0
        JE END_PRINT_LOOP
        ; else
        MOV DX, 0 ; DX:AX = 0000:AX
        
        ; AX = AX / 10 ; store reminder in DX 
        DIV CX
    
        PUSH DX
        
        JMP PRINT_LOOP

    END_PRINT_LOOP:
    
    
    
    POP_PRINT_LOOP:
        POP DX
        ; loop ending condition
        ; if DX == 'X'
        CMP DX, 'X'
        JE END_POP_PRINT_LOOP
        
        ; if DX == '-'
        CMP DX, '-'
        JE PRINT_TO_CONSOLE
        
        ; convert to ascii
        ADD DX, 30H       
        ; print the digit
        PRINT_TO_CONSOLE:
        MOV AH, 2
        INT 21H
        
        JMP POP_PRINT_LOOP
    
    END_POP_PRINT_LOOP: 
CALL PRINT_NEWLINE
    POP CX
    RET
PRINT_NUM_FROM_BX ENDP

END MAIN
