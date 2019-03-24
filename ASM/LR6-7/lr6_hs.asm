public print_hs
EXTRN X:FAR
Data	SEGMENT	PUBLIC
	SYMBOLS	DB	'0123456789ABCDEF'
Data	ENDS

CSEG SEGMENT PARA PUBLIC 'CODE'
ASSUME CS:CSEG, DS:Data
	print_hs proc near
			MOV AX, X
			PUSH DS
			
			CMP		AX,0
			JGE		HS_AFTER_MINUS	

			PUSH	AX

			MOV		AH,2h
			MOV		DL,'-'
			INT		21h
			POP		AX
			NEG		AX

		HS_AFTER_MINUS:
			MOV CX, Data
			MOV DS, CX
			MOV BX,16								
			PUSH	AX								


		HS_DIV1:
				MOV		DX,0
				DIV		BX							
				PUSH		AX							
				MOV		AH,2						
				MOV		DL,'a'
				INT		21h
				POP		AX							
				CMP		AX,0					
				JNE		HS_DIV1				

				MOV	AH,2
				MOV DL,8							 
				INT 21h

				POP		AX							

		HS_DIV2:
				MOV		DX,0
				DIV		BX							
				PUSH	AX						

				PUSH	BX
				MOV   BX, OFFSET SYMBOLS
				MOV		AL, DL
				XLAT
				MOV		DL, AL
				POP 	BX
				MOV		AH,2
				JMP		HS_ADD_0

		HS_ADD_A:
				ADD		DL,'A'
				SUB		DL,10

		HS_ADD_0:
				INT		21h							
				MOV		DL,8						
				INT		21h
				INT		21h
				POP		AX							
				CMP		AX,0					
				JNE		HS_DIV2

			POP DS	
		ret
	print_hs endp
CSEG ENDS
END