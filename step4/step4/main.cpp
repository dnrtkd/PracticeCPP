#include <stdio.h>



int main()
{
	int kg=0;
	float meter=0.0;
	float bmi=0.0;

	printf_s("Ű�� �����Ը� �Է��ϼ���.\n");
	scanf_s("%f " , &meter);
	scanf_s("%d ", &kg);

	bmi = kg / (meter * meter);

	if (bmi >= 30) printf_s("����\n");
	else if (bmi >= 25) printf_s("��\n");
	else if (bmi >= 23) printf_s("��ü��\n");
	else if (bmi >= 18.5) printf_s("ǥ��\n");
	else printf_s("ü�߹̴�");

}