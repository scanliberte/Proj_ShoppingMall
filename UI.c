#include "func.h"

char* pID;

void select_1() {
	int sel = 0, sel1 = 0;

	system("cls");

	while (1) {	//** while2
		system("cls");
		gotoxy(gX,gY);
		printf("----------����ȭ���Դϴ�----------");
		gotoxy(gX, gY+2);
		printf("1. �α���");
		gotoxy(gX, gY+3);
		printf("2. ȸ������");
		gotoxy(gX, gY+4);
		printf("�̿��Ͻ� ��ȣ�� �Է��ϼ��� : ");
		scanf_s("%d", &sel1);

		switch (sel1) {	//** switch2
		case 1:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------�α���-----------\n");
			pID = login();	//** DB �α��� �Լ�

			if (!strcmp(pID, "1")) {
				system("cls");
				gotoxy(gX, gY+2);
				printf("���� ���̵��Դϴ�. �α��� ȭ������ �̵��մϴ�.\n");
				system("pause");
			}
			else if (!strcmp(pID, "2")) {
				system("cls");
				gotoxy(gX, gY+2);
				printf("��й�ȣ�� Ʋ���̽��ϴ�. �α��� ȭ������ �̵��մϴ�.\n");
				system("pause");
			}
			else if (strcmp(pID, "root")) {
				select_2();
			}
			else {
				gotoxy(gX, gY);
				printf("������ ���\n");
				//������ ���
				root();
			}

			break;

		case 2:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------ȸ������-----------\n");
			membership();	//** DB ȸ������ �Լ�
			break;
		default:
			if (sel1 == -1) {
				exit(1);
			}
			else {
				gotoxy(gX, gY+2);
				printf("�߸��Է��ϼ̽��ϴ�\n");
				break;
			}
		}	//** switch2_end
	}	//** while_end2
}

void select_2() {
	int sel = 0;
	int sw = 1;

	while (sw) {
		system("cls");
		gotoxy(gX, gY);
		printf("----------�α��� ����------------\n");
		gotoxy(gX, gY+2);
		printf("1.�ֹ�\n");
		gotoxy(gX, gY+3);
		printf("2.ĳ������\n");
		gotoxy(gX, gY+4);
		printf("3.ĳ�� �� ���ϸ��� Ȯ��\n");
		gotoxy(gX, gY+5);
		printf("4.ȸ��Ż��\n");
		gotoxy(gX, gY+6);
		printf("��ȣ�� �Է��ϼ���(-1 = �α���ȭ��) : ");
		scanf_s("%d", &sel);

		switch (sel) {
		case 1:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------�ֹ�-----------\n");
			//** �޴��� db
			//** �ֹ� db
			order();
			//spend_point();
			break;
		case 2:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------ĳ������-----------\n");
			charge_cashDB();
			break;
		case 3:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------ĳ�� �� ���ϸ��� Ȯ��-----------\n");
			check_cash_point();
			break;
		case 4:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------ȸ��Ż��-----------\n");
			member_leaveDB();
			gotoxy(gX, gY+2);
			printf("ȸ��Ż�� �Ǿ����ϴ�.\n");
			gotoxy(gX, gY+3);
			printf("�α��� ȭ������ �̵��մϴ�.\n");
			system("pause");
			sel = -1;
			break;
		default:
			if (sel == -1) {
				sw = 0;
				break;
			}
			gotoxy(gX, gY+2);
			printf("�߸��Է��ϼ̽��ϴ�\n");
			break;
		}
		if (sel == -1) {
			sw = 0;
			break;
		}
	}
}

void order() {
	int sel = 0;
	int amount = 0;
	char address[100] = { 0, };
	int i=0;

	while (1) {
		gotoxy(gX, gY);
		printf("----------category----------\n");
		gotoxy(gX, gY+2);
		printf("1. ����\n");
		gotoxy(gX, gY+3);
		printf("2. ����\n");
		gotoxy(gX, gY+4);
		printf("3. ä��\n");
		gotoxy(gX, gY+5);
		printf("4. ����\n");
		gotoxy(gX, gY + 6);
		printf("��ȣ�� �Է��ϼ��� (-1 = �ڷ�) : ");
		scanf_s("%d", &sel);

		if (sel > 0 && sel < 5) {
			i = menuDB(sel);
			break;
		} 
		else if (sel == -1) {
			system("cls");
			gotoxy(gX, gY+2);
			printf("�ֹ��� �����ϴ�.\n");
			break;
		} 
		else {
			gotoxy(gX, gY+2);
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			system("pause");
		}

		//++ �ֹ��߰� db
	}	//** end_while
	gotoxy(gX, gY + 2 + i + 1);
	printf("��� ǰ���� �����Ͻðڽ��ϱ� : ");
	scanf_s("%d", &selectedId);

	gotoxy(gX, gY + 2 + i + 2);
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &amount);

	gotoxy(gX, gY + 2 + i + 3);
	printf("������� �Է��ϼ��� : ");
	getchar();
	gets_s(address, sizeof(address));
	
	orderDB(amount, address);
}

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int root() {
	int sel = 0;
	int sw = 1;

	while (sw) {
		system("cls");
		gotoxy(gX, gY);
		printf("----------������ ���------------\n");
		gotoxy(gX, gY + 2);
		printf("1. ȸ����� ���\n");
		gotoxy(gX, gY + 3);
		printf("2. �ֹ� ��Ȳ\n");
		gotoxy(gX, gY + 4);
		printf("3. ����\n");
		gotoxy(gX, gY + 5);
		printf("��ȣ�� �Է��ϼ���(-1 = �α���ȭ��) : ");
		scanf_s("%d", &sel);

		switch (sel) {
		case 1:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------ȸ�����-----------\n");
			memberlist();
			//
			break;
		case 2:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------�ֹ� ��Ȳ-----------\n");
			orderlist();
			//
			break;
		case 3:
			system("cls");
			gotoxy(gX, gY);
			printf("-----------����-----------\n");
			income();
			//
			break;
		default:
			if (sel == -1) {
				sw = 0;
				break;
			}
			gotoxy(gX, gY + 2);
			printf("�߸��Է��ϼ̽��ϴ�\n");
			break;
		}
		if (sel == -1) {
			sw = 0;
			break;
		}
	}
}