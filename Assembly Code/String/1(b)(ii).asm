;1(b)(ii)
;Name: Jaggesher Mondal
;Roll: 14025423

.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "Please Input a String=$"
MSG2 DB "Output String:=$"

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9;String Out
    LEA DX,MSG1
    INT 21H
    
    MOV AH,1
    
    PUSH 0024H; Assigning $ sing
    
WHILE:;This Loop For Input
    INT 21H
    CMP AL,0DH
    JE END_WHILE
    MOV AH,0
    PUSH AX
    MOV AH,1
    JMP WHILE
END_WHILE:
    ;New Line
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    MOV AH,9
    LEA DX,MSG2
    INT 21H
    
    MOV AH,2
WHILE2: ;This Loop For Print
    POP DX
    CMP DX,'$'
    JE END_WHILE2
    INT 21H
    JMP WHILE2 
END_WHILE2:    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN