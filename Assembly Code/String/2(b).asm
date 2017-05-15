;2(b)
;Name: Jaggesher Mondal
;Roll: 14025423

.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "Please Input a String=$"
MSG2 DB 0DH,0AH,"The Longest Sub Sequence IS:=$"

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9;String Out
    LEA DX,MSG1
    INT 21H
    
    MOV AH,1
    INT 21H
    CMP AL,0DH
    JE EXIT
    
    MOV DL,AL
    MOV CL,1
    MOV CH,1
    MOV DH,AL
    
    POS1:
        INT 21H
        MOV Bl,AL
        
        SUB AL,CH
        CMP DH,AL
        JNE POS2
        INC CH
        CMP CL,CH 
        
        JG POS3
        MOV CL,CH
        MOV DL,DH
        JMP POS3
        
        POS2:
            MOV DH,BL
            MOV CH,1 
            
            
        POS3:      
        CMP BL,0DH
        JE OUTPUT  
        JMP POS1
           
    OUTPUT:
    
        MOV BL,DL
        MOV AH,9
        LEA DX,MSG2
        INT 21H
        MOV AH,2
        MOV DL,BL
        
        
        POS4:
            INT 21H
            INC DL
            DEC CL
            CMP CL,0
            JNE POS4 
            
            
    EXIT:        
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN