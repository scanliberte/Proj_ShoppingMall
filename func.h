#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


//** UI 함수들
void select();			//** 처음 선택문
void select_1();		//** 로그인 후 선택문
void order();			//** 주문
void spend_point();		//** 마일리지 사용여부
void charge_cash();		//** 캐쉬 충전
void check_point();		//** 캐쉬 및 마일리지 확인
void member_leave();	//** 회원탈퇴

//** DB 함수들
void login();
void membership();
