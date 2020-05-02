#include"schedule.h"

int select_menu(){
	int menu;
	printf("일정관리 프로그램\n");
	printf("====================\n");
	printf("1. 일정추가\n");
	printf("2. 일정조회\n");
	printf("메뉴를 입력해 주세요: ");
	scnaf("%d", &menu);
	return menu;
}

