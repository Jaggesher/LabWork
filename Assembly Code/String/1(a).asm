;Lab: 1(a)
;Name: Jaggesher Mondal
;Roll: 14025423


.MODEL SMALL
.STACK 100H
.DATA
STRING DB 100 DUP(?)
MSG1 DB "Please Input a String=$"
MSG2 DB "Your Input String:=$"
X DB ?

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
    
    MOV X,AL
     
    CMP X,61H
    JAE Small_Above_Equle
    
    CMP X,41H
    JAE Cap_Above_Equle
    
    JMP LAST
    
Cap_Above_Equle:
    CMP X,5AH
    JA LAST
    ADD X,32
    
    JMP LAST

Small_Above_Equle:
    CMP X,7AH
    JA LAST
    SUB X,32
    
LAST:
    MOV AL,X 
    MOV STRING[SI],AL
    INC SI
    
    JMP WHILE
    
END_WHILE:
    MOV STRING[SI],'$'
    
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