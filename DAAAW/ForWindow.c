#include <Windows.h>
#include "ForWindow.h"
#include <stdio.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#include <stdbool.h>
#include "TrackInput.h"

enum ColorType {
    BLACK = 0,
    darkBLUE = 1,	//1
    DarkGreen = 2,	//2
    darkSkyBlue = 3,    //3
    DarkRed = 4,
    DarkPurple = 5,	//5
    DarkYellow = 6,	//6
    GRAY = 7,		//7
    DarkGray = 8,	//8
    BLUE = 9,		//9
    GREEN = 10,		//10
    SkyBlue = 11,	//11
    RED = 12,		//12
    PURPLE = 13,		//13
    YELLOW = 14,		//14
    WHITE = 15		//15
} COLOR;

void goto_xy(int x, int y)
{
	COORD pos={ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}




int ModselectCursor()
{
    int x=0, y=23;

    int SelectNum=0;
	// ����Ű �Է¹ޱ�
    char c;
    while (1) {
        if (_kbhit()) {               // 2. while���ȿ��� Ű���� ������ �� if���� ����ȴ�.
            c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�. 
            if (c == -32) {           // 4. -32�� �ԷµǸ�
                c = _getch();        // 5. ���� �� 00�� �Ǻ��Ͽ� �¿���� ���
                switch (c) {        //27���Ͱ� ������
                case LEFT:
                    goto_xy(x, y);
                    PrintNotSelect(x, y);
                    if (x != 0&&y!=27)x -= 12;
                    else x = 24;
                    goto_xy(x, y);
                    SelectNum=PrintSelect(x, y);

                    break;
                case RIGHT:
                    goto_xy(x, y);
                    PrintNotSelect(x, y);
                    if (x != 24&&y!=27)x += 12;
                    else x = 0;
                    if (y == 27)x = 0;
                    goto_xy(x, y);
                    SelectNum = PrintSelect(x, y);

                    break;
                case UP:
                    goto_xy(x, y);
                    PrintNotSelect(x, y);
                    if (y != 23)y -= 2;
                    else y = 27;
                    if (y == 27)x = 0;
                    goto_xy(x, y);
                    SelectNum = PrintSelect(x, y);
                    break;
                case DOWN:
                    goto_xy(x, y);
                    PrintNotSelect(x, y);
                    if (y != 27)y += 2;
                    else
                    {
                        y = 23;
                        x = 0;
                    }
                    if (y == 27 && x != 0) x = 0;
                    goto_xy(x, y);
                    SelectNum = PrintSelect(x, y);
                    break;

                }
                
            }
           if (c == 32)
                break;
        }
    }

    return SelectNum;
}

int Selectshow()
{
    goto_xy(0, 23);
    int x = 0, y = 23;
    int SelectNum = 0;
    SelectNum=ModselectCursor();
    return SelectNum;


}
int PrintSelect(int x, int y)
{
    // 0 1 2 
    // 3 4 5 
    // 6

    textcolor(BLUE);
    switch (y)
    {
    case 23:

        if (x == 0) { printf("��������"); return 0; }
        else if (x == 12) { printf("�ҷ�����"); return 1; }
        else {printf("���ϻ���"); return 2;}
        break;
    case 25: 
        if (x == 0) {printf("�������"); return 3; }
        else if (x == 12){ printf("���Ǹ���"); return 4; }
        else {printf("��������"); return 5;
        }
        break;
    case 27:
        if (x == 0)
        {
            printf("���α׷� ����"); return 6;
        
        }
        break;
    }
}

int PrintNotSelect(int x, int y)
{
    textcolor(SkyBlue);
    switch (y)
    {
    case 23:

        if (x == 0) printf("��������");
        else if (x == 12) printf("�ҷ�����");
        else printf("���ϻ���");
        break;
    case 25:
        if (x == 0) printf("�������");
        else if (x == 12) printf("���Ǹ���");
        else printf("��������");
        break;
    case 27:
        if (x == 0)
            printf("���α׷� ����");
        break;
    }
}


int SelectProcess()
{
    printf("\n");

    int ModSelect = 0;
    //printf("1)���� - 2)���� �ҷ����� - 3)���� ����� - 4)���� ����ϱ� - 5)���� ���߱�- 6)�����ϱ�");
    // ���� �ҷ����� ����� ����ϱ� ���߱� �����ϱ�
    // �������� �ʰ� �ҷ����ų� �� ������ ������ ��, �ڵ�������� �ʽ��ϴ�.
    textcolor(SkyBlue);
    printf("\n\n��������    �ҷ�����    ���ϻ���\n");//����� �׻� 4ĭ
    printf("\n�������    ���Ǹ���    ��������\n");//-> ������� - ���Ǹ��� �� ���²� �����ͼ� �ϰ����� 
    printf("\n���α׷� ����\n\n");
    textcolor(DarkGray);
    printf("SPACE Ű�� �����ϼ���");
    textcolor(WHITE);

    ModSelect=Selectshow();

    goto_xy(0, 28);
    textcolor(DarkGray);
    switch (ModSelect)
    {
    case 0:

        printf("�������� ���õ�");
        return 0;
        break;
    case 1:
        printf("�ҷ����� ���õ�"); 
        return 1;
        break;
    case 2:
        printf("���ϻ��� ���õ�");
        return 2;
        break;
    case 3:
        printf("������� ���õ�");
        return 3;
        break;
    case 4:
        printf("���Ǹ��� ���õ�");
        return 4;
        break;
    case 5:
        printf("���α׷��� �����մϴ�.");
        return 5;
        break;
    }

}


int MusicCursor(char* music, int* Oc, int* HowLong)
{

    int x = 0, y = 10;


    // ����Ű �Է¹ޱ�
    char c;
    while (1) {
        if (_kbhit()) {               // 2. while���ȿ��� Ű���� ������ �� if���� ����ȴ�.
            c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�. 
            if (c == -32) {           // 4. -32�� �ԷµǸ�
                c = _getch();        // 5. ���� �� 00�� �Ǻ��Ͽ� �¿���� ���
                switch (c) {        //27���Ͱ� ������
                case LEFT:
                    
                    
                    if (x - 1 > 0)
                        x--;

                    goto_xy(x,y);
                    printf("����");


                    break;
                case RIGHT:
                    printf("����");
                    break;
                case UP:
                    printf("����");
                    break;
                case DOWN:
                    printf("�Ʒ���");
                    break;

                }

            }
            else 
            {
                switch (c)
                {
                case 48:
                    //����
                    return 0;
                    break;
                case 49:
                    //��
                    //music[*x + (*y - 14)] = "C";
                    return 1;
                    break;
                case 50:
                    //��
                    //music[*x + (*y - 14)] = "D";
                    return 2;
                    break;
                case 51:
                    //��
                    //music[*x + (*y - 14)] = "E";
                    return 3;
                    break;
                case 52:
                    //��
                    //music[*x + (*y - 14)] = "F";
                    return 4;
                    break;
                case 53:
                    //��
                    //music[*x + (*y - 14)] = "G";
                    return 5;
                    break;
                case 54:
                    //��
                    //music[*x + (*y - 14)] = "A";
                    return 6;
                    break;
                case 55:
                    //��
                    //music[*x + (*y - 14)] = "B";
                    return 7;
                    break;
                case 56:
                    //��Ÿ�� �ø���
                    if (*Oc == 0) *Oc = 1;
                    else if (*Oc == 2) *Oc = 1;
                    return 8;
                    break;
                case 57:
                    //��Ÿ�� ������
                    if (*Oc == 0) *Oc = 2;
                    else if (*Oc == 1) *Oc = 2;
                    return 9;
                    break;
                case 81:
                    //������ ���
                    if (*HowLong != 4) *HowLong += 1;
                    else *HowLong = 1;
                    break;
                case 87:
                    if (*HowLong != 1) *HowLong -= 1;
                    else *HowLong = 4;
                    //������ ª��
                    break;
                }


                // if (*Oc == 0) music[*x + (*y - 12)] = '=';
               // else if (*Oc == 1)  music[*x + (*y - 12)] = '+';
               // else  music[*x + (*y - 12)] = '-';

                //if (*HowLong == 1) music[*x + (*y - 13)] = '1';
               // else if (*HowLong == 2)  music[*x + (*y - 13)] = '2';
               // else if(*HowLong==3) music[*x + (*y - 13)] = '3';
               // else  music[*x + (*y - 13)] = '4';

               // printf("%c%c%c", music[*x + (*y - 14)], music[*x + (*y - 13)], music[*x + (*y - 12)]);

            }
           
        }
    }

}

