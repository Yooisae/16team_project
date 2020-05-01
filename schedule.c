#include"schedule.h"

/*typedef struct{
	char s_name[20];//스케줄 이름
	int s_date;//시작일
	int e_date;//종료일
	int importance;//중요도
	bool complete;//완료유무
}Schedule;*/
int add_schedule(Schedule *p){
	printf("일정 이름을 입력해 주세요: ");
	scanf("%[^\n]", p->s_name);
	getchar();
	printf("일정 시작일을 입력해 주세요: ");
	scanf("%d", &p->s_date);
	printf("일정 종료일을 입력해 주세요: ");
	scanf("%d", &p->e_date);
	printf("일정의 중요한 정도를 입력해 주세요(1~5): ");
	scanf("%d", &p->e_date);
	return 1;
}
