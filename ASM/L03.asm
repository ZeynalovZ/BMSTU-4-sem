SSTACK SEGMENT PARA STACK 'STACK'
DB 64 DUP('СТЕК____')
SSTACK ENDS
DSEG SEGMENT PARA PUBLIC 'DATA'
X DB 0,1,2,3,4,5,6,7
B DB 1B
K DB ?
DSEG ENDS
SUBTTL ОСНОВНАЯ ПРОГРАММА
PAGE
CSEG SEGMENT PARA PUBLIC 'CODE'
ASSUME CS:CSEG,DS:DSEG,SS:SSTACK
START PROC FAR
MOV AX,DSEG		;Поместим данные в регистр свободного назначения Ax
MOV DS,AX		;Установим регистр DS
M1: MOV K,2     ;Проинициализируем переменную K
MOV SI,0		;Проинициализируем счетчик нулем
MOV CX,8		;Установим в регистр CX число 8
MOV AL,B		;Поместим в регистр AL число 1 Byte
M2: TEST X[SI],AL	;ПРоверка равен ли текущий символ 1
JNZ M3			; Если регистр СХ != 0 то управдение метке М3 иначе скип
DEC K			; Уменьшить значение К
JZ M4			; Если регистр Сх == 0, передать управление метке М4
M3: INC SI		; Увеличить счетчик
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