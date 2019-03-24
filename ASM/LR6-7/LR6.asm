PUBLIC X
extrn input:near, print_bu:near, print_bs:near, print_du:near, print_ds:near, print_hu:near, print_hs:near
SSTACK SEGMENT PARA STACK  'STACK'
		DB   64 DUP(0)
SSTACK     ENDS

DSEG SEGMENT  PARA PUBLIC 'DATA'
					db 10,13
		zero_p  	db '0. Print menu'
					db 10,13
		one_p   	db '1. Enter a number'
					db 10,13
		two_p   	db '2. Print binary unsigned'
					db 10,13
		three_p 	db '3. Print binary signed'
					db 10,13
		four_p  	db '4. Print decimal unsigned'
					db 10,13
		five_p  	db '5. Print decimal signed'
					db 10,13
		six_p   	db '6. Print hexadecimal unsigned'
					db 10,13
		seven_p 	db '7. Print hexadecimal signed'
					db 10,13
		eight_p 	db '8. Exit'
					db 10,13,'$'
					
		ADDR		dw print_bu, print_bs, print_du, print_ds, print_hu, print_hs
		X			dw 10
DSEG          ENDS

PAGE
    CSEG SEGMENT PARA PUBLIC 'CODE'
        ASSUME CS:CSEG,DS:DSEG,SS:SSTACK
               
		call_input:
			call input
			MOV X, AX
			jmp MENU

		read:     
			mov ah, 7
			int 21h
			cmp al,'0'
			je menu
			cmp al, '8'
			je exit
			CMP AL, '1'
			JE call_input
			dec al
			dec al
			mov ah, 0
			sub ax, '0'
			mov dl, 2
			mul dl
			MOV BX, AX
			call ADDR[BX]
   
		menu:     
			mov ah, 9
			mov dx, 0
			int 21h
			jmp read
	 
		START:    
				MOV  AX,DSEG				
               	MOV  DS,AX
               	jmp menu

		exit:     
				mov ah, 4ch
				int 21h
    CSEG ENDS     
		END  START