StkSeg SEGMENT PARA STACK 'STACK'
	DB 200h dup(?)
StkSeg ENDS

DataS SEGMENT PARA PUBLIC 'DATA'
NUM	DB	3
MSG	DB	'Hello'
C$	DB	?
	DB	'rd$'
DataS ENDS

Code SEGMENT PARA PUBLIC 'CODE'
	ASSUME CS:Code, DS:DataS, SS: StkSeg

BEGIN PROC FAR
M1:
mov	AX,DataS
mov	DS,AX
M2:
mov	AL,NUM
mov	C$,AL
INT	21h
M3:
mov	AH,9
mov	DX,OFFSET MSG
INT	21h


MOV AH,4CH
MOV AL,0
INT 21H

BEGIN ENDP

Code ENDS
END BEGIN