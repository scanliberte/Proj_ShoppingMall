#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mysql.h>

MYSQL_RES *res;
MYSQL_ROW row;
MYSQL *conn;

#define TRUE 1
#define FALSE 0

char currnetUserId[32];
char* selectedTable;
int selectedId;

//** UI �Լ���
void select_1();		//** ó�� ���ù�
void select_2();		//** �α��� �� ���ù�
void order();			//** �ֹ�
						//void spend_point();		//** ���ϸ��� ��뿩��
						//void charge_cash();		//** ĳ�� ����
						//void check_point();		//** ĳ�� �� ���ϸ��� Ȯ��
						//void member_leave();	//** ȸ��Ż��

						//** DB �Լ���
void errorMsg(char *errMsg);	//** ���� �޼��� ���
int connectDB(void);			//** DB ����
void closeDB(void);				//** DB ���� ����
int runQuery(char *query);		//** ���� ����

								// ȸ�����Խ� �ڵ����� ���̺� �ʱ�ȭ�� ���ڵ带 �߰���Ų��.
int membership();		//** ȸ������
int member_user();		//** �������̺� ���ڵ� �߰�
int member_cash();		//** ĳ�����̺� ���ڵ� �߰�
int member_point();		//** ����Ʈ���̺� ���ڵ� �߰�

char* login();			//** �α���
int orderDB();			//** �ֹ�
int spend_pointDB();	//** ���ϸ��� ��뿩��
int charge_cashDB();	//** ĳ�� ����
int check_cash_point();	//** ĳ�� �� ���ϸ��� Ȯ��

int member_leaveDB();		//** ȸ��Ż��
int member_leaveDB_user();	//** ȸ��Ż��_user
int member_leaveDB_cash();	//** ȸ��Ż��_cash
int member_leaveDB_point();	//** ȸ��Ż��_point

int menuDB(int sel);
int menu_meatDB();		//** �޴���_meat
int menu_fruitsDB();	//** �޴���_fruits
int menu_vegetableDB();	//** �޴���_vegetable
int menu_fish();		//** �޴���_fish