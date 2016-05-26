#include "func.h"

void select() {
	int sel = 0, sel1 = 0;

	while (1) {
		system("cls");
		printf("1. 사용자 모드\n");
		printf("2. 관리자 모드\n");
		printf("이용하실 번호를 입력하세요. (-1 = 종료) : ");
		scanf("%d", &sel);

		if (sel == -1) {
			exit(1);
		}

		switch (sel) {	//** switch1
		case 1:
			system("cls");
			printf("-----------사용자 모드-----------\n");
			printf("1. 로그인\n");
			printf("2. 회원가입\n");
			printf("이용하실 번호를 입력하세요. (-1 = 뒤로) : ");
			scanf("%d", &sel1);

			if (sel1 == -1) {
				break;
			}

			switch (sel1) {	//** switch2
			case 1:
				system("cls");
				printf("-----------로그인-----------\n");
				login();	//** DB 로그인 함수
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

		default:
			printf("잘못입력하셨습니다.\n");
			break;
		}	//** switch1_end
	}	//** while_end
}

