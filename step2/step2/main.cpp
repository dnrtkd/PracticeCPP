#include <stdio.h>

//** main�Լ�: �����Ϸ��� ���� ���� ã�� �����Ű�� �Լ�

int main(void) 
{
	//** ���Ĺ���

	   //**[%d] 10�� ����
	   //**[%s] ���ڿ�
 	   //**[%c] ����
	   //**[%f] 10�� �Ǽ�

	printf_s("char:%d\n", sizeof(char));
	printf_s("short:%d\n", sizeof(short));
	printf_s("int:%d\n", sizeof(int));
	printf_s("float:%d\n", sizeof(float));
	printf_s("long:%d\n", sizeof(long));
	printf_s("double:%d\n", sizeof(double));

	  //** [\n] �� �ٲ�
	  //** [\t] ����
	  //** []
	printf_s("*************************************\n");
	printf_s("Let's Study C/C++ Game Programming!!!\n");
	printf_s("*************************************");

	return 0;
}