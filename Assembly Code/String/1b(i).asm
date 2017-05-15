;1(b)(i)
;Name: Jaggesher Mondal
;Roll: 14025423

.MODEL SMALL
.STACK 100H
.DATA
STRING DB 100 DUP(?)
MSG1 DB "Please Input a String=$"
MSG2 DB "Output String:=$"

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9;String Out
    LEA DX,MSG1
    INT 21H
    
    MOV SI,0
    MOV AH,1
WHILE:
    
    INT 21H 
    CMP AL,0DH
    JE END_WHILE
    MOV STRING[SI],AL
    INC SI
    JMP WHILE
    
END_WHILE:    
    MOV STRING[SI],'$'
MOV DI,SI
MOV SI,0
DEC DI
 
WHILE2:
    CMP SI,DI
    JNBE END_WHILE2
    MOV AH,STRING[SI]
    MOV AL,STRING[DI]
    
    MOV STRING[SI],AL
    MOV STRING[DI],AH
    INC SI
    DEC DI
    JMP WHILE2
    
END_WHILE2:    
    
    ;New Line
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    MOV AH,9
    LEA DX,MSG2
    INT 21H
       
    
    MOV AH,9
    LEA DX,STRING
    INT 21H 
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN