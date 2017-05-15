;Lab: 2(c)
;Name: Jaggesher Mondal
;Roll: 14025423

.MODEL SMALL
.STACK 100H
.DATA
String DB 100 DUP(?)
SubString DB 100 DUP(?)
MSG1 DB "ENter A String: $"
MSG2 DB 0DH,0AH,"Enter Sub String: $"
MSG3 DB 0DH,0AH,"Sub String Found :)$"
MSG4 DB 0DH,0AH,"Sub String Isn't Found :($"
Flag DB "N"
Length DW ?

.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9;String Out
    LEA DX,MSG1
    INT 21H
    
    MOV AH,1
    MOV SI,0
    WHILE1:;FIrst Input
        INT 21H
        CMP AL,0DH
        JE END_WHILE1
        MOV String[SI],AL
        INC SI
        JMP WHILE1
    END_WHILE1:
    MOV Length,SI
    
    MOV AH,9;String Out
    LEA DX,MSG2
    INT 21H
    
    MOV AH,1
    MOV SI,0
    WHILE2:;Second Input
        INT 21H
        CMP AL,0DH
        JE END_WHILE2
        MOV SubString[SI],AL
        INC SI
        JMP WHILE2
    END_WHILE2:
    
    SUB Length,SI
    DEC SI
    MOV BX,SI
    MOV DX,0
    
    WHILE3:  ;Here we Check For Sub String. 
        CMP DX,Length
        JG OUTPUT
        MOV SI,DX
        MOV DI,0 
        
        INN_WHILE1:
            CMP DI,BX
            JG END_INN_WHILE1
             
            MOV AL, String[SI]
            CMP AL,SubString[DI]
            JNE POS1 
            
            INC SI
            INC DI
            JMP INN_WHILE1
            
        END_INN_WHILE1:
        MOV Flag,'Y'
        JMP OUTPUT
            
        POS1:
        INC DX
        JMP WHILE3
                   
    END_WHILE3:
    
    
    
    OUTPUT:
        MOV AH,9
        
        LEA DX,MSG3
        CMP Flag,'Y'
        JE POS2
        LEA DX,MSG4
        POS2:
        INT 21H
         
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN