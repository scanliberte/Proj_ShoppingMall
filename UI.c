#include "func.h"

char* pID;

void select_1() {
	int sel = 0, sel1 = 0;

	while (1) {	//** while1
		system("cls");
		printf("1. ����� ���\n");
		printf("2. ������ ���\n");
		printf("�̿��Ͻ� ��ȣ�� �Է��ϼ���. (-1 = ����) : ");
		scanf_s("%d", &sel);

		if (sel == -1) {
			exit(1);
		}

		while (1) {	//** while2
			switch (sel) {	//** switch1
			case 1:
				system("cls");
				printf("-----------����� ���-----------\n");
				printf("1. �α���\n");
				printf("2. ȸ������\n");
				printf("�̿��Ͻ� ��ȣ�� �Է��ϼ���. (-1 = �ڷ�) : ");
				scanf_s("%d", &sel1);

				switch (sel1) {	//** switch2
				case 1:
					system("cls");
					printf("-----------�α���-----------\n");
					pID = login();	//** DB �α��� �Լ�
					select_2();
					break;

				case 2:
					system("cls");
					printf("-----------ȸ������-----------\n");
					membership();	//** DB ȸ������ �Լ�
					break;
				}	//** switch2_end
				break;

			case 2:
				system("cls");
				printf("-----------������ ���-----------\n");
				break;
			}	//** switch1_end
			
			if (sel1 == -1) {
				break;
			}
		}	//** while_end2
	}	//** while_end1
}

void select_2() {
	int sel = 0;

	while (1) {
		system("cls");
		printf("----------�α��� ����------------\n");
		printf("1.�ֹ�\n");
		printf("2.ĳ������\n");
		printf("3.ĳ�� �� ���ϸ��� Ȯ��\n");
		printf("4.ȸ��Ż��\n");
		printf("��ȣ�� �Է��ϼ���(-1 = �α���ȭ��) : ");
		scanf_s("%d", &sel);

		switch (sel) {
		case 1:
			system("cls");
			printf("-----------�ֹ�-----------\n");
			//** �޴��� db
			//** �ֹ� db
			order();
			//spend_point();
			break;
		case 2:
			system("cls");
			printf("-----------ĳ������-----------\n");
			charge_cashDB();
			break;
		case 3:
			system("cls");
			printf("-----------ĳ�� �� ���ϸ��� Ȯ��-----------\n");
			check_cash_point();
			break;
		case 4:
			system("cls");
			printf("-----------ȸ��Ż��-----------\n");
			member_leaveDB();
			printf("ȸ��Ż�� �Ǿ����ϴ�.\n");
			printf("�α��� ȭ������ �̵��մϴ�.\n");
			system("pause");
			sel = -1;
			break;
		default:
			printf("�߸��Է��ϼ̽��ϴ�\n");
			break;
		}

		if (sel == -1) {
			break;
		}
	}
}

void order() {
	int sel = 0;
	char address[100];

	while (1) {
		printf("----------category----------\n");
		printf("1. ����\n");
		printf("2. ����\n");
		printf("3. ä��\n");
		printf("4. ����\n");
		printf("��ȣ�� �Է��ϼ��� (-1 = �ڷ�) : ");
		scanf_s("%d", &sel);

		if (sel == -1) {
			printf("�ֹ��� �����ϴ�.\n");
			break;
		}

		if (sel > 0 && sel < 5) {
			menuDB(sel);
		}
		else {
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			system("pause");
		}
		
		//++ �ֹ��߰� db
	}	//** end_while

	printf("������� �Է��ϼ��� : ");
	scanf_s("%s", address);
	//++ ����� db
}