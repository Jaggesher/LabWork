;Lab: 1(b)
;Name: Jaggesher Mondal
;Roll: 14025423


.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 0AH,"Please Input a Digit From 0 To 3=$"
MSG2 DB 0AH,0DH,0AH,"The FACTORIAL IS:=$"
X DB ?

.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9;String Out
    LEA DX,MSG1
    INT 21H
    
    MOV AH,1
    INT 21H
    
    SUB AL,'0'
    MOV AH,0
    MOV CX,AX
    MOV BL,AL
    MOV AX,1
    
    CMP CX,0
    JE OUTPUT 
TOP:
    MUL BL
    DEC BL
    LOOP TOP
    
OUTPUT:
    MOV BX,AX
    ADD BX,'0'    
    MOV AH,9;String Out
    LEA DX,MSG2
    INT 21H
    
    MOV AH,2
    MOV DX,BX
    INT 21H
     
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN