public print_ds
EXTRN X:FAR
CSEG SEGMENT PARA PUBLIC 'CODE'
ASSUME CS:CSEG
	print_ds proc near
		PUSH	DS

		MOV 	AX, X

		CMP		AX,0
		JGE		DS_AFTER_MINUS
		PUSH		AX
		MOV		AH,2h
		MOV		DL,'-'
		INT		21h
		POP		AX
		NEG		AX

		DS_AFTER_MINUS:
				PUSH	AX
				MOV 	BX, 10	


		DS_DIV1:
				MOV		DX,0
				DIV		BX								
				PUSH	AX								
				MOV		AH,2							
				MOV		DL,'a'
				INT		21h
				POP		AX								
				CMP		AX,0							
				JNE		DS_DIV1					

				MOV	AH,2
				MOV DL,8								
				INT 21h

				POP		AX								

		DS_DIV2:
				MOV		DX,0
				DIV		BX								
				PUSH		AX								
				MOV		AH,2
				ADD		DL,'0'						
				INT		21h
				MOV		DL,8							
				INT		21h
				INT		21h
				POP		AX								
				CMP		AX,0							
				JNE		DS_DIV2
		POP 	DS

		ret
	print_ds endp
	
CSEG ENDS
END