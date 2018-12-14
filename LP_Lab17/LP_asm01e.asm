.586                                         ; система команд (процессор Pentium)
.model flat, stdcall                         ; модель памяти, соглашение о вызовах
includelib libucrt.lib
includelib kernel32.lib                      ; компановщику: компоновать с kernel32

EXTRN getmax: proc
EXTRN getmin: proc

ExitProcess PROTO: DWORD                     ; прототип функции
GetStdHandle PROTO: DWORD									; получить handle вывода на консоль 
															; (принимает константное значение -10 ввод, -11 вывод, -12 ошибка устройства вывода)
WriteConsoleA PROTO: DWORD,: DWORD,: DWORD,: DWORD,: DWORD	; вывод на консоль (стандартная ф-ия)
SetConsoleTitleA PROTO: DWORD								; прототип ф-ии устанавливающей заголовок консольного окна (функция стандартная)



.stack 4096													; выделение стека объёмом 4 мегабайта

.const														; константы
	consoleTitle byte 'LP_asm01', 0							; строка, первый элемент данные + нулевой бит
	handleOutput sdword -11									; код на запрос разрешения вывода в консоль
	massiv sdword -10, 15, -23, 4, 2, 8, 34, 11, -16, 27	; массив заполненый 10-ю значениями
	text byte 'getmax-getmin =', 0							; строка для вывода ответа	

.data
	consoleHandle dword 0h									; состояние консоли
	max sdword ?
	min sdword ?
	result sdword ?
	resultString byte 4 dup(0)

.code

int_to_char PROC uses eax ebx ecx edi esi, 
											pstr: dword, 
											intfield: sdword 
    mov edi, pstr						
    mov esi, 0							
    mov eax, intfield					
    cdq
    mov ebx, 10
    idiv ebx
    test eax, 80000000h
    jz plus
    neg eax
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

main PROC							; точка входа main
	INVOKE SetConsoleTitleA, offset consoleTitle			; вызываем функцию устанвки заголовка окна
	INVOKE GetStdHandle,handleOutput			 ; вызываем ф-ию проверки разрешения на вывод
	mov consoleHandle, eax						 ; копируем полученное разрешение из регистра eax
	push lengthof massiv
	push offset massiv
    call getmin				                     ; вызов процедуры getmin
    mov min, eax								 ; результат в min
	push lengthof massiv
	push offset massiv
    call getmax									 ; вызов процедуры getmin
    mov max, eax								 ; результат в min
	sub eax, min								 
	mov result, eax								 
	INVOKE WriteConsoleA, consoleHandle,offset text,sizeof text,0,0	 
	INVOKE int_to_char,offset resultString,result
	INVOKE WriteConsoleA, consoleHandle,offset resultString,sizeof resultString,0,0 		
	INVOKE ExitProcess,0			; завершение процесса Windows
main ENDP							; конец процедуры
end main							; конец модуля main   
