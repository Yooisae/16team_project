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
	getchar();
	scanf(" %[^\n]", p->s_name);
	printf("일정 시작일을 입력해 주세요: ");
	getchar();
	scanf("%d", &p->s_date);
	printf("일정 종료일을 입력해 주세요: ");
	getchar();
	scanf("%d", &p->e_date);
	printf("일정의 중요한 정도를 입력해 주세요(1~5): ");
	getchar();
	scanf("%d", &p->importance);
	p->complete = 0;
	return 1;
}

void read_schedule(Schedule p){
	char comp[10]="complete";
	if(p.complete == 0)
		strcpy(comp,"ongoing");
		
	printf("%-22s %-15d %-17d %-5d %s\n", p.s_name, p.s_date, p.e_date, p.importance, comp);
}

void list_schedule(Schedule p[], int count){
	//printf("\n===>해야 하는 일정<===\n");
	printf("NO.| 일정이름		시작일		종료일		중요도	완료유무\n");
	printf("------------------------------------------------------------------------\n");
	for(int i = 0 ; i <count ; i++){
		printf("%2d.| ",(i+1));
		if(p[i].complete==-1/*||p[i].complete==1*/)
			continue;
		else
			read_schedule(p[i]);
	}
	/*printf("\n\n=============================================================================\n\n");
	printf("===>완료된 일정<===\n");
	printf("NO.| 일정이름		시작일		종료일		중요도	완료유무\n");
	printf("------------------------------------------------------------------------\n");
	for(int i = 0 ; i <count ; i++){
		printf("%2d.| ",(i+1));
		if(p[i].complete==-1||p[i].complete==0)
			continue;
		else
			read_schedule(p[i]);
	}*/
	printf("\n");
}

int select_No(Schedule *p, int count){
    int no;
    list_schedule(p,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    return no;
}

int updata_schedule(Schedule *p){
	
	printf("일정 이름을 입력해 주세요: ");
	getchar();
	scanf("%[^\n]s", p->s_name);
	printf("일정 시작일을 입력해 주세요: ");
	getchar();
	scanf("%d", &p->s_date);
	printf("일정 종료일을 입력해 주세요: ");
	getchar();
	scanf("%d", &p->e_date);
	printf("일정의 중요한 정도를 입력해 주세요(1~5): ");
	getchar();
	scanf("%d", &p->importance);
	p->complete = 0;
	printf("=>수정되었습니다!");
	return 1;
}

