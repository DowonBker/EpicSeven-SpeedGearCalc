#include <stdio.h>
#include "calc.h"
#include "utils.h"

void enh_proc_lgd(double perc[MAX_SPD]){
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

void enh_proc_epic(double perc[MAX_SPD]){
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

void reforge(double perc[MAX_SPD], int times){  //제련
	if(times>4)
        times=4;
    for(int i=(MAX_SPD-1-times);i>0;i--){
        perc[i+times]=perc[i];
        perc[i]=0;
    }
}

void enh_lgd(int enh_times, double perc[MAX_SPD]){
    for(int i=0;i<enh_times;i++)
        enh_proc_lgd(perc);
    reforge(perc, enh_times);

    for(int i=0;i<MAX_SPD;i++)
        perc[i]*=binomi_probabil(5,enh_times,0.25);
}

void enhance_lgd(double perc[MAX_SPD]){
    double perc2[MAX_SPD], perc3[MAX_SPD], perc4[MAX_SPD], perc5[MAX_SPD];
    copy_array(perc2, perc);
    copy_array(perc3, perc);
    copy_array(perc4, perc);
    copy_array(perc5, perc);

    enh_lgd(2, perc2);
    enh_lgd(3, perc3);
    enh_lgd(4, perc4);
    enh_lgd(5, perc5);

    double sum[MAX_SPD];
    for(int i=0;i<MAX_SPD;i++)
        sum[i]=perc2[i]+perc3[i]+perc4[i]+perc5[i];
    
    for(int i=15;i<MAX_SPD;i++)
        if(sum[i]*100>=0.0005)
            printf("속도가 %d 일 확률: %.3lf%%\n", i, sum[i]*100);
    
}

void enh_epic(int enh_times, double perc[MAX_SPD]){
    for(int i=0;i<enh_times;i++)
        enh_proc_epic(perc);
    reforge(perc, enh_times);

    for(int i=0;i<MAX_SPD;i++)
        perc[i]*=binomi_probabil(5,enh_times,0.25);
}

void enhance_epic(double perc[MAX_SPD]){

    double perc3[MAX_SPD], perc4[MAX_SPD];
    copy_array(perc3, perc);
    copy_array(perc4, perc);

    for(int i=0;i<3;i++)
        enh_proc_epic(perc3);
    reforge(perc3, 3);
    
    for(int i=0;i<MAX_SPD;i++)
        perc3[i]*=binomi_probabil(3,3,0.333333)*0.75;

    for(int i=0;i<4;i++)
        enh_proc_epic(perc4);
    reforge(perc4, 4);
    
    for(int i=0;i<MAX_SPD;i++)
        perc4[i]*=binomi_probabil(3,3,0.333333)*0.25;

    double sum[MAX_SPD];
    for(int i=0;i<MAX_SPD;i++)
        sum[i]=perc3[i]+perc4[i];

    for(int i=15;i<MAX_SPD;i++)
        if(sum[i]*100>=0.0005)
            printf("속도가 %d 일 확률: %.3lf%%\n", i, sum[i]*100);
}

void copy_array(double perc2[MAX_SPD], double perc1[MAX_SPD]){
    for(int i=0;i<MAX_SPD;i++)
        perc2[i]=perc1[i];
}
