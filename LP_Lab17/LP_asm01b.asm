.586														; ������� ������ (��������� Pentium)
.model flat, stdcall										; ������ ������, ���������� � �������
includelib kernel32.lib										; ������������: ����������� � kernel32
includelib LP_asm01a.lib

ExitProcess PROTO: DWORD									; �������� ������� ��� ���������� �������� Windows 
GetStdHandle PROTO: DWORD									; �������� handle ������ �� ������� 
															
WriteConsoleA PROTO: DWORD,: DWORD,: DWORD,: DWORD,: DWORD	; ����� �� �������
SetConsoleTitleA PROTO: DWORD								; �������� �-�� ��������������� ��������� ����������� ���� (������� �����������)

getmin PROTO :DWORD, :DWORD
getmax PROTO :DWORD, :DWORD

.stack 4096

.const
	massiv			sdword		-10, 15, -23, 4, 2, 8, 34, 11, -16, 27
	consoleTitle	byte		'LP_asm01', 0
	text			byte		'getmax-getmin =', 0							
	handleOutput	sdword		-11						    ; ��� �� ������ ���������� ������ � �������

.data
	consoleHandle dword 0h									; ��������� �������
	max sdword ?
	min sdword ?
	result sdword ?
	resultString byte 4 dup(0)

.code

int_to_char PROC uses eax ebx ecx edi esi,		; �������� �-�� ������. ����� � ������(����-�������)
							  pstr: dword,
						  intfield: sdword
    mov edi, pstr
    mov esi, 0									; ��. �������� � ���
    mov eax, intfield										
    cdq											; ���� eax - �� ��� ���� edx				
    mov ebx, 10
    idiv ebx									; eax/ebx (�.�. - eax, ���. - edx)		
    test eax, 80000000h											
    jz plus														
    neg eax										; ������ ����
    neg edx
    mov cl, '-'
    mov[edi], cl
    inc edi														
plus:
    push dx
    inc esi
    test eax, eax												
    jz fin
    cdq
    idiv ebx
    jmp plus
fin:
    mov ecx ,esi
write:
    pop bx														
    add bl,'0'
    mov[edi], bl
    inc edi
    loop write
    ret
int_to_char ENDP

main PROC
	INVOKE SetConsoleTitleA, offset consoleTitle		; ����� �-� ��������� ���������
	INVOKE GetStdHandle,handleOutput			        ; ����� �-� �������� ���������� �� �����
	mov consoleHandle, eax						        ; �������� ���������� ���������� �� �������� eax
    INVOKE getmin, offset massiv,lengthof massiv
    mov min, eax
    INVOKE getmax, offset massiv,lengthof massiv
    mov max, eax
	sub max, min
	mov result, eax
	INVOKE WriteConsoleA, consoleHandle, offset text, sizeof text, 0, 0							;max-min
	INVOKE int_to_char, offset resultString, result												;���.� ���������� ������
	INVOKE WriteConsoleA, consoleHandle, offset resultString, sizeof resultString, 0, 0			;����� ���-�
	INVOKE ExitProcess,0
main ENDP
end main   