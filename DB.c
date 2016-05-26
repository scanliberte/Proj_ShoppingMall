#include "func.h"

void login() {
	FILE* fp;
	char ID[20];
	char PW[20];
	char cID[20];
	char cPW[20];
	int strl = 0;
	int sw = 0;

	printf("ID를 입력하세요 : ");
	scanf("%s", ID);

	if ((fp = fopen("membership.txt", "r")) == NULL) {
		printf("파일 오류");
		exit(1);
	}

	while (!feof(fp)) {	//** while1
		fscanf(fp, "%s", cID);

		if (strcmp(ID, cID) == 0) {	//** ID값 비교
			sw = TRUE;
			break;
		}
		else {
			sw = FALSE;
		}
	}	//** while1_end

	fseek(fp, 1L, SEEK_CUR);
	fgets(cPW, sizeof(cPW), fp);
	strl = strlen(cPW);	//** cPW 길이

	if (sw == FALSE) {
		printf("일치하는 ID가 없습니다.\n");
		system("pause");
	}
	else {
		while (1) {
			printf("PW를 입력하세요 : ");
			scanf("%s", PW);

			cPW[strl-1] = '\0';	//** 파일 끝에 강제 '\n'을 '\0'으로 강제 변환(비밀번호 확인을 위해)

			if (strcmp(cPW, PW) == 0) {
				//** 로그인 UI
				printf("로그인 UI\n");
				break;
			}
			else {
				printf("PW가 틀렸습니다.");
			}
		}	//** while_end
	}	//** if_end
}

void membership() {
	typedef struct human {
		//char name[20];
		char ID[20];
		char PW[20];
		//int age;
	}human;

	FILE* fp;
	human man;
	char cID[20];
	int sw = 0;

	while (1) {		//** while1
		printf("ID를 입력하세요 : ");
		scanf("%s", man.ID);

		if ((fp = fopen("membership.txt", "r")) == NULL) {
			printf("파일 오류");
			exit(1);
		}

		while (!feof(fp)) {	//** while2
			fscanf(fp, "%s", cID);

			if (strcmp(man.ID, cID) == 0) {	//** ID값 비교
				printf("중복되는 아이디가 있습니다.\n");
				sw = TRUE;
				break;
			}
			else {
				sw = FALSE;
			}
		}	//** while2_end

		if (sw == 0) {
			break;
		}
	}	//** while1_end
	fclose(fp);

	printf("PW를 입력하세요 : ");
	scanf("%s", man.PW);

	if ((fp = fopen("membership.txt", "a")) == NULL) {
		printf("파일 오류");
		exit(1);
	}

	fprintf(fp, "%s %s\n", man.ID, man.PW);

	fclose(fp);
	printf("회원가입이 되었습니다.\n");
}
