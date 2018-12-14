.586														; система команд (процессор Pentium)
.model flat, stdcall										; модель памяти, соглашение о вызовах
includelib kernel32.lib										; компановщику: компоновать с kernel32
includelib LP_asm01a.lib

ExitProcess PROTO: DWORD									; прототип функции для завершения процесса Windows 
GetStdHandle PROTO: DWORD									; получить handle вывода на консоль 
															
WriteConsoleA PROTO: DWORD,: DWORD,: DWORD,: DWORD,: DWORD	; вывод на консоль
SetConsoleTitleA PROTO: DWORD								; прототип ф-ии устанавливающей заголовок консольного окна (функция стандартная)

getmin PROTO :DWORD, :DWORD
getmax PROTO :DWORD, :DWORD

.stack 4096

.const
	massiv			sdword		-10, 15, -23, 4, 2, 8, 34, 11, -16, 27
	consoleTitle	byte		'LP_asm01', 0
	text			byte		'getmax-getmin =', 0							
	handleOutput	sdword		-11						    ; код на запрос разрешения вывода в консоль

.data
	consoleHandle dword 0h									; состояние консоли
	max sdword ?
	min sdword ?
	result sdword ?
	resultString byte 4 dup(0)

.code

int_to_char PROC uses eax ebx ecx edi esi,		; прототип ф-ии преобр. числа в строку(сохр-возврат)
							  pstr: dword,
						  intfield: sdword
    mov edi, pstr
    mov esi, 0									; ск. символов в рез
    mov eax, intfield										
    cdq											; знак eax - на все биты edx				
    mov ebx, 10
    idiv ebx									; eax/ebx (ц.ч. - eax, ост. - edx)		
    test eax, 80000000h											
    jz plus														
    neg eax										; меняем знак
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
	INVOKE SetConsoleTitleA, offset consoleTitle		; вызов ф-и установки заголовка
	INVOKE GetStdHandle,handleOutput			        ; вызов ф-и проверки разрешения на вывод
	mov consoleHandle, eax						        ; копируем полученное разрешение из регистра eax
    INVOKE getmin, offset massiv,lengthof massiv
    mov min, eax
    INVOKE getmax, offset massiv,lengthof massiv
    mov max, eax
	sub max, min
	mov result, eax
	INVOKE WriteConsoleA, consoleHandle, offset text, sizeof text, 0, 0							;max-min
	INVOKE int_to_char, offset resultString, result												;рез.в символьную строку
	INVOKE WriteConsoleA, consoleHandle, offset resultString, sizeof resultString, 0, 0			;пишем рез-т
	INVOKE ExitProcess,0
main ENDP
end main   