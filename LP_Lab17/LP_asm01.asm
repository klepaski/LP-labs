.586														; система команд (процессор Pentium)
.model flat, stdcall										; модель памяти(плоская), соглашение о вызовах
includelib kernel32.lib										; компановщику: компоновать с kernel32
ExitProcess PROTO: DWORD									; прототип функции для завершения процесса Windows 

.stack 4096

.const
	massiv sdword -10, 15, -23, 4, 2, 8, 34, 11, -16, 27

.data
	min sdword ?

.code

getmin PROC x : sdword, y : dword
	mov esi, x
	mov ebx, 4096				; мин в ebx
	mov ecx, y
Next:
	lodsd						; в eax загр. слово из esi
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

main PROC													; точка входа main
    INVOKE getmin, offset massiv, lengthof massiv			; вызов процедуры getmin
    mov min, eax											; результат в min												
	INVOKE ExitProcess, 0									; завершение процесса Windows
main ENDP													; конец процедуры
end main  