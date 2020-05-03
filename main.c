#include"schedule.h"

int select_menu(){
	int menu;
	printf("\n일정관리 프로그램\n");
	printf("====================\n");
	printf("1. 일정추가\n");
	printf("2. 일정조회\n");
	printf("3. 일정수정\n");
	printf("메뉴를 입력해 주세요: ");
	scanf("%d", &menu);
	return menu;
}

int main(){
	Schedule sch[SIZE];
	int count = 0;
	int curcount =0;
	int menu;
	while(1){	
		menu = select_menu();
		if(menu == 1){
			count += add_schedule(&sch[curcount]);
			curcount++;
		}
		else if(menu == 2){
			if(count == 0){
				printf("일정이 없습니다.\n");
				continue;
			}
			list_schedule(sch, curcount);
		}
		else if(menu == 3){
			int no = select_No(sch,curcount);
			if(no == 0){
					printf("취소되었습니다\n");
					continue;	
			}
			updata_schedule(&sch[no-1]);
		}
		else{
			printf("=======종료=======\n");
			break;
		}
}
}
