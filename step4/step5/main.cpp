#include <stdio.h>
int input(int _inumber);
char Output(int _inumber);

int main(void)
{
	int iNumber;
	printf_s("1~255 �� �ϳ�: ");
	scanf_s("%d", &iNumber);

	switch (input(iNumber))
	{
	case 1:
		printf_s("���� 1�Է�\n\n");
		break;
	case 2:
		printf_s("���� 2�Է�\n\n");
		break;
	case 3:
		printf_s("���� 3�Է�\n\n");
		break;
	default:
		printf_s("%c\n",Output(iNumber));
	
	}
		

}
int input(int _inumber)
{
	return _inumber;
}

char Output(int _inumber) {
	return _inumber;
}
