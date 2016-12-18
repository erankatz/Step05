#include <stdio.h>

#include <stdlib.h>

#include <memory.h>

int *Temp_0;

int *Temp_1;

int *Temp_2;

int *Temp_3;

int *Temp_4;

int *Temp_5;

int *Temp_6;

int *Temp_7;

int *Temp_8;

int *Temp_9;

int *Temp_10;

int *Temp_11;

int *Temp_12;

int *Temp_13;

int *Temp_14;

int *sp;

int *fp;

int *ra;

int *rv;

int *a0;

int *a1;

int *a2;

int *a3;

int *v0;

int *v1;

int *t0;

int *t1;

int *t2;

int *t3;

int *t4;

int *t5;

int *t6;

int *t7;

void main()

{

	int b1=1;
	int b2=2;
	int b3=3;
	int b4=4;
	int b5=5;
	int b6=6;
	sp = &b3;
	fp = &b2;
	__asm
	{
		call _here0
		_here0: pop eax
		add eax,14
		mov ra,eax
	}

	goto Label_0_main;

Label_0_main:

	fp = (int *) ((int) sp + 40);

	Temp_3 = (int *) -4;

	Temp_2 =(int *) (((int) fp) + ((int) Temp_3));

	*(Temp_2) = (int) (v0+(0));

	Temp_8 = (int *) -4;

	Temp_7 =(int *) (((int) fp) + ((int) Temp_8));

	Temp_6 = (int *) *(Temp_7 + 0);

	Temp_9 = (int *) 4;

	Temp_5 =(int *) (((int) Temp_6) + ((int) Temp_9));

	*(Temp_5) = (int) (v0+(0));

	Temp_13 = (int *) -4;

	Temp_12 =(int *) (((int) fp) + ((int) Temp_13));

	Temp_11 = (int *) *(Temp_12 + 0);

	Temp_14 = (int *) 8;

	Temp_10 =(int *) (((int) Temp_11) + ((int) Temp_14));

	*(Temp_10) = (int) (v0+(0));

	exit(0);

Label_1_AllocateRecord:

Label_2_AllocateArray:

Label_3_PrintInt:

	a0 = (int *) *(sp + 0);

	printf("%d ",(int) a0);

	a0 = (int *) 32;

	printf("%c ",(char) a0);

	__asm
	{
		jmp ra
	}

Label_4_Access_Violation:

	a0 = (int *) 65;

	printf("%c ",(char) a0);

	a0 = (int *) 99;

	printf("%c ",(char) a0);

	a0 = (int *) 99;

	printf("%c ",(char) a0);

	a0 = (int *) 101;

	printf("%c ",(char) a0);

	a0 = (int *) 115;

	printf("%c ",(char) a0);

	a0 = (int *) 115;

	printf("%c ",(char) a0);

	a0 = (int *) 32;

	printf("%c ",(char) a0);

	a0 = (int *) 86;

	printf("%c ",(char) a0);

	a0 = (int *) 105;

	printf("%c ",(char) a0);

	a0 = (int *) 111;

	printf("%c ",(char) a0);

	a0 = (int *) 108;

	printf("%c ",(char) a0);

	a0 = (int *) 97;

	printf("%c ",(char) a0);

	a0 = (int *) 116;

	printf("%c ",(char) a0);

	a0 = (int *) 105;

	printf("%c ",(char) a0);

	a0 = (int *) 111;

	printf("%c ",(char) a0);

	a0 = (int *) 110;

	printf("%c ",(char) a0);

	exit(0);

}

