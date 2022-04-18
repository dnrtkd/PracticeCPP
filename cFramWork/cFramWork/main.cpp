//C++_Practice.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.


#define _CRT_SECURE_NO_WARNINGS //scanf ���Ȱ�� ����
#include <stdio.h> //ǥ�� ����� �Լ� ��� ���� 
#include <malloc.h> //�޸� ���� �Ҵ� �Լ��� �������
#include <string>//strcpy,strlen�� ���ڿ� ���� �Լ� 
#include <time.h>//time�Լ��� ���� ���� �������
#include <Windows.h>//������ �Լ����� ���ǵǾ�����


const int TYPE_PLAYER = 1; //�÷��̾� Ÿ�� ��� ���� ����
const int TYPE_ENEMY = 2; //�� Ÿ�� ��� ���� ����

typedef struct tagInfo//���̳� �÷��̾��� ������ ��Ÿ���� tagInfo����ü ����
{
	char* Name; //�̸�
	int HP; //ü��
	int MP; //����

	int EXP; //����ġ

	float Att; //���ݷ�
	float Def; //����

	int Level; //����

}INFO; //INFO��� ���� ���


typedef struct tagObject//���̳� �÷��̾ ��Ÿ���� tagObject����ü ����
{
	INFO Info; //������ ���� ����ü

}OBJECT; //OBJECT���� ���







void InitializeObject(OBJECT* _Obj, int ObjectType); //InitializeObject�Լ� ���漱�� 
char* SetName(); //SetName ���漱��


int main(void)
{
	OBJECT* Player = (OBJECT*)malloc(sizeof(OBJECT)); // OBJECT�� ������ ���� Player�� �޸� ���� �Ҵ�
	InitializeObject(Player, TYPE_PLAYER); //InitializeObject�Լ� ȣ�� ,

	while (true) //���� ����
	{
		OBJECT* Enemy = (OBJECT*)malloc(sizeof(OBJECT)); //OBJECT�� ������ ���� Enemy�� �޸� ���� �Ҵ�
		InitializeObject(Enemy, TYPE_ENEMY); //InitializeObject�Լ� ȣ��
		int isBattel = 1; // ��Ʋ���̸� 1 ��Ʋ ���̾ƴϸ� 0
		while (isBattel)
		{
			// ** �ܼ�â�� ��� ����.
			system("cls");
			//�÷��̾��� ���� ��� ���
			printf_s("\n[%s]\n", Player->Info.Name);
			printf_s("HP : %d\n", Player->Info.HP);
			printf_s("MP : %d\n", Player->Info.MP);
			printf_s("���ݷ� : %.2f\n", Player->Info.Att);
			printf_s("���� : %.2f\n", Player->Info.Def);
			printf_s("EXP : %d\n", Player->Info.EXP);
			printf_s("Level : %d\n\n", Player->Info.Level);
			//���� ���� ��� ���
			printf_s("[%s]\n", Enemy->Info.Name);
			printf_s("HP : %d\n", Enemy->Info.HP);
			printf_s("MP : %d\n", Enemy->Info.MP);
			printf_s("���ݷ� : %.2f\n", Enemy->Info.Att);
			printf_s("���� : %.2f\n", Enemy->Info.Def);
			printf_s("EXP : %d\n", Enemy->Info.EXP);
			printf_s("Level : %d\n\n", Enemy->Info.Level);
			Sleep(500);


			int iChoice = 0; //�÷��̾��� ���� ������ ��� ���� ����
			printf_s("���Ϳ� �������ϴ�. �����Ͻðڽ��ϱ� ?\n1. ����\n2. ����\n�Է� : ");
			scanf_s("%d", &iChoice);


			switch (iChoice)
			{
			case 1: //���� ����
				if (Player->Info.Att > Enemy->Info.Def) //�÷��̾��� ���ݷ��� ���� ���º��� ���ٸ�
				{
					Enemy->Info.HP -= Player->Info.Att - Enemy->Info.Def; //���� ü��-(�÷��̾� ���ݷ�-�� ����)
				}
				else //�÷��̾��� ���ݷ��� ���� ���º��� ���ٸ�
					Enemy->Info.HP -= 1; //���� ü���� 1 ����


				if (Enemy->Info.Att > Player->Info.Def)//���� ���ݷ��� �÷��̾��� ���º��� ���ٸ�
				{
					Player->Info.HP -= Enemy->Info.Att - Player->Info.Def;//�÷��̾��� ü��-(�� ���ݷ�-�÷��̾� ����)
				}
				else//���� ���ݷ��� �÷��̾��� ���º��� ���ٸ�
					Player->Info.HP -= 1; //�÷��̾��� ü�� 1����
				break;
			case 2://���� ����
				srand(time(0)); //���� �Լ��� ��� �� ���� �ʱ�ȭ��. �Ű������� �޴� �õ尪 �̿��� �ʱ�ȭ
				int iRand = rand() % 100;//rand(): 0~32767�� ��ȯ %������ ���� 0~99���� �ϳ��� iRand�� ����
				if (iRand < 10)//10���� 1 Ȯ��
				{
					printf_s("����ġ�°Ϳ� [����] �߽��ϴ�.\n");
					free(Enemy); //�޸� ����
					Sleep(500);//�۾� ��� �Լ� Sleep(500) 0.5�� �Ű�����*1/1000��
					isBattel = 0;//��Ʋ ����
				}
				else
				{
					printf_s("����ġ�°Ϳ� [����] �߽��ϴ�.\n");
					Sleep(500);
				}
				break;
			}
		}


	}


}



//OBJECTŸ�� ������ Info���� �ʱ�ȭ ������ ,objectType���� �÷��̾ ������ �ʱ�ȭ
void InitializeObject(OBJECT* _Obj, int ObjectType)
{
	switch (ObjectType)
	{
	case TYPE_PLAYER: //�÷��̾� Ÿ���̸�
		_Obj->Info.Name = SetName();//�̸� �Է� �Լ�
		//������ �ʱ�ȭ
		_Obj->Info.Att = 10;
		_Obj->Info.Def = 10;
		_Obj->Info.EXP = 0;
		_Obj->Info.HP = 100;
		_Obj->Info.MP = 10;
		_Obj->Info.Level = 1;
		break;
	case TYPE_ENEMY://�� Ÿ���̸�
		_Obj->Info.Name = (char*)"Enemy";//Enemy�� �̸� ����
		//������ �ʱ�ȭ
		_Obj->Info.Att = 5;
		_Obj->Info.Def = 15;
		_Obj->Info.EXP = 0;
		_Obj->Info.HP = 30;
		_Obj->Info.MP = 5;
		_Obj->Info.Level = 1;
		break;
	}
}

char* SetName() //�̸� �Է� �Լ�
{
	char Buffer[128] = ""; //�� ������ �迭 ����

	printf_s("�̸� �Է� : ");
	scanf("%s", Buffer); //�迭�� �Է¹����� ����

	char* pName = (char*)malloc(strlen(Buffer) + 1); //�����ͺ��� pName�� Buffer�� ����+1��ŭ �޸� �����Ҵ�,+1�� �ϴ�����:���ڿ��� �������� �ΰ��̾���ؼ�

	strcpy(pName, Buffer);//pName�� ����Ű�� �޸𸮿� Buffer���� ������ ����

	return pName;//pName ��ȯ
}


