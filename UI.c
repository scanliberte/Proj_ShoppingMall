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
				select_1();
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

void select_1() {
	int sel = 0;

	while (1) {
		system("cls");
		printf("----------로그인 성공------------\n");
		printf("1.주문\n");
		printf("2.캐쉬충전\n");
		printf("3.캐쉬 및 마일리지 확인\n");
		printf("4.회원탈퇴\n");
		printf("번호를 입력하세요(-1 = 로그인화면) : ");
		scanf("%d", &sel);

		if (sel == -1) {
			break;
		}

		switch (sel) {
		case 1:
			system("cls");
			printf("-----------주문-----------\n");
			//** 메뉴판 db
			//** 주문 db
			order();
			spend_point();
			break;
		case 2:
			system("cls");
			printf("-----------캐쉬충전-----------\n");
			charge_cash();
			break;
		case 3:
			system("cls");
			printf("-----------캐쉬 및 마일리지 확인-----------\n");
			break;
		case 4:
			system("cls");
			printf("-----------회원탈퇴-----------\n");
			break;
		default:
			printf("잘못입력하셨습니다\n");
			break;
		}
	}
	
}

void order() {
	int sel = 0;
	char address[100];

	while (1) {
		printf("주문하실 번호를 입력하세요(-1=나가기) : ");
		scanf("%d", &sel);

		if (sel == -1) {
			printf("주문을 끝냅니다.\n");
			break;
		}
		//++ 주문추가 db
	}
	printf("배송지를 입력하세요 : ");
	scanf("%s", address);
	//++ 배송지 db
}

void spend_point() {
	char sel = 'n';

	printf("마일리지를 사용하시겠습니까?(y/n)");
	if (sel == 'y') {
		printf("마일리지를 사용하셨습니다.\n");
		//++ 마일리지 차감db
	}
	else {
		printf("마일리지를 사용 안하셨습니다.\n"); 
	}
}

void charge_cash() {
	int cash = 0;

	printf("캐쉬를 얼마나 충전하시겠습니까?");
	scanf("%d", &cash);
	//++ 캐쉬 db
}

void check_point() {
	//++ 캐쉬 마일리지 db
	printf("고객님의 마일리지는 %d원 입니다\n");
}

void member_leave() {
	char sel = 'n';
	
	printf("회원탈퇴 하시겠습니까?(y/n)");
	scanf("%c", &sel);

	if (sel == 'y') {
		//++ 회원탈퇴 db
	}
}
