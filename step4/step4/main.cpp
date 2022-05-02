#include <stdio.h>



int main()
{
	int kg=0;
	float meter=0.0;
	float bmi=0.0;

	printf_s("키와 몸무게를 입력하세요.\n");
	scanf_s("%f " , &meter);
	scanf_s("%d ", &kg);

	bmi = kg / (meter * meter);

	if (bmi >= 30) printf_s("고도비만\n");
	else if (bmi >= 25) printf_s("비만\n");
	else if (bmi >= 23) printf_s("과체중\n");
	else if (bmi >= 18.5) printf_s("표준\n");
	else printf_s("체중미달");

}