;Lab: 2(a)
;Name: Jaggesher Mondal
;Roll: 14025423


.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 0AH,"Please Input a Digit From 0 To 9=$"
MSG2 DB 0AH,0DH,0AH,"The Input Digit Is ODD!$"
MSG3 DB 0AH,0DH,0AH,"The Input Digit Is EVEN!$"
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
    
    LEA DX,MSG3
    TEST AL,1
    JZ OUTPUT
    LEA DX,MSG2
    
OUTPUT:
    MOV AH,9
    INT 21H 
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN