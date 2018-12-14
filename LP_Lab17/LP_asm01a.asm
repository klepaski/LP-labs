.586
.model flat, stdcall
.code
getmin PROC x : sdword, y : dword
	mov esi, x
	mov ebx, [esi]				; мин в ebx
	mov ecx, y
Next:
	lodsd						; загр. слово из esi в eax
	sub ecx, 1
	cmp ecx, 0
	je Exit
	cmp  ebx, eax					
	jl Next
	mov ebx, eax
	jmp Next
Exit:
	mov eax, ebx
	ret								
getmin ENDP



getmax PROC x : sdword, y : dword
	mov esi, x
 	mov ebx, [esi]					
	mov ecx, y	
Next:
	lodsd							
	sub ecx, 1	
	cmp ecx, 0						
	je Exit
	cmp eax, ebx
	jl Next	
	mov ebx, eax				
	jmp Next
Exit:
	mov eax, ebx					
	ret								
getmax ENDP
end