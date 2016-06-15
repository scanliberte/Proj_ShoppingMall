#include <stdio.h>
#include <mysql.h>

MYSQL_RES *res;
MYSQL_ROW row;
MYSQL *conn;

// 에러 메세지 출력
void errorMsg(char *errMsg)
{
	printf("t%s", errMsg);
	printf("nntError Meassage : %sn", mysql_error(conn));
}

// 디비 연결
int connectDB(void)
{
	char *server = "127.0.0.1";
	char *user = "root";
	char *password = "1q2w3e4r";
	char *database = "project_db";

	conn = mysql_init(NULL);
	mysql_options(conn, MYSQL_SET_CHARSET_NAME, "euckr");
	mysql_options(conn, MYSQL_INIT_COMMAND, "SET NAMES euckr");
	
	if (conn == NULL) {
		errorMsg("MySQL init fail");
		return -1;
	}
	if (!mysql_real_connect(conn, server,
		user, password, database, 3306, (char *)NULL, 0)) {
		errorMsg("MySQL connect fail");
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
		errorMsg("MySQL Query Excute failed");
		return -1;
	}

	res = mysql_store_result(conn);
	return 0;
}

int main(void)
{
	int field;
	int i;
	char recv[100];
	if (connectDB() < 0) {
		return -1;
	}
	//mysql_set_character_set(conn, "utf8");
	
	if (runQuery("select * from fish")) {
		return -2;
	}

	field = mysql_num_fields(res);

	while ((row = mysql_fetch_row(res))) {
		for (i = 0; i < field; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	printf("MySQL Client Version: %s\n", mysql_get_client_info());

	closeDB();

	return 0;
}

