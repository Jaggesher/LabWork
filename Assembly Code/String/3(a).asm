;Lab: 3(a)
;Name: Jaggesher Mondal
;Roll: 14025423


.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 0AH,"ENTER A STRING: $"
    MSG2 DB 0DH,0AH,0AH,"NUMBER OF VOWELS: $" 
    MSG3 DB 0DH,0AH,0AH,"NUMBER OF CONSONENTS: $"
    MSG4 DB 0DH,0AH,0AH,"NUMBER OF DIGITS: $"
    MSG5 DB 0DH,0AH,0AH,"NUMBER OF SPACES: $" 
   
    
    VOWELS DB 30H
    CONSONENTS DB 30H
    DIGITS DB 30H
    SPACES DB 30H


.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9;String Out
    LEA DX,MSG1
    INT 21H
    
    MOV AH,1
    WHILE:
        INT 21H
        CMP AL,0DH
        JE OUTPUT 
        
        SPACES_CHK:
            CMP AL,20H
            JNE VOWELS_CHK ;The Char Is Not A SPACE, So Go For Next Check
            INC SPACES
            JMP WHILE
        
        VOWELS_CHK:
            CMP AL,'a'
            JE COUNT_VOWELS
            
            CMP AL,'e'
            JE COUNT_VOWELS
            
            CMP AL,'i'
            JE COUNT_VOWELS
            
            CMP AL,'o'
            JE COUNT_VOWELS
            
            CMP AL,'u'
            JE COUNT_VOWELS
            
            CMP AL,'A'
            JE COUNT_VOWELS
            
            CMP AL,'E'
            JE COUNT_VOWELS
            
            CMP AL,'I'
            JE COUNT_VOWELS
            
            CMP AL,'O'
            JE COUNT_VOWELS
            
            CMP AL,'U'
            JE COUNT_VOWELS
            
            JMP DIGITS_CHK ;The Char Is Not A Vowel, So Go For Next Check
             
            COUNT_VOWELS:
            INC VOWELS
            JMP WHILE
        
        DIGITS_CHK:
            CMP AL,'0'
            JL CONSONENTS_CHK_LO ;Out Of Range Go For Next Check
            CMP AL,'9'
            JG CONSONENTS_CHK_LO ;Out Of Range Go For Next Check
            
            INC DIGITS
            JMP WHILE
        
        CONSONENTS_CHK_LO:
            CMP AL,'a'
            JL CONSONENTS_CHK_UP ;Out Of Range Go For Next Check
            CMP AL,'z'
            JG CONSONENTS_CHK_UP ;Out Of Range Go For Next Check
            
            
            INC CONSONENTS
            JMP WHILE
            
        CONSONENTS_CHK_UP:
            CMP AL,'A'
            JL WHILE ;Out Of Range Go For Next Input
            CMP AL,'Z'   
            JG WHILE ;Out Of Range Go For Next Input
            
            INC CONSONENTS
            JMP WHILE
        
    OUTPUT:
        MOV AH,9
        LEA DX,MSG2
        INT 21H
        MOV AH,2
        MOV DL,VOWELS
        INT 21H
        
        MOV AH,9
        LEA DX,MSG3
        INT 21H
        MOV AH,2
        MOV DL,CONSONENTS
        INT 21H
        
        MOV AH,9
        LEA DX,MSG4
        INT 21H
        MOV AH,2
        MOV DL,DIGITS
        INT 21H
        
        MOV AH,9
        LEA DX,MSG5
        INT 21H
        MOV AH,2
        MOV DL,SPACES
        INT 21H
        
        
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN