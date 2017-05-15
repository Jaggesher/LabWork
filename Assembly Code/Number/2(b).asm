;Lab: 2(b)
;Name: Jaggesher Mondal
;Roll: 14025423


.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 0AH,"Please Input a Digit From 0 To 9=$"
MSG2 DB 0AH,0DH,0AH,"The Input Digit Is PRIME!$"
MSG3 DB 0AH,0DH,0AH,"The Input Digit Isn't PRIME!$"

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
    XOR BX,BX
    MOV BL,AL
    LEA DX,MSG3
    
    CMP AL,2    
    JL OUTPUT
    JE END_WHILE
    
    MOV CL,2
WHILE:
    CMP CL,BL
    JGE END_WHILE
    
    MOV AX,BX
    DIV CL
    CMP AH,0
    JE OUTPUT
    
    INC CL
    JMP WHILE
END_WHILE:   
    LEA DX,MSG2
       
OUTPUT:
    MOV AH,9
    INT 21H 
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN