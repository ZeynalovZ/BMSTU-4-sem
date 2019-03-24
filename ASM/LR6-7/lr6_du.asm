public print_du
EXTRN X:FAR
CSEG SEGMENT PARA PUBLIC 'CODE'
ASSUME CS:CSEG
	print_du proc near
		MOV 	AX, X
		PUSH	DS
		PUSH	SI
		PUSH	AX
		MOV 	BX, 10								


		DU_DIV1:
				MOV		DX,0
				DIV		BX								
				PUSH	AX							
				MOV		AH,2						
				MOV		DL,'a'
				INT		21h
				POP		AX							
				CMP		AX,0						
				JNE		DU_DIV1				

				MOV	AH,2
				MOV DL,8								
				INT 21h

				POP		AX								

		DU_DIV2:
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
				JNE		DU_DIV2		
		POP 	SI
		POP 	DS
		ret
	print_du endp
	
CSEG ENDS
END