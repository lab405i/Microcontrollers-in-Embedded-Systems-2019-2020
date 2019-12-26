#include <mega128.h>
#include <io.h>
#include <stdio.h>

void main(void)
{
	DDRD = 0xFF;

	#asm


		ldi r19, 0x03
		ldi r26, 0x30
		ldi r27, 0x02
		ldi r28, 0x40
		ldi r29, 0x02
		ldi r30, 0x50
		ldi r31, 0x02

		onemore:

	ld r20, X +
		ld r21, Y +
		sub r20, r21
		st Z + , r20

		nop

		dec r19
		BREQ M1

		JMP onemore
		ldi r18, 0x4D
		ldi r17, 0x58
		ldi r24, 0xFF

		nop

		M1 :

	CPI r20, 0
		out $12, r17
		JMP M2
		out $12, r24

		nop

		st Z + , r20

		nop

		dec r19
		BREQ M1
		JMP onemore
		ldi r18, 0x4D
		ldi r17, 0x58
		ldi r24, 0xFF

		nop

		M1 :
	CPI r20, 0
		out $12, r18
		JMP M2
		out $2, r17
		M2 :
	out $12, r24

		nop

		nop
		#endasm
}