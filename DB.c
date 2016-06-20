#include "func.h"

char mID[30];
char* pID = mID;

// 에러 메세지 출력
void errorMsg(char *errMsg)
{
	printf("%s", errMsg);
	printf("Error Meassage : %s\n", mysql_error(conn));
}

// 디비 연결
int connectDB(void)
{
	char* server = "127.0.0.1";
	char* user = "root";
	char* password = "1q2w3e4r";
	char* database = "project_db";

	conn = mysql_init(NULL);
	mysql_options(conn, MYSQL_SET_CHARSET_NAME, "euckr");
	mysql_options(conn, MYSQL_INIT_COMMAND, "SET NAMES euckr");

	if (conn == NULL) {
		errorMsg("MySQL init fail\n");
		return -1;
	}
	if (!mysql_real_connect(conn, server,
		user, password, database, 3306, (char *)NULL, 0)) {
		errorMsg("MySQL connect fail\n");
		return -2;
	}
	return 0;
}

// 디비 연결 해제
void closeDB(void)
{
	if (res)
		mysql_free_result(res);
	mysql_close(conn);
}

// 쿼리 실행
int runQuery(char *query)
{
	//mysql_query(conn, "set names utf8");
	if (mysql_query(conn, query)) {
		errorMsg("MySQL Query Excute failed\n");
		exit(1);
		return -1;
	}

	res = mysql_store_result(conn);
	return 0;
}

int membership() {	//** 회원가입

	member_user();
	member_cash();
	member_point();
}
int member_user() {	//** 회원가입 user
	char cPW[30];
	char comm[100] = { "insert into user value (\"" };	//** sql 명령문
	int len, idlen, pwlen;
	int i;

	len = strlen(comm);

	printf("ID를 입력하세요 : ");
	scanf_s("%s", mID, sizeof(mID));

	idlen = strlen(mID);

	for (i = 0; i < idlen; i++) {
		comm[len + i] = mID[i];
	}

	comm[len + idlen] = '\"';
	comm[len + idlen + 1] = ',';
	comm[len + idlen + 2] = '\"';

	printf("비밀번호를 입력하세요 : ");
	scanf_s("%s", cPW, sizeof(cPW));

	pwlen = strlen(cPW);

	for (i = 0; i < pwlen; i++) {
		comm[len + idlen + i + 3] = cPW[i];
	}

	comm[len + idlen + pwlen + 3] = '\"';
	comm[len + idlen + pwlen + 4] = ')';
	comm[len + idlen + pwlen + 5] = ';';

	//printf("%s", comm);

	if (runQuery(comm)) {
		return -2;
	}
}
int member_cash() {	//** 회원가입 cash
	char com_cash[100] = { "insert into cash value (\"" };
	int len, idlen;
	int i;

	len = strlen(com_cash);
	idlen = strlen(mID);

	for (i = 0; i < idlen; i++) {
		com_cash[len + i] = mID[i];
	}

	com_cash[len + idlen] = '\"';
	com_cash[len + idlen + 1] = ',';
	com_cash[len + idlen + 2] = '0';
	com_cash[len + idlen + 3] = ')';
	com_cash[len + idlen + 4] = ';';

	if (runQuery(com_cash)) {
		return -2;
	}
}
int member_point() {	//** 회원가입 point
	char com_point[100] = { "insert into point value (\"" };
	int len, idlen;
	int i;

	len = strlen(com_point);
	idlen = strlen(mID);

	for (i = 0; i < idlen; i++) {
		com_point[len + i] = mID[i];
	}

	com_point[len + idlen] = '\"';
	com_point[len + idlen + 1] = ',';
	com_point[len + idlen + 2] = '0';
	com_point[len + idlen + 3] = ')';
	com_point[len + idlen + 4] = ';';

	if (runQuery(com_point)) {
		return -2;
	}
}

char* login() {
	char comm[100] = { "select password from user where id=\"" };
	int field;
	int len, idlen;
	char cID[30], cPW[30];
	int sw = 1;


	printf("ID를 입력해 주세요 : ");
	scanf_s("%s", cID, sizeof(cID));

	strcpy_s(currnetUserId, sizeof(cID), cID);

	if (strcmp("root", cID)) {		// 관리자인지 사용자인지 확인
		if (runQuery("select * from user")) {
			return -2;
		}

		field = mysql_num_fields(res);

		while ((row = mysql_fetch_row(res))) {
			for (int i = 0; i < field; i++) {
				if (!strcmp(cID, row[i] ? row[i] : "NULL")) {
					sw = 0;
				}
				break;
			}
			printf("\n");
		}
	}
	else {
		printf("비밀번호를 입력하세요 : ");
		scanf_s("%s", cPW, sizeof(cPW));

		if (strcmp("root", cPW)) {
			mID[0] = '2';

			return pID;
		}
		else {
			strcpy_s(mID, sizeof(cID), cID);
			return pID;
		}
	}

	if (sw == 0) {	//** 로그인 성공했을 경우
		printf("비밀번호를 입력하세요 : ");
		scanf_s("%s", cPW, sizeof(cPW));

		len = strlen(comm);
		idlen = strlen(cID);

		for (int i = 0; i < idlen; i++) {	//** comm에 id추가
			comm[len + i] = cID[i];
		}

		comm[len + idlen] = '\"';
		comm[len + idlen + 1] = ';';

		if (runQuery(comm)) {	//** 쿼리 실행
			return -2;
		}

		field = mysql_num_fields(res);

		while ((row = mysql_fetch_row(res))) {	//** 필드를 읽어온다
			for (int i = 0; i < field; i++) {	//** 필드 수 만큼
				if (!strcmp(cPW, row[i] ? row[i] : "NULL")) {	//** 비밀번호 비교
					sw = 1;
				}
				break;
			}
			printf("\n");
		}
		if (sw == 1) {
			strcpy_s(mID, sizeof(cID), cID);		//** mID에 cID를 복사한다
			printf("로그인 성공\n");
			return pID;
		}
		else {
			mID[0] = '2';
			return pID;
		}
	}
	else {
		mID[0] = '1';
		return pID;
	}
}

int member_leaveDB() {	//** 회원탈퇴
	member_leaveDB_user();
	member_leaveDB_cash();
	member_leaveDB_point();
}
int member_leaveDB_user() {
	char comm[100] = { "delete from user where id=\"" };
	int len, idlen;
	int i;

	len = strlen(comm);
	idlen = strlen(mID);

	for (i = 0; i < idlen; i++) {
		comm[len + i] = mID[i];
	}

	comm[len + idlen] = '\"';
	comm[len + idlen + 1] = ';';

	//printf("%s", comm);

	if (runQuery(comm)) {
		return -2;
	}
}
int member_leaveDB_cash() {
	char comm[100] = { "delete from cash where id=\"" };
	int len, idlen;
	int i;

	len = strlen(comm);
	idlen = strlen(mID);

	for (i = 0; i < idlen; i++) {
		comm[len + i] = mID[i];
	}

	comm[len + idlen] = '\"';
	comm[len + idlen + 1] = ';';

	//printf("%s", comm);

	if (runQuery(comm)) {
		return -2;
	}
}
int member_leaveDB_point() {
	char comm[100] = { "delete from point where id=\"" };
	int len, idlen;
	int i;

	len = strlen(comm);
	idlen = strlen(mID);

	for (i = 0; i < idlen; i++) {
		comm[len + i] = mID[i];
	}

	comm[len + idlen] = '\"';
	comm[len + idlen + 1] = ';';

	//printf("%s", comm);

	if (runQuery(comm)) {
		return -2;
	}
}


int charge_cashDB() {	//** 캐쉬 충전
	char comm[100] = { "update cash set cash=cash+" };
	char comm_1[100] = { " where id=\"" };
	char comm_2[100] = { "select cash from cash where id=\"" };
	int len, len_1, len_2, idlen, cashlen;
	char add_cash[50];

	printf("캐쉬를 얼마나 충전하시겠습니까? : ");
	scanf_s("%s", add_cash, sizeof(add_cash));

	cashlen = strlen(add_cash);	//** add_cash 길이
	len = strlen(comm);			//** comm 길이
	idlen = strlen(mID);		//** ID 길이

	for (int i = 0; i < cashlen; i++) {	//** comm에 add_cash 추가
		comm[len + i] = add_cash[i];
	}

	len = strlen(comm);
	len_1 = strlen(comm_1);

	for (int i = 0; i < len_1; i++) {	//** comm에 comm_1 추가
		comm[len + cashlen + i] = comm_1[i];
	}

	for (int i = 0; i < idlen; i++) {	//** comm에 id 추가
		comm[len + cashlen + len_1 + i] = mID[i];
	}

	comm[len + cashlen + len_1 + idlen] = '\"';
	comm[len + cashlen + len_1 + idlen + 1] = ';';


	if (runQuery(comm)) {
		return -2;
	}

	len_2 = strlen(comm_2);

	for (int i = 0; i < idlen; i++) {	//** SQL명령어 조합
		comm_2[len_2 + i] = mID[i];
	}

	comm_2[len_2 + idlen] = '\"';
	comm_2[len_2 + idlen + 1] = ';';

	if (runQuery(comm_2)) {
		return -2;
	}

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < 1; i++) {
			printf("%s님의 cash는 %s원 있습니다.", mID, row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
	system("pause");
}

int check_cash_point() {	//캐쉬 및 마일리지 확인
	char comm_cash[100] = { "select cash from cash where id=\"" };
	char comm_point[100] = { "select point from point where id=\"" };
	int len, idlen;

	len = strlen(comm_cash);	//** cash길이 구하기
	idlen = strlen(mID);		//** ID길이 구하기

	for (int i = 0; i < idlen; i++) {	//** SQL명령어 조합
		comm_cash[len + i] = mID[i];
	}

	comm_cash[len + idlen] = '\"';
	comm_cash[len + idlen + 1] = ';';

	len = strlen(comm_point);	//** point길이 구하기

	for (int i = 0; i < idlen; i++) {	//** SQL명령어 조합
		comm_point[len + i] = mID[i];
	}

	comm_point[len + idlen] = '\"';
	comm_point[len + idlen + 1] = ';';

	if (runQuery(comm_cash)) {	//** cash_query
		return -2;
	}

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < 1; i++) {
			printf("%s님의 cash는 %s원 있습니다.", mID, row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	if (runQuery(comm_point)) {	//** point_query
		return -2;
	}

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < 1; i++) {
			printf("%s님의 point는 %s원 있습니다.", mID, row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
	system("pause");
}

int spend_pointDB(int point)	// 포인트사용
{
	char temp_query[1024] = { 0, };

	sprintf_s(
		temp_query,
		sizeof(temp_query),
		"select point from point where id='%s'",
		currnetUserId);

	if (runQuery(temp_query)) {
		return -2;
	}

	row = mysql_fetch_row(res);

	while (1) {
		if (atoi(row[0]) >= point) {
			sprintf_s(
				temp_query,
				sizeof(temp_query),
				"update point set point=(point-%d) where id='%s'",
				point, currnetUserId);

			if (runQuery(temp_query)) {
				return -2;
			}
		}
		else {
			return -1;
		}
	}

	return 0;
}

int spend_cash(int total_price) {	//캐쉬사용
	char temp_query[1024] = { 0, };

	sprintf_s(
		temp_query,
		sizeof(temp_query),
		"select cash from cash where id='%s'",
		currnetUserId);

	if (runQuery(temp_query)) {
		return -2;
	}

	row = mysql_fetch_row(res);

	if (atoi(row[0]) >= total_price) {
		sprintf_s(
			temp_query,
			sizeof(temp_query),
			"update cash set cash=(cash-%d) where id='%s'",
			total_price, currnetUserId);

		if (runQuery(temp_query)) {
			return -2;
		}
	}
	else {
		return -1;
	}

	return 0;
}

int saving_point(int total_price) {	//마일리지 충전
	char temp_query[1024] = { 0, };

	sprintf_s(
		temp_query,
		sizeof(temp_query),
		"update point set point=(point+%.0f) where id='%s'",
		((float)total_price)*0.2, currnetUserId);

	if (runQuery(temp_query)) {
		return -2;
	}
}

int menuDB(int sel) {
	switch (sel) {
	case 1:
		menu_meatDB();
		selectedTable = "menu_meat";
		break;
	case 2:
		menu_fruitsDB();
		selectedTable = "menu_fruits";
		break;
	case 3:
		menu_vegetableDB();
		selectedTable = "menu_vegetable";
		break;
	case 4:
		menu_fish();
		selectedTable = "menu_fish";
		break;
	}
}

int menu_meatDB() {
	int field;

	if (runQuery("select * from menu_meat")) {
		return -2;
	}

	field = mysql_num_fields(res);

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < field; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}

int menu_fruitsDB() {
	int field;

	if (runQuery("select * from menu_fruits")) {
		return -2;
	}

	field = mysql_num_fields(res);

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < field; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}

int menu_vegetableDB() {
	int field;

	if (runQuery("select * from menu_vegetable")) {
		return -2;
	}

	field = mysql_num_fields(res);

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < field; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}

int menu_fish() {
	int field;

	if (runQuery("select * from menu_fish")) {
		return -2;
	}

	field = mysql_num_fields(res);

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < field; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}

int orderDB(int amount, char address[]) {
	char temp_query[1024] = { 0, };
	char menu_name[32] = { 0, };
	int price = 0;
	int total_price = 0;
	int use;

	sprintf_s(
		temp_query,
		sizeof(temp_query),
		"select item_name, item_value from %s where item_num=%d",
		selectedTable, selectedId);

	if (runQuery(temp_query)) {
		return -2;
	}

	row = mysql_fetch_row(res);
	strcpy_s(menu_name, sizeof(menu_name), row[0]);
	price = atoi(row[1]);

	total_price = amount * price;

	printf("포인트를 사용하시겠습니까?\n");

	if (spend_pointDB(total_price) == -1) {
		printf("포인트가 부족합니다.");
	}

	if (spend_cash(total_price)) {
		printf("캐쉬가 부족합니다!\n");
		system("pause");
		return -3;
	}

	sprintf_s(
		temp_query,
		sizeof(temp_query),
		"Insert into request "
		"(id, menu_name, amount, total_price, address) "
		"values "
		"('%s', '%s', '%d', '%d', '%s')",
		currnetUserId, menu_name, amount, total_price, address);

	if (runQuery(temp_query)) {
		return -2;
	}

	saving_point(total_price);
}

int userList() {
	int field;

	if (runQuery("select * from user")) {
		return -2;
	}

	field = mysql_num_fields(res);

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < field; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}

int addressList() {
	int field;

	if (runQuery("select * from request")) {
		return -2;
	}

	field = mysql_num_fields(res);

	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < field; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}
