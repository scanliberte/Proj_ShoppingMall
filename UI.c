#include "func.h"

char* pID;

void select_1() {
	int sel = 0, sel1 = 0;

	system("cls");

	while (1) {	//** while2
		printf("1. �α���\n");
		printf("2. ȸ������\n");
		printf("�̿��Ͻ� ��ȣ�� �Է��ϼ��� : ");
		scanf_s("%d", &sel1);

		switch (sel1) {	//** switch2
		case 1:
			system("cls");
			printf("-----------�α���-----------\n");
			pID = login();	//** DB �α��� �Լ�

			if (!strcmp(pID, "1")) {
				system("cls");
				printf("���� ���̵��Դϴ�. �α��� ȭ������ �̵��մϴ�.\n");
			}
			else if (!strcmp(pID, "2")) {
				system("cls");
				printf("��й�ȣ�� Ʋ���̽��ϴ�. �α��� ȭ������ �̵��մϴ�.\n");
			}
			else if (strcmp(pID, "root")) {
				select_2();
			}
			else {
				printf("������ ���\n");
				//������ ���
			}

			break;

		case 2:
			system("cls");
			printf("-----------ȸ������-----------\n");
			membership();	//** DB ȸ������ �Լ�
			break;
		default:
			if (sel1 == -1) {
				exit(1);
			}
			else {
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
			if (sel == -1) {
				sw = 0;
				break;
			}
			printf("�߸��Է��ϼ̽��ϴ�\n");
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

		if (sel > 0 && sel < 5) {
			menuDB(sel);
		}
		else {
			if (sel == -1) {
				printf("�ֹ��� �����ϴ�.\n");
				break;
			}
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			system("pause");
		}

		//++ �ֹ��߰� db
	}	//** end_while
	fflush(stdin);
	printf("������� �Է��ϼ��� : ");
	scanf_s("%s", address, sizeof(address));
	//fgets(address, sizeof(address), stdin);
	printf("%s", address);
	system("pause");
	//++ ����� db
}