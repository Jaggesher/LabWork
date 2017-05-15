;Lab: 3(b)
;Name: Jaggesher Mondal
;Roll: 14025423

.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 0AH,"ENTER A STRING: $"
    MSG2 DB 0DH,0AH,0AH,"AFTER SORTING THE STRING LOOKS LIKE: $" 
    MSG3 DB 0DH,0AH,0AH,"IN ASSENDING: $"
    MSG4 DB 0DH,0AH,0AH,"IN DECENDING: $" 
    
    STRING1 DB 100 DUP(?)
    STRING2 DB 100 DUP(?)
     
.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9;String Out
    LEA DX,MSG1
    INT 21H
    
    MOV AH,1
    MOV SI,0
    WHILE1: 
        INT 21H
        CMP AL,0DH
        JE END_WHILE1
        
        MOV STRING1[SI],AL
        MOV STRING2[SI],AL
        INC SI
        JMP WHILE1
    
    END_WHILE1:
        MOV STRING1[SI],'$'
        MOV STRING2[SI],'$'
        
        DEC SI
        MOV BX,SI
        MOV CX,SI
        
    SORT:
        MOV SI,0
        MOV DI,1
        WHILE2:
            CMP DI,BX
            JG END_WHILE2
            
            MOV AL,STRING1[SI]
            CMP AL,STRING1[DI] ;Assending Check
            JL POS1
            
            MOV DL,STRING1[DI]
            MOV STRING1[SI],DL
            MOV STRING1[DI],AL 
            
            POS1:
            
            MOV AL,STRING2[SI]
            CMP AL,STRING2[DI] ;Decending Check
            JG POS2
            
            MOV DL,STRING2[DI]
            MOV STRING2[SI],DL
            MOV STRING2[DI],AL
            
            POS2:
            
            INC SI
            INC DI
            JMP WHILE2
        END_WHILE2:
        
        LOOP SORT
    
    OUTPUT:
        MOV AH,9
        LEA DX,MSG2
        INT 21H
        
        LEA DX,MSG3
        INT 21H
        
        LEA DX,STRING1
        INT 21H
        
        LEA DX,MSG4
        INT 21H
        
        LEA DX,STRING2
        INT 21H
        
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN