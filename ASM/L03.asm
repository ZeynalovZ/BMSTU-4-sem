SSTACK SEGMENT PARA STACK 'STACK'
DB 64 DUP('����____')
SSTACK ENDS
DSEG SEGMENT PARA PUBLIC 'DATA'
X DB 0,1,2,3,4,5,6,7
B DB 1B
K DB ?
DSEG ENDS
SUBTTL �������� ���������
PAGE
CSEG SEGMENT PARA PUBLIC 'CODE'
ASSUME CS:CSEG,DS:DSEG,SS:SSTACK
START PROC FAR
MOV AX,DSEG		;�������� ������ � ������� ���������� ���������� Ax
MOV DS,AX		;��������� ������� DS
M1: MOV K,2     ;����������������� ���������� K
MOV SI,0		;����������������� ������� �����
MOV CX,8		;��������� � ������� CX ����� 8
MOV AL,B		;�������� � ������� AL ����� 1 Byte
M2: TEST X[SI],AL	;�������� ����� �� ������� ������ 1
JNZ M3			; ���� ������� �� != 0 �� ���������� ����� �3 ����� ����
DEC K			; ��������� �������� �
JZ M4			; ���� ������� �� == 0, �������� ���������� ����� �4
M3: INC SI		; ��������� �������
LOOP M2			;
M4: ADD SI,'0'	;
MOV AH,2		;
MOV DX,SI		;
M5: INT 21H		;
M6: MOV AH,4CH	;
MOV AL,0		;
INT 21H			;
START ENDP		;
CSEG ENDS		;
END START		;