.586														; ������� ������ (��������� Pentium)
.model flat, stdcall										; ������ ������(�������), ���������� � �������
includelib kernel32.lib										; ������������: ����������� � kernel32
ExitProcess PROTO: DWORD									; �������� ������� ��� ���������� �������� Windows 

.stack 4096

.const
	massiv sdword -10, 15, -23, 4, 2, 8, 34, 11, -16, 27

.data
	min sdword ?

.code

getmin PROC x : sdword, y : dword
	mov esi, x
	mov ebx, 4096				; ��� � ebx
	mov ecx, y
Next:
	lodsd						; � eax ����. ����� �� esi
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

main PROC													; ����� ����� main
    INVOKE getmin, offset massiv, lengthof massiv			; ����� ��������� getmin
    mov min, eax											; ��������� � min												
	INVOKE ExitProcess, 0									; ���������� �������� Windows
main ENDP													; ����� ���������
end main  