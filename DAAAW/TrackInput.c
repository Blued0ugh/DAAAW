#include "TrackInput.h"
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "ForWindow.h"

enum ColorType {
	BLACK = 0,
	darkBLUE=1,	//1
	DarkGreen=2,	//2
	darkSkyBlue=3,    //3
	DarkRed=4,
	DarkPurple=5,	//5
	DarkYellow=6,	//6
	GRAY=7,		//7
	DarkGray=8,	//8
	BLUE=9,		//9
	GREEN=10,		//10
	SkyBlue=11,	//11
	RED=12,		//12
	PURPLE=13,		//13
	YELLOW=14,		//14
	WHITE=15		//15
} COLOR;

typedef struct  Tracks {
	char arr[1000];
	int num;
	char title[15]; //�Ǻ��̸�
	 
	//�Ǻ��̸� ó�� ĭ���� �׻� ^�� �־ ���߿� �ڸ��� �ұ� \0

};

void InputHelp()
{
	int daww = 0;
	char titl[15];
	char forserch[20];
	int forpoint=0;

	FILE* fp;


	printf("DAAAW�� ���� ���� ȯ���մϴ�!\n��� : \n1)���� �Է� \n2)���� �Է� \n4)���� �ҷ����� \n5)����\n\n>>");
	scanf_s("%d",&daww);
	forpoint = 0;

	switch (daww)
	{
	case 1:
		printf("�Ǻ� �̸� �Է� : [�ִ� 10��]\n>>");
		scanf("%s", titl);
		while (strlen(titl) > 10)
		{
			printf("�ٽ� �Է��ϼ���>>");
			scanf("%s", titl);
			
		}
		
		/*for (int i = 0; i < 20; i++)
		{
			if (titl[i] == "\0")
				forpoint = i;
			else forserch[i] = titl[i];
		}*/

		strcpy(forserch, titl);
		forpoint = strlen(forserch);
		forserch[forpoint++] = '.';
		forserch[forpoint++] = 't';
		forserch[forpoint++] = 'x';
		forserch[forpoint++] = 't';
		forserch[forpoint] = '\0';
		//���ڿ��� �������� .txt�� �߰��Ѵ�.

		fp = fopen(forserch, "r");

		if (fp == NULL) {
			printf("%d", forpoint);
			printf("%s", forserch);
			textcolor(DarkGray);
			printf("%s ", titl);
			printf("���� ���� ����\n");
			textcolor(WHITE);
		}
		else {
			textcolor(DarkGray);
			printf("%s ", titl);
			printf("�Ǻ� ���� ����\n\n");
			textcolor(WHITE);
		}


		char arr[304];
		char* pStr = fgets(arr, 301, fp);
		textcolor(DarkGray);
		printf("�Ǻ� ���: \n");
		textcolor(WHITE);
		int i = 0;
		while (pStr[i] != NULL)
		{
			printf("%c", pStr[i]);
			if ((i+1) % 30==0)printf("\n");
			i++;
		}

		//printf("1)���� - 2)���� �ҷ����� - 3)���� ����� - 4)���� ����ϱ� - 5)���� ���߱�- 6)�����ϱ�");
		int mods;
		mods=SelectProcess();
		switch (mods)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			MusicEdit(arr);
			break;
		case 6:
			break;
		}



		/// <summary>
		/// arr�� �Ǻ��� ����Ǿ������ �̰ɷ� ���� �Űܾ��� 
		/// </summary>

		fclose(fp);
		break;
	default:
		break;

	}
}
//�������� �ҷ����� ���ϻ���
//������� ���Ǹ��� ��������
//����

void MusicEdit(char* music)
{
	int x=0, y=10;//������
	int arrPoint = 1;
	goto_xy(0,24);
	textcolor(darkSkyBlue);
	printf("[1:��] [2:��] [3:��] [4:��] [5:��] [6:��] [7:��]");
	goto_xy(0, 25);
	printf("[8:��Ÿ�� ���̱�] [9:��Ÿ�� ���߱�] [0:���� �Ϸ��ϱ�] [q:�� ���� �ø���] [w:�� ���� ª��]");
	goto_xy(0, 26);
	printf("[����Ű�� ���� �̵��ϼ���]");

	//���������� ������ ��
	//xy�Է¹ޱ� ȣ��
	//�����Է����� ȣ����� ��ġ�� ���� ���ڸ� �ٲ۴�
	//�迭�� ���ڿ��� �ٲ۴� 
	
	//ù��° �ڸ��� �̵� 
	//
	goto_xy(x, y);
	while (arrPoint != 0)
	{
		arrPoint = ArrPoint(music);
	}

	

}

int ArrPoint(char* music)
{
	static int Oc = 0, HowLong = 1;
	//ù��° �ڸ��� �̵� 
	// music [arrX+ (arrY-14)]
	int WhenEnds=11;

	

	while (WhenEnds != 0)
	{
		textcolor(WHITE);

		WhenEnds = MusicCursor(music,&Oc,&HowLong);

	}


}


