.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.DATA
		myBytes		BYTE	10h, 20h, 30h, 40h			;1�
		myWords		WORD	8Ah, 3Bh, 44h, 5Fh, 99h		;2�
		myDoubles	DWORD	1, 2, 3, 4, 5, 6			;4�
		myPointer	DWORD	myDoubles					;4�


		myMassive BYTE 1, 2, 3, 4, 5, 6, 7				;������[7](���.�)
		myCol DWORD 7									;���-�� ���������
		myP DWORD myCol									;��������� �� ���-��

		Str1 DB "Julia Chistyakova, 1-5", 0
		Str2 DB "NULL IS PRESENT", 0
		Str3 DB "NULL IS EPSEND", 0


.CODE
main PROC
start :
			mov EDI, 4
			mov AX, [myWords + EDI]				;���(32) (�� - 16) - ��� �������� ��������.������
			mov BX, myWords[0]					;���(32) (�� - 16) - ������� ����, ��� �������� �������� ����c


;��������� ����� ��������� �������. ��������� ��������� � �������� EAX.

			mov ESI, OFFSET myMassive
			mov EAX, 0
			add AL, [ESI]
			mov ECX, 6

			loop1:									;���� ECX != 0
					add ESI, 1
					add AL, [ESI]
					loop loop1

;��������� ������� � ������� �������� ��������. ���� ���� - � EBX 0, ����� - 1

			mov AL, 0
			mov ESI, OFFSET myMassive
			mov EBX, 1
			mov ECX, 0								;� ECX 0, ��� ��������� � [EDX]
			mov EDX, myP


			loop2 :									;�������� �� 0
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


;����� � ������� ���� � ���������� � ������� ������. ��������� ���� : ��� ��������, ����, ����� ������

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