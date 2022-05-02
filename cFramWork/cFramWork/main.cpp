#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <time.h>
#include <Windows.h>
#include <conio.h>

//�� ��ȯ�� ���� ����
int SceneState = 0;
//�� ��ȯ ���
const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_NewGame = 2;
const int Scene_Menu2 = 3;
const int Scene_SelectField = 4;
const int Scene_Exit = 5;
//���� ��
int MapState = 0;
//�� ���
const int Map_Samgir = 0;
const int Map_SmallCave = 1;
const int Map_seaBottom = 2;

const int Job_sword = 0;
const int Job_bow = 1;
const int Job_gun = 2;

typedef struct tagMap
{
	char* name;
	int levelLimit;
	int apearPet[3];
	int apearLevel;
}Map; //�� ���� ����ü

//����
typedef struct tagStatus
{
	int hp;
	int att;
	int def;
	int quick;
}STATUS;

typedef struct tagPlayer //�÷��̾� ����ü
{
	int level;
	char* name;
	int exp;
	int gold;
	int job;
	STATUS status;
}Player;

Map maps[10];

void HideCursor();
void SetPosition(int _x, int _y, char* _str, int _Color);
void SetColor(int _Color);
void LogoScene();
void SceneManager();
void MenuScene();
void MenuScene2();
char* SetName();
void SelectFieldScene();
void InBattle();
void InField();
void showFrame(int w, int h, int startX, int startY);
void allotPoints();
void CreatePlayerScene();
void showPlayer();
void SetCursor(int _x, int _y);
Player player;
//const int CursorX;
//const int CursorY;


int main(void)
{
	srand(time(0));

	// ** Ŀ���� �Ⱥ��̰� ��.
	HideCursor();

	// ** �ܼ�â�� ����� ����.
	system("mode con:cols=120 lines=30");

	// ** �ݼ�â�� �̸��� ����
	system("title ȫ�浿 Framework v0.6");

	// ** ��ü ������ ������.
	//system("color 70");

	DWORD dwTime = GetTickCount(); // 1/1000 (1000���� 1��)
	int Delay = 1000;

	int UpCount = 0;

	while (true)
	{
		if (dwTime + Delay < GetTickCount())
		{
			dwTime = GetTickCount();

			// ** �ܼ�â�� �ִ� ��� ������ ����.
			system("cls");
			// ** ���� ����
			SceneManager();

		}
	}

	return 0;
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO Info;

	Info.dwSize = 1;// Ŀ���� ũ��
	Info.bVisible = false; //Ŀ���� ǥ�ÿ���

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);//�μ�: �ܼ� �⺻ �ڵ�, ���� ��
}

void SceneManager()
{
	switch (SceneState)
	{
	case Scene_Logo:
		LogoScene();
		break;
	case Scene_Menu:
		MenuScene();
		break;
	case Scene_NewGame:
		CreatePlayerScene();
		break;
	case Scene_Menu2:
		MenuScene2();
		break;
	case Scene_SelectField:
		SelectFieldScene();
		break;
	case Scene_Exit:
		exit(NULL);// ** ���α׷� ����
		break;
	}
}

void LogoScene()
{
	int Width = (120 / 2) - (strlen("      ,gggg,     _,gggggg,_        ,gg,         _,gggggg,_      ") / 2);
	int Height = 10;

	SetPosition(Width, Height + 1, (char*)"      ,gggg,     _,gggggg,_        ,gg,         _,gggggg,_      ", 1);
	SetPosition(Width, Height + 2, (char*)"      d8` `8I   ,d8P``d8P`Y8b,     i8``8i      ,d8P``d8P`Y8b,   ", 2);
	SetPosition(Width, Height + 3, (char*)"      88  ,dP  ,d8'   Y8   `8b,dP  `8,,8'     ,d8'   Y8   `8b,dP", 3);
	SetPosition(Width, Height + 4, (char*)"   8888888P`   d8'    `Ybaaad88P'   `Y88aaad8 d8'    `Ybaaad88P'", 4);
	SetPosition(Width, Height + 5, (char*)"      88       8P       `````Y8      d8````Y8,8P       `````Y8  ", 5);
	SetPosition(Width, Height + 6, (char*)"      88       8b            d8     ,8P     8b8b            d8  ", 6);
	SetPosition(Width, Height + 7, (char*)" ,aa,_88       Y8,          ,8P     dP      Y8Y8,          ,8P  ", 7);
	SetPosition(Width, Height + 8, (char*)"dP` `88P       `Y8,        ,8P' _ ,dP'      I8`Y8,        ,8P'  ", 8);
	SetPosition(Width, Height + 9, (char*)"Yb,_,d88b,,_    `Y8b,,__,,d8P'  `888,,_____,dP `Y8b,,__,,d8P'   ", 9);
	SetPosition(Width, Height + 10, (char*)" `Y8P`  `Y88888   ``Y8888P`'    a8P`Y888888P`    ``Y8888P`'     ", 10);
	SetColor(1);

	Sleep(3000);
	printf_s("\n������ �����Ϸ���, EnterŰ�� �����ּ���.");
	char c;
	while (true)
	{
		c = _getch();
		if (c == 13)break;
	}

	SceneState++;
}


void MenuScene()
{
	printf_s("MenuScene\n\n");

	//printf_s("���� �� ����??\n1. ���ӽ���\n2. ����\n�Է� : ");
	printf_s("1. ���ν���\n");
	printf_s("2. �̾��ϱ�\n");
	printf_s("3. ��������\n");
	int i = 0;
	scanf("%d", &i);

	if (i == 1)
		SceneState++;
	else if (i == 2) SceneState += 2;
	else if (i == 3)
		SceneState = Scene_Exit;
}

void CreatePlayerScene()
{
	printf_s("�̸� �Է�: ");
	player.name = SetName();
	player.level = 1;
	player.gold = 0;
	player.exp = 0;

	printf_s("\n\n���� ����\n1. �˼���\n2. �ü���\n3. �Ѽ���");
	int i = 0;
	scanf("%d", &i);

	if (i == 1) player.job = 0;
	if (i == 2) player.job = 1;
	if (i == 3) player.job = 2;

	allotPoints();
	SceneState++;
}

void allotPoints()
{
	if (player.job == Job_sword)
	{
		player.status.att = 8;
		player.status.def = 8;
		player.status.quick = 5;
		player.status.hp = 50;
	}
	else if (player.job == Job_bow)
	{
		player.status.att = 8;
		player.status.def = 5;
		player.status.quick = 6;
		player.status.hp = 40;
	}
	else if (player.job == Job_gun)
	{
		player.status.att = 10;
		player.status.def = 4;
		player.status.quick = 5;
		player.status.hp = 35;
	}
}


void MenuScene2()
{
	printf_s("MenuScene2\n");

	printf_s("\n1. �ʵ�Ž��\n2. ������Ʈ\n3. �κ��丮\n4. �÷��̾� ����");

	int i = 0;
	scanf("%d", &i);

	if (i == 1)
		SceneState++;
	else if (i == 2) {}
	else if (i == 3) {}
	else if (i == 4)
	{
		showPlayer();
	}

}

void showPlayer()
{
	short startX = 40;
	short startY = 5;


	showFrame(40, 18, startX, startY);
	SetCursor(startX + 3, startY + 2);
	printf_s("�÷��̾� �г���: %s", player.name);

	SetCursor(startX + 2, startY + 3);
	printf_s("����          : %d", player.level);

	SetCursor(startX + 2, startY + 4);
	printf_s("����ġ        : %d", player.exp);

	SetCursor(startX + 2, startY + 5);
	printf_s("����          : %d", player.job);

	SetCursor(startX + 2, startY + 6);
	printf_s("���          : %d", player.gold);

	SetCursor(startX + 2, startY + 7);
	printf_s("ü��          : %d", player.status.hp);

	SetCursor(startX + 2, startY + 8);
	printf_s("���ݷ�        : %d", player.status.att);

	SetCursor(startX + 2, startY + 9);
	printf_s("����        : %d", player.status.def);

	SetCursor(startX + 2, startY + 10);
	printf_s("���߷�        : %d", player.status.quick);

	SetCursor(startX + 2, startY + 11);
	printf_s("1. ĳ���� ����â �ݱ�");

	int i = 0;
	scanf("%d", &i);


}

void SelectFieldScene()
{
	printf_s("SelectFieldScene\n\n");
	printf_s("1. %s\n2. %s\n3. %s ", maps[Map_Samgir].name, maps[Map_SmallCave].name, maps[Map_seaBottom].name);

	int i = 0;
	scanf("%d", &i);

	if (i == 1)
	{
		MapState = Map_Samgir;
	}
	else if (i == 2)
	{
		MapState = Map_SmallCave;
	}
	else if (i == 3)
	{
		MapState = Map_seaBottom;
	}
	InField();
}
void InField()
{
	system("cls");

	printf("%s\n", maps[MapState].name);

	printf("1. ���\n 2. ��Ʈ\n 3. �κ��丮\n 4. �ڷΰ���");

	int i = 0;
	scanf("%d", &i);

	if (i == 1)
	{
		InBattle();
	}
	else if (i == 2)
	{

	}
	else if (i == 3)
	{

	}
	else if (i == 4)
	{
		SceneState--;
	}
}
void InBattle()
{
	int R1 = rand() % 3;


	while (true)
	{

		int i = 0;
		scanf("%d", &i);

		printf_s("\n\n\n\n\n1.�����ϱ�\n2.������3.\n�����ۻ��\n��ȹ�ϱ�\n��������\n");

		if (i == 1)
		{
			//if(player.holdPet[currBattlePet].Att>)
		}



	}


}

void SetPosition(int _x, int _y, char* _str, int _Color)
{
	COORD Pos = { _x, _y }; // �ܼ� ������

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//Ŀ�� ��ġ �̵�
	SetColor(_Color);

	printf_s("%s", _str);
}

void SetCursor(int _x, int _y)
{
	COORD Pos = { _x, _y }; // �ܼ� ������

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//Ŀ�� ��ġ �̵�
}
//��, ����, ��������
void showFrame(int w, int h, int startX, int startY)
{
	for (int i = 0; i < h; i++)
	{
		COORD Pos = { startX, startY + i }; // �ܼ� ������
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//Ŀ�� ��ġ �̵�
		for (int j = 0; j < w; j++)
		{
			if (i == 0 && j == 0)printf_s("��");
			else if (i == 0 && j == w - 1)printf_s("��");
			else if (i == (h - 1) && j == 0)printf_s("��");
			else if (i == (h - 1) && j == w - 1)printf_s("��");
			else if (i == 0 || i == h - 1) printf_s("��");
			else if (j == 0 || j == w - 1) printf_s("��");
			else printf_s(" ");
		}
	}
	COORD Pos = { startX + 1, startY + 1 }; // �ܼ� ������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//Ŀ�� ��ġ �̵�
}

void SetColor(int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color); //���� ��ȯ
}

char* SetName()
{
	// ** scanf �Լ��� ���ڿ��� �Է¹ޱ� ���� ���ڿ��� �������ִ� �迭�� ����.
	char Buffer[128] = "";
	// ** ���ڿ��� �Է� ����.
	scanf("%s", Buffer);

	// ** �Է� �������� �迭 ������, ��ȯ ���� ĳ���� ���������̹Ƿ� ���ڿ��� ���������.
	// ** ���ڿ��� ���� �ϱ����� �����Ͱ� ����Ű�� ������ �Է¹��� ���ڿ��� ��ư���ŭ�� ũ��� �޸� �Ҵ�.
	char* pName = (char*)malloc(strlen(Buffer) + 1);

	// ** Buffer �� ���� ���ڿ��� pName ���� ����.
	strcpy(pName, Buffer);

	// ** ��ȯ.
	return pName;
}