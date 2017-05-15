;2(a)
;Name: Jaggesher Mondal
;Roll: 14025423

.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "Please Input a String=$"
MSG2 DB 0DH,0AH,"THE FIRST CAPITAL: $"
MSG3 DB 0DH,0AH,"THE LAST CAPITAL: $"
MSG4 DB 0DH,0AH,"NO CAPITALS$"

FC DB 'Z'
LC DB 'A'
FLAG DB 'N'

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9;String Out
    LEA DX,MSG1
    INT 21H
    
    MOV AH,1
    WHILE1:
        INT 21H
        CMP AL,0DH
        JE OUTPUT
        
        CMP AL,'A'
        JL POS1
        CMP AL,'Z'
        JG POS1
        
        MOV FLAG,'Y'
        
        CMP FC,AL
        JL POS0
        MOV FC,AL
        
        POS0:
        CMP LC,AL
        JG POS1
        MOV LC,AL
        
        POS1:
        JMP WHILE1     
    END_WHILE1:
    
    OUTPUT:
    
    CMP FLAG,'Y'
    JE POS2
    
    MOV AH,9
    LEA DX,MSG4
    INT 21H
    JMP LASTk 
    
    POS2:
        MOV AH,9
        LEA DX,MSG2
        INT 21H
        
        MOV AH,2
        MOV DL,FC
        INT 21H
        
        MOV AH,9
        LEA DX,MSG3
        INT 21H
        
        MOV AH,2
        MOV DL,LC
        INT 21H
        
    LAST:    
                
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN