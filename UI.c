#include "func.h"

char* pID;

void select_1() {
	int sel = 0, sel1 = 0;

	system("cls");

	while (1) {	//** while2
		printf("1. 로그인\n");
		printf("2. 회원가입\n");
		printf("이용하실 번호를 입력하세요 : ");
		scanf_s("%d", &sel1);

		switch (sel1) {	//** switch2
		case 1:
			system("cls");
			printf("-----------로그인-----------\n");
			pID = login();	//** DB 로그인 함수
			
			if (!strcmp(pID, "1")) {
				system("cls");
				printf("없는 아이디입니다. 로그인 화면으로 이동합니다.\n");
			}
			else if (!strcmp(pID, "2")) {
				system("cls");
				printf("비밀번호를 틀리셨습니다. 로그인 화면으로 이동합니다.\n");
			}
			else if (strcmp(pID, "root")) {
				select_2();
			}
			else {
				printf("관리자 모드\n");
				//관리자 모드
			}
			
			break;

		case 2:
			system("cls");
			printf("-----------회원가입-----------\n");
			membership();	//** DB 회원가입 함수
			break;
		default :
			if (sel1 == -1) {
				exit(1);
			}
			else {
				printf("잘못입력하셨습니다\n");
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
		printf("----------로그인 성공------------\n");
		printf("1.주문\n");
		printf("2.캐쉬충전\n");
		printf("3.캐쉬 및 마일리지 확인\n");
		printf("4.회원탈퇴\n");
		printf("번호를 입력하세요(-1 = 로그인화면) : ");
		scanf_s("%d", &sel);

		switch (sel) {
		case 1:
			system("cls");
			printf("-----------주문-----------\n");
			//** 메뉴판 db
			//** 주문 db
			order();
			//spend_point();
			break;
		case 2:
			system("cls");
			printf("-----------캐쉬충전-----------\n");
			charge_cashDB();
			break;
		case 3:
			system("cls");
			printf("-----------캐쉬 및 마일리지 확인-----------\n");
			check_cash_point();
			break;
		case 4:
			system("cls");
			printf("-----------회원탈퇴-----------\n");
			member_leaveDB();
			printf("회원탈퇴 되었습니다.\n");
			printf("로그인 화면으로 이동합니다.\n");
			system("pause");
			sel = -1;
			break;
		default:
			if (sel == -1) {
				sw = 0;
				break;
			}
			printf("잘못입력하셨습니다\n");
			break;
		}
	}
}

void order() {
	int sel = 0;
	char address[100];

	while (1) {
		printf("----------category----------\n");
		printf("1. 육류\n");
		printf("2. 과일\n");
		printf("3. 채소\n");
		printf("4. 생선\n");
		printf("번호를 입력하세요 (-1 = 뒤로) : ");
		scanf_s("%d", &sel);

		if (sel > 0 && sel < 5) {
			menuDB(sel);
		}
		else {
			if (sel == -1) {
				printf("주문을 끝냅니다.\n");
				break;
			}
			printf("잘못입력하셨습니다.\n");
			system("pause");
		}
		
		//++ 주문추가 db
	}	//** end_while
	fflush(stdin);
	printf("배송지를 입력하세요 : ");
	scanf_s("%s", address, sizeof(address));
	//fgets(address, sizeof(address), stdin);
	printf("%s", address);
	system("pause");
	//++ 배송지 db
}
