#include "func.h"

char* pID;

void select_1() {
	int sel = 0, sel1 = 0;

	while (1) {	//** while1
		system("cls");
		printf("1. 사용자 모드\n");
		printf("2. 관리자 모드\n");
		printf("이용하실 번호를 입력하세요. (-1 = 종료) : ");
		scanf_s("%d", &sel);

		if (sel == -1) {
			exit(1);
		}

		while (1) {	//** while2
			switch (sel) {	//** switch1
			case 1:
				system("cls");
				printf("-----------사용자 모드-----------\n");
				printf("1. 로그인\n");
				printf("2. 회원가입\n");
				printf("이용하실 번호를 입력하세요. (-1 = 뒤로) : ");
				scanf_s("%d", &sel1);

				switch (sel1) {	//** switch2
				case 1:
					system("cls");
					printf("-----------로그인-----------\n");
					pID = login();	//** DB 로그인 함수
					select_2();
					break;

				case 2:
					system("cls");
					printf("-----------회원가입-----------\n");
					membership();	//** DB 회원가입 함수
					break;
				}	//** switch2_end
				break;

			case 2:
				system("cls");
				printf("-----------관리자 모드-----------\n");
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
			printf("잘못입력하셨습니다\n");
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
		printf("1. 육류\n");
		printf("2. 과일\n");
		printf("3. 채소\n");
		printf("4. 생선\n");
		printf("번호를 입력하세요 (-1 = 뒤로) : ");
		scanf_s("%d", &sel);

		if (sel == -1) {
			printf("주문을 끝냅니다.\n");
			break;
		}

		if (sel > 0 && sel < 5) {
			menuDB(sel);
		}
		else {
			printf("잘못입력하셨습니다.\n");
			system("pause");
		}
		
		//++ 주문추가 db
	}	//** end_while

	printf("배송지를 입력하세요 : ");
	scanf_s("%s", address);
	//++ 배송지 db
}