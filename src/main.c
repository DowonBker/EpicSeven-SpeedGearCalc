/*
	에픽세븐 속도템 강화 확률 계산 프로그램
	https://page.onstove.com/epicseven/kr/view/7902451 기준
*/
#include <stdio.h>
#include "calc.h"

int main(void){
	
	printf("에픽세븐 속도템 강화 확률 계산 프로그램\n\n");
	
	int item_class;
	printf("강화할 아이템이\n전설템이면 1, 영웅템이면 2를 입력해주세요\n");
	
    if(scanf("%d", &item_class) != 1 || (item_class != 1 && item_class != 2)){
		printf("잘못된 입력입니다\n");
		return 0;
	}
	
	
	int s0;
	printf("초기 속도값을 입력해주세요\n");
	if (scanf("%d", &s0) != 1){
        printf("잘못된 입력입니다\n");
        return 0;
    }
	
	if(item_class==1 && (s0<2 || s0>5)){
		printf("잘못된 입력입니다\n");
		return 0;
	}
	if(item_class==2 && (s0<1 || s0>4)){
		printf("잘못된 입력입니다\n");
		return 0;
	}

	double spd_perc[MAX_SPD]={0};
	spd_perc[s0]=1;

    printf("\n\n");
	
    if(item_class==1)
        enhance_lgd(spd_perc);
    else
        enhance_epic(spd_perc);
	
	return 0;
}