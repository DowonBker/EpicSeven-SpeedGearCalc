/*
	에픽세븐 속도템 강화 확률 계산 프로그램
	https://page.onstove.com/epicseven/kr/view/7902451 기준
*/
#include <stdio.h>
#include <math.h>

void enh_proc_lgd();
void enh_proc_epic();
void reforge();
void enhance();
void enhance_lgd();
void enhance_epic();

//이항분포
int facto();
int binomi_coeffi();
double binomi_probabil();


int main(void){
	
	printf("에픽세븐 속도템 강화 확률 계산 프로그램\n\n");
	
	int item_class;
	printf("강화할 아이템이\n전설템이면 1, 영웅템이면 2를 입력해주세요\n");
	scanf("%d", &item_class);
	
	if(item_class!=1 && item_class!=2){
		printf("잘못된 입력입니다\n");
		return 0;
	}
	
	double spd_perc[35]={0};	//속도 최댓값이 34
	
	int s0;
	printf("초기 속도값을 입력해주세요\n");
	scanf("%d", &s0);
	spd_perc[s0]=1;
	
	if(item_class==1 && (s0<2 || s0>5)){
		printf("잘못된 입력입니다\n");
		return 0;
	}
	if(item_class==2 && (s0<1 || s0>4)){
		printf("잘못된 입력입니다\n");
		return 0;
	}
    printf("\n\n");
	
    if(item_class==1)
        enhance_lgd(spd_perc);
    else
        enhance_epic(spd_perc);
	
	return 0;
}


void enh_proc_lgd(double perc[35]){
	for(int i=25;i>0;i--){
		if(perc[i]>0){
			perc[i+2]+=perc[i]*0.33223;
			perc[i+3]+=perc[i]*0.33223;
			perc[i+4]+=perc[i]*0.33223;
			perc[i+5]+=perc[i]*0.00332;
			perc[i]=0;
		}
	}
}

void enh_proc_epic(double perc[35]){
	for(int i=16;i>0;i--){
		if(perc[i]>0){
			perc[i+1]+=perc[i]*0.03833;
			perc[i+2]+=perc[i]*0.34843;
			perc[i+3]+=perc[i]*0.34843;
			perc[i+4]+=perc[i]*0.26481;
			perc[i]=0;
		}
	}
}

void reforge(double perc[35], int times){    //제련
	if(times>4)
        times=4;
    for(int i=(34-times);i>0;i--){
        perc[i+times]=perc[i];
        perc[i]=0;
    }
}

void enh_lgd(int enh_times, double perc[35]){
    for(int i=0;i<enh_times;i++)
        enh_proc_lgd(perc);
    reforge(perc, enh_times);

    for(int i=0;i<35;i++)
        perc[i]*=binomi_probabil(5,enh_times,0.25);
}

void enhance_lgd(double perc[35]){
    double perc2[35];
    for(int i=0;i<35;i++)
        perc2[i]=perc[i];
    double perc3[35];
    for(int i=0;i<35;i++)
        perc3[i]=perc[i];
    double perc4[35];
    for(int i=0;i<35;i++)
        perc4[i]=perc[i];
    double perc5[35];
    for(int i=0;i<35;i++)
        perc5[i]=perc[i];

    int enh_times=2;
    enh_lgd(enh_times, perc2);
    enh_times++;
    enh_lgd(enh_times, perc3);
    enh_times++;
    enh_lgd(enh_times, perc4);
    enh_times++;
    enh_lgd(enh_times, perc5);

    double sum[35];
    for(int i=0;i<35;i++)
        sum[i]=perc2[i]+perc3[i]+perc4[i]+perc5[i];
    
    for(int i=15;i<35;i++)
        if(sum[i]*100>=0.0005)
            printf("속도가 %d 일 확률: %.3lf%%\n", i, sum[i]*100);
    
}

void enh_epic(int enh_times, double perc[35]){
    for(int i=0;i<enh_times;i++)
        enh_proc_epic(perc);
    reforge(perc, enh_times);

    for(int i=0;i<35;i++)
        perc[i]*=binomi_probabil(5,enh_times,0.25);
}

void enhance_epic(double perc[35]){

    double perc3[35];
    for(int i=0;i<35;i++)
        perc3[i]=perc[i];
    double perc4[35];
    for(int i=0;i<35;i++)
        perc4[i]=perc[i];

    for(int i=0;i<3;i++)
        enh_proc_epic(perc3);
    reforge(perc3, 3);
    
    for(int i=0;i<35;i++)
        perc3[i]*=binomi_probabil(3,3,0.333333)*0.75;

    for(int i=0;i<4;i++)
        enh_proc_epic(perc4);
    reforge(perc4, 4);
    
    for(int i=0;i<35;i++)
        perc4[i]*=binomi_probabil(3,3,0.333333)*0.25;

    double sum[35];
    for(int i=0;i<35;i++)
        sum[i]=perc3[i]+perc4[i];

    for(int i=15;i<35;i++)
        if(sum[i]*100>=0.0005)
            printf("속도가 %d 일 확률: %.3lf%%\n", i, sum[i]*100);
}


//이항분포
int facto(int n){
    int ans=1;
    for(int i=2;i<=n;i++)
        ans*=i;
    return ans;
}

int binomi_coeffi(int n, int k){
    return facto(n)/(facto(k)*facto(n-k));
}

double binomi_probabil(int n, int k, double p){
    return binomi_coeffi(n,k)*pow(p,k)*pow(1-p,n-k);
}
