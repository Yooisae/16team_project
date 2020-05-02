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

int main(){
	schedule sch[SIZE];
	int conut = 0;
	int curcount =0;
	while(1){	
		if(menu == 1){
			count += add_schedule(&sch[curcount]);
			curcount++;
		}
		else if(menu == 2){
			if(count == 0){
				printf("일정이 없습니다.");
				continue;
			}
			read_schedule(sch[curcount]);
		}
		else{
			printf("=======종료=======");
			break;
		}		
	}
}
