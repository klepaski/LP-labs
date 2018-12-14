.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.DATA
		myBytes		BYTE	10h, 20h, 30h, 40h			;1б
		myWords		WORD	8Ah, 3Bh, 44h, 5Fh, 99h		;2б
		myDoubles	DWORD	1, 2, 3, 4, 5, 6			;4б
		myPointer	DWORD	myDoubles					;4б


		myMassive BYTE 1, 2, 3, 4, 5, 6, 7				;массив[7](зад.с)
		myCol DWORD 7									;кол-во элементов
		myP DWORD myCol									;указатель на кол-во

		Str1 DB "Julia Chistyakova, 1-5", 0
		Str2 DB "NULL IS PRESENT", 0
		Str3 DB "NULL IS EPSEND", 0


.CODE
main PROC
start :
			mov EDI, 4
			mov AX, [myWords + EDI]				;ЕАХ(32) (АХ - 16) - для хранения промежут.данных
			mov BX, myWords[0]					;ЕВХ(32) (ВХ - 16) - регистр базы, для хранения базового адреc


;Вычислить сумму элементов массива. Результат запомнить в регистре EAX.

			mov ESI, OFFSET myMassive
			mov EAX, 0
			add AL, [ESI]
			mov ECX, 6

			loop1:									;пока ECX != 0
					add ESI, 1
					add AL, [ESI]
					loop loop1

;Проверить наличие в массиве нулевого элемента. Если есть - в EBX 0, иначе - 1

			mov AL, 0
			mov ESI, OFFSET myMassive
			mov EBX, 1
			mov ECX, 0								;в ECX 0, для сравнения с [EDX]
			mov EDX, myP


			loop2 :									;проверка на 0
					cmp AL, [ESI]
					jne loop3
					mov EBX, 0
					jmp cout2

			loop3 :
					add ESI, 1
					add ECX, 1
					cmp ECX, [EDX]
					jne loop2
					jmp cout1


;Вывод в консоль окна с сообщением и кнопкой выхода. Заголовок окна : ФИО студента, курс, номер группы

			cout1 :
				INVOKE MessageBoxA, 0, OFFSET Str3, OFFSET Str1, 1
				INVOKE ExitProcess, 2

			cout2 :
				INVOKE MessageBoxA, 0, OFFSET Str2, OFFSET Str1, 1
				INVOKE ExitProcess, 2


	push 0
	call ExitProcess

	main ENDP
	end main