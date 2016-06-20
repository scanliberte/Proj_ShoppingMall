#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include <mysql.h>

MYSQL_RES *res;
MYSQL_ROW row;
MYSQL *conn;

#define TRUE 1
#define FALSE 0
#define gX 45
#define gY 5

char currnetUserId[32];
char* selectedTable;
int selectedId;

//** UI 함수들
void gotoxy(int x, int y);
void select_1();		//** 처음 선택문
void select_2();		//** 로그인 후 선택문
void order();			//** 주문
int root();

//** DB 함수들
void errorMsg(char *errMsg);	//** 에러 메세지 출력
int connectDB(void);			//** DB 연결
void closeDB(void);				//** DB 연결 해제
int runQuery(char *query);		//** 쿼리 실행

								// 회원가입시 자동으로 테이블에 초기화된 레코드를 추가시킨다.
int membership();		//** 회원가입
int member_user();		//** 유저테이블에 레코드 추가
int member_cash();		//** 캐시테이블에 레코드 추가
int member_point();		//** 포인트테이블에 레코드 추가

char* login();			//** 로그인
int orderDB(int amount, char address[]);			//** 주문
int spend_pointDB(int point);	//** 마일리지 사용여부
int charge_cashDB();	//** 캐쉬 충전
int check_cash_point();	//** 캐쉬 및 마일리지 확인
int saving_point(int total_price);	//** 포인트 적립
int spend_cash(int total_price);	//** 캐시삭감

int member_leaveDB();		//** 회원탈퇴
int member_leaveDB_user();	//** 회원탈퇴_user
int member_leaveDB_cash();	//** 회원탈퇴_cash
int member_leaveDB_point();	//** 회원탈퇴_point

int menuDB(int sel);
int menu_meatDB();		//** 메뉴판_meat
int menu_fruitsDB();	//** 메뉴판_fruits
int menu_vegetableDB();	//** 메뉴판_vegetable
int menu_fish();		//** 메뉴판_fish

int memberlist();		//** 회원목록 출력
int orderlist();		//** 주문목록 출력
int income();			//** 정산