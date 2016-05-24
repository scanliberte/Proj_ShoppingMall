void select() {
	int sel = 0, sel1 = 0;

	printf("1. 사용자 모드\n");
	printf("2. 관리자 모드\n");
	printf("이용하실 번호를 입력하세요 : ");
	scanf("%d", &sel);

	switch (sel) {
	case 1:
		system("cls");
		printf("-----------사용자 모드-----------\n");
		printf("1. 로그인\n");
		printf("2. 회원가입\n");
		printf("이용하실 번호를 입력하세요 : ");
		scanf("%d", &sel1);

		switch (sel1) {
		case 1:
			system("cls");
			printf("-----------로그인-----------\n");
			break;
		case 2:
			system("cls");
			printf("-----------회원가입-----------\n");
			break;
		}
		break;

	case 2:
		system("cls");
		printf("-----------관리자 모드-----------\n");
		break;

	default:
		printf("잘못입력하셨습니다.\n");
		break;
	}
}
