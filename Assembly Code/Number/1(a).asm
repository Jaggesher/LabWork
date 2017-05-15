;Lab: 1(a)
;Name: Jaggesher Mondal
;Roll: 14025423


.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 0AH,"Please Input a Digit From 0 To 3=$"
MSG2 DB 0AH,0DH,0AH,"The Sum IS:=$"
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
    XOR BX,BX
    MOV BX,'0'
    MOV CX,AX
    CMP CX,0
    JE OUTPUT 
TOP:
    ADD BX,CX
    LOOP TOP
    
OUTPUT:    
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