EXTRN X:FAR
public print_bu
CSEG SEGMENT PARA PUBLIC 'CODE'
	ASSUME CS:CSEG
    EXIT:
		MOV DL, '0'
		MOV AH, 2
		INT 21H
        POP SI
		POP DS
		ret
	print_bu proc near
			MOV 	AX, X
			PUSH	DS
			PUSH	SI
			
			
			MOV SI,	16
            
		IGNORE_ZEROS:
			DEC SI
			CMP SI, 0
			JZ EXIT
			MOV DH, 0
			SHL AX, 1
			JNC IGNORE_ZEROS
			INC DH
			JMP PRINT_BIT
			
		SHIFT:
			DEC SI
			MOV DH, 0
			SHL AX, 1
			JNC PRINT_BIT
			INC DH
			

		PRINT_BIT:
			MOV DL, '0'
			ADD DL, DH
			PUSH AX
			MOV AH, 2
			INT 21H
			POP AX
			CMP SI, 0
			JNZ SHIFT
		POP SI
		POP DS
		ret
	print_bu endp
	
CSEG ENDS
END