public print_hu
EXTRN X:FAR

Data	SEGMENT	PUBLIC
	SYMBOLS	DB	'0123456789ABCDEF'
Data	ENDS

EXTRN X:FAR
CSEG SEGMENT PARA PUBLIC 'CODE'
ASSUME CS:CSEG, DS:Data
	print_hu proc near
			MOV AX, X
			PUSH DS
			MOV CX, Data
			MOV DS, CX
			MOV BX,16							
			PUSH	AX							


		HU_DIV1:
				MOV		DX,0
				DIV		BX				
				PUSH		AX						
				MOV		AH,2					
				MOV		DL,'a'
				INT		21h
				POP		AX				
				CMP		AX,0				
				JNE		HU_DIV1				

				MOV	AH,2
				MOV DL,8						
				INT 21h

				POP		AX					

		HU_DIV2:
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
				JMP		HU_ADD_0

		HU_ADD_A:
				ADD		DL,'A'
				SUB		DL,10

		HU_ADD_0:
				INT		21h							
				MOV		DL,8						
				INT		21h
				INT		21h
				POP		AX							
				CMP		AX,0						
				JNE		HU_DIV2				

			POP DS
			ret
	print_hu endp
	
CSEG ENDS
END