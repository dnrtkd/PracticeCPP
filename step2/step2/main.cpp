#include <stdio.h>

//** main함수: 컴파일러가 가장 먼저 찾아 실행시키는 함수

int main(void) 
{
	//** 서식문자

	   //**[%d] 10진 정수
	   //**[%s] 문자열
 	   //**[%c] 문자
	   //**[%f] 10진 실수

	printf_s("char:%d\n", sizeof(char));
	printf_s("short:%d\n", sizeof(short));
	printf_s("int:%d\n", sizeof(int));
	printf_s("float:%d\n", sizeof(float));
	printf_s("long:%d\n", sizeof(long));
	printf_s("double:%d\n", sizeof(double));

	  //** [\n] 줄 바꿈
	  //** [\t] 공백
	  //** []
	printf_s("*************************************\n");
	printf_s("Let's Study C/C++ Game Programming!!!\n");
	printf_s("*************************************");

	return 0;
}