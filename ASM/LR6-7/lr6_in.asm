public input
DataSeg SEGMENT PUBLIC
	INPUT_SUCCEED	DB	13,10,'<entered>',13,10,'$'
	INPUT_ENTER		DB	'ENTER NUMBER: ', '$'
DataSeg ENDS

CSEG SEGMENT PARA PUBLIC 'CODE'
ASSUME CS:CSEG
	input proc near
			PUSH 	DS
			PUSH	SI		
			
			MOV		AX,DataSeg 
			MOV		DS, AX
			MOV		AX,0
			MOV		BX,0
			
			MOV		AH,9
			MOV		DX, OFFSET INPUT_ENTER		
			INT		21h
			MOV		DX,0   		

		INPUT_LOOP:
				MOV		AH,1
				INT		21h					

				CMP		AL,13					
				JE		INPUT_SUCCESS   

				CMP		AL,2Dh 			
				JNE		INPUT_NOT_MINUS 
				MOV		SI,1					
				JMP		INPUT_LOOP  		

		INPUT_NOT_MINUS:
				PUSH	AX						
				MOV		AX,BX       
				MOV		BX,10				
				MUL		BX					
				POP		BX					
				SUB		BL,'0'				
				MOV		BH,0				
				ADD		BX,AX					
				JMP		INPUT_LOOP

		INPUT_SUCCESS:
				MOV	AX,BX					
				CMP	SI,1					
				JNE	INPUT_END				
				NEG	AX							

		INPUT_END:
				PUSH		AX						
				MOV		DX,OFFSET INPUT_SUCCEED
				MOV		AH,9
				INT		21h
				POP		AX						
				POP		SI
				POP 		DS
				RET
	input endp
	
CSEG ENDS
END