//C++_Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


#define _CRT_SECURE_NO_WARNINGS //scanf 보안경고 해제
#include <stdio.h> //표준 입출력 함수 헤더 파일 
#include <malloc.h> //메모리 동적 할당 함수가 들어있음
#include <string>//strcpy,strlen등 문자열 관련 함수 
#include <time.h>//time함수를 쓰기 위한 헤더파일
#include <Windows.h>//윈도우 함수들이 정의되어있음


const int TYPE_PLAYER = 1; //플레이어 타입 상수 변수 선언
const int TYPE_ENEMY = 2; //적 타입 상수 변수 선언

typedef struct tagInfo//적이나 플레이어의 정보를 나타내는 tagInfo구조체 선언
{
	char* Name; //이름
	int HP; //체력
	int MP; //마나

	int EXP; //경험치

	float Att; //공격력
	float Def; //방어력

	int Level; //레벨

}INFO; //INFO라는 별명 사용


typedef struct tagObject//적이나 플레이어를 나타내는 tagObject구조체 선언
{
	INFO Info; //정보를 담은 구조체

}OBJECT; //OBJECT별명 사용







void InitializeObject(OBJECT* _Obj, int ObjectType); //InitializeObject함수 전방선언 
char* SetName(); //SetName 전방선언


int main(void)
{
	OBJECT* Player = (OBJECT*)malloc(sizeof(OBJECT)); // OBJECT형 포인터 변수 Player에 메모리 동적 할당
	InitializeObject(Player, TYPE_PLAYER); //InitializeObject함수 호출 ,

	while (true) //무한 루프
	{
		OBJECT* Enemy = (OBJECT*)malloc(sizeof(OBJECT)); //OBJECT형 포인터 변수 Enemy에 메모리 동적 할당
		InitializeObject(Enemy, TYPE_ENEMY); //InitializeObject함수 호출
		int isBattel = 1; // 배틀중이면 1 배틀 중이아니면 0
		while (isBattel)
		{
			// ** 콘솔창을 모두 지움.
			system("cls");
			//플레이어의 정보 모두 출력
			printf_s("\n[%s]\n", Player->Info.Name);
			printf_s("HP : %d\n", Player->Info.HP);
			printf_s("MP : %d\n", Player->Info.MP);
			printf_s("공격력 : %.2f\n", Player->Info.Att);
			printf_s("방어력 : %.2f\n", Player->Info.Def);
			printf_s("EXP : %d\n", Player->Info.EXP);
			printf_s("Level : %d\n\n", Player->Info.Level);
			//적의 정보 모두 출력
			printf_s("[%s]\n", Enemy->Info.Name);
			printf_s("HP : %d\n", Enemy->Info.HP);
			printf_s("MP : %d\n", Enemy->Info.MP);
			printf_s("공격력 : %.2f\n", Enemy->Info.Att);
			printf_s("방어력 : %.2f\n", Enemy->Info.Def);
			printf_s("EXP : %d\n", Enemy->Info.EXP);
			printf_s("Level : %d\n\n", Enemy->Info.Level);
			Sleep(500);


			int iChoice = 0; //플레이어의 선택 정보를 담기 위한 변수
			printf_s("몬스터와 만났습니다. 공격하시겠습니까 ?\n1. 공격\n2. 도망\n입력 : ");
			scanf_s("%d", &iChoice);


			switch (iChoice)
			{
			case 1: //공격 선택
				if (Player->Info.Att > Enemy->Info.Def) //플레이어의 공격력이 적의 방어력보다 높다면
				{
					Enemy->Info.HP -= Player->Info.Att - Enemy->Info.Def; //적의 체력-(플레이어 공격력-적 방어력)
				}
				else //플레이어의 공격력이 적의 방어력보다 낮다면
					Enemy->Info.HP -= 1; //적의 체력을 1 감소


				if (Enemy->Info.Att > Player->Info.Def)//적의 공격력이 플레이어의 방어력보다 높다면
				{
					Player->Info.HP -= Enemy->Info.Att - Player->Info.Def;//플레이어의 체력-(적 공격력-플레이어 방어력)
				}
				else//적의 공격력이 플레이어의 방어력보다 낮다면
					Player->Info.HP -= 1; //플레이어의 체력 1감소
				break;
			case 2://도망 선택
				srand(time(0)); //랜덤 함수에 사용 될 수를 초기화함. 매개변수로 받는 시드값 이용해 초기화
				int iRand = rand() % 100;//rand(): 0~32767값 반환 %연산을 통해 0~99값중 하나가 iRand에 저장
				if (iRand < 10)//10분의 1 확률
				{
					printf_s("도망치는것에 [성공] 했습니다.\n");
					free(Enemy); //메모리 해제
					Sleep(500);//작업 대기 함수 Sleep(500) 0.5초 매개변수*1/1000초
					isBattel = 0;//배틀 종료
				}
				else
				{
					printf_s("도망치는것에 [실패] 했습니다.\n");
					Sleep(500);
				}
				break;
			}
		}


	}


}



//OBJECT타입 변수의 Info값을 초기화 시켜줌 ,objectType으로 플레이어나 적으로 초기화
void InitializeObject(OBJECT* _Obj, int ObjectType)
{
	switch (ObjectType)
	{
	case TYPE_PLAYER: //플레이어 타입이면
		_Obj->Info.Name = SetName();//이름 입력 함수
		//정보값 초기화
		_Obj->Info.Att = 10;
		_Obj->Info.Def = 10;
		_Obj->Info.EXP = 0;
		_Obj->Info.HP = 100;
		_Obj->Info.MP = 10;
		_Obj->Info.Level = 1;
		break;
	case TYPE_ENEMY://적 타입이면
		_Obj->Info.Name = (char*)"Enemy";//Enemy로 이름 설정
		//정보값 초기화
		_Obj->Info.Att = 5;
		_Obj->Info.Def = 15;
		_Obj->Info.EXP = 0;
		_Obj->Info.HP = 30;
		_Obj->Info.MP = 5;
		_Obj->Info.Level = 1;
		break;
	}
}

char* SetName() //이름 입력 함수
{
	char Buffer[128] = ""; //빈 문자형 배열 생성

	printf_s("이름 입력 : ");
	scanf("%s", Buffer); //배열에 입력받은값 저장

	char* pName = (char*)malloc(strlen(Buffer) + 1); //포인터변수 pName에 Buffer의 길이+1만큼 메모리 동적할당,+1을 하는이유:문자열의 마지막은 널값이어야해서

	strcpy(pName, Buffer);//pName이 가리키는 메모리에 Buffer안의 데이터 복사

	return pName;//pName 반환
}


