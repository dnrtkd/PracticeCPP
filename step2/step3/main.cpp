#include <stdio.h>

int main(void)
{/*
	int a, b;
	int c = 30, d = 40;

	a = 10;
	b = 10;

	printf_s("%d %d\n", a, b);
	printf_s("%d %d\n", c, d);
	*/
	/*float fNumber;
	fNumber = 87.654321;

	printf_s("%f\n", fNumber);
	printf_s("%d\n", (int)fNumber);
	printf_s("%c\n", (char)fNumber);
	printf_s("%d\n", fNumber);*/

	/*float fpi = 3.1401435f;
	int i = fpi;
	printf_s("%d\n", i);
	printf_s("%0.3f\n", fpi);*/

	//printf_s("%d\n", 3.14);
	//printf_s("%d\n", 314);
	//printf_s("%d\n", 0x13a);

	//printf_s("%x\n", 0x13a);
	//printf_s("%X\n", 0x13A);
	 
	//printf_s("%d\n", 'A');
	//printf_s("%c\n", 'A');
	//printf_s("%c\n", 33);
	//printf_s("%c\n", 0x26);
	//printf_s("%x\n", 'A');

	int iNum;
	float fNum;
	printf_s("iNum 값 입력: ");
	scanf_s("%d", &iNum);

	printf_s("fNum 값 입력: ");
	scanf_s("%f", &fNum);

	printf_s("iNum: %d\n ",iNum);
	printf_s("fNum:%f\n ",fNum);

	
}