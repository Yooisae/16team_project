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
	printf("일정 시작일을 입력해 주세요(yyyy mm dd): ");
	for(int i = 0 ; i < 3 ; i++){
		getchar();
		scanf("%d", &p->s_date[i]);
	}
	printf("일정 종료일을 입력해 주세요(yyyy mm dd): ");
	for(int i = 0 ; i < 3 ; i++){
		getchar();
		scanf("%d", &p->e_date[i]);
	}
	printf("일정의 중요한 정도를 입력해 주세요(1~5): ");
	getchar();
	scanf("%d", &p->importance);
	p->complete = 0;
	return 1;
}

void read_schedule(Schedule p){
	char comp[10]="complete";
	if(p.complete == 0){
		strcpy(comp,"ongoing");
	}
	printf("%-20s %-4d-%2d-%-7d %-4d-%2d-%-9d %-5d %s\n", p.s_name, p.s_date[0], p.s_date[1], p.s_date[2], p.e_date[0], p.e_date[1], p.e_date[2], p.importance, comp);
}

void list_schedule(Schedule p[], int count){
	printf("NO.| 일정이름		시작일		종료일		중요도	완료유무\n");
	printf("------------------------------------------------------------------------\n");
	for(int i = 0 ; i <count ; i++){
		if(p[i].complete==-1)
			continue;
		else{
			printf("%2d.| ",(i+1));
			read_schedule(p[i]);
		}
	}
	printf("\n");
}

int select_No(Schedule *p, int count){//수정이나 삭제 함수 등에서 원하는 일정을 선택하여 바꾸기 위한 함수
    int no;//선택할 번호
    list_schedule(p,count);//일정 리스트 함수를 불러와서 보여주기 위한 코드
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
	 printf("\n");
    return no;//선택한 번호를 return
}

int updata_schedule(Schedule *p){//스케줄을 수정하기 위한 함수
	
	printf("일정 이름을 입력해 주세요 : ");
	getchar();
	scanf("%[^\n]s", p->s_name);//일정 이름 받기
	printf("일정 시작일을 입력해 주세요(yyyy mm dd): ");
	for(int i = 0 ; i < 3 ; i++){
		getchar();
		scanf("%d", &p->s_date[i]);//날짜 년,월,일을 배열을 통해 받기
	}
	printf("일정 종료일을 입력해 주세요(yyyy mm dd): ");
	for(int i = 0 ; i < 3 ; i++){
		getchar();
		scanf("%d", &p->e_date[i]);
	}
	printf("일정의 중요한 정도를 입력해 주세요(1~5): ");
	getchar();
	scanf("%d", &p->importance);//중요도 입력
	p->complete = 0;
	printf("=>수정되었습니다!\n");
	printf("\n");
	return 1;
}

int delete_schedule(Schedule *p){
	p->complete=-1;
	printf("==>삭제됨!\n");
	return 0;
}

void saveFile(Schedule p[], int count){
	FILE *fp;
	fp = fopen("schedule.txt", "wt");
	for(int i = 0 ; i < count ; i++){
		fprintf(fp,"%s\n %d %d %d %d %d %d %d %d ", p[i].s_name, p[i].s_date[0], p[i].s_date[1], p[i].s_date[2], p[i].e_date[0], p[i].e_date[1], p[i].e_date[2], p[i].importance, p[i].complete);
	}
	fclose(fp);
	printf("==>저장됨<==\n"); 

}

int loadFile(Schedule p[]){
	int count=0;
	FILE *fp;
	fp=fopen("schedule.txt","rt");
	if(fp==NULL){
		printf("=>파일이 없습니다.\n");
		return 0;
	}
	for(;;count++){
		fscanf(fp,"%[^\n] %d %d %d %d %d %d %d %d", p[count].s_name, &p[count].s_date[0], &p[count].s_date[1], &p[count].s_date[2], &p[count].e_date[0], &p[count].e_date[1], &p[count].e_date[2], &p[count].importance, &p[count].complete);
		if(feof(fp)) break;
}
	fclose(fp);
	printf("=>로딩성공!\n");
	return count;
} 

void find(Schedule p[],int count){
	char f_name[20];
	int confi = 0;
	printf("\n==>찾을 일정의 이름을 입력해 주세요: ");
	getchar();
	scanf("%[^\n]", f_name);
	printf("\nNO.| 일정이름		시작일		종료일		중요도	완료유무\n");
	printf("------------------------------------------------------------------------\n");
	for(int i = 0 ; i < count ; i++){
		if(strstr(p[i].s_name,f_name)!=NULL && p[i].complete != -1){
			printf("%2d.| ",(i+1));
			read_schedule(p[i]);
			confi++;
		}
		
	}
	if(confi==0){	
		printf("==>검색된 일정 없이 없습니다.<==\n");
	}
}

void sortedbyDate(Schedule p[],int count ){
	Schedule temp;
	for(int i=0; i<count; i++){
		for(int j=i+1; j<count; j++){		
			if(p[i].e_date[0]>=p[j].e_date[0]&&p[i].e_date[1]>=p[j].e_date[1]&&p[i].e_date[2]>p[j].e_date[2]){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	printf("날짜에 따라 출력된 일정입니다.\n\n");
	list_schedule(p,count);
	
}

void sortedbyImportance(Schedule p[],int count){
	Schedule temp;
	for(int i=0; i<count; i++){
		for(int j=i+1; j<count; j++){		
			if(p[i].importance<p[j].importance){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	printf("중요도에 따라 출력된 일정입니다.\n\n");
	printf("\n");
	list_schedule(p,count);
}


int complete(Schedule p[]){
	p->complete=1;
	printf("일정이 완료되었습니다!\n");
	printf("\n");
	return 1;
}

int processivity(Schedule p[],int count){
	int p_count=0;
	float proc;
	for(int i=0; i<count; i++){
		if(p[i].complete==1){
			p_count++;
		}
	}
	proc=((float)p_count/count)*100;	
	printf("총 %d개의 일정 중에 %d개의 일정을 완료하셨습니다.\n",count,p_count);
	printf("현재 전체 일정의 진행도는 %0.f%% 입니다\n",proc);
	for(int i=0;i<102;i++)
		printf("-");
	printf("\n|");
	for(int i =0 ; i<proc ; i++)
		printf("@");	
	for(int i = proc ; i<100;i++)
		printf(" ");
	printf("|\n");
	for(int i=0;i<102;i++)
		printf("-");
	
	return 0;
}
