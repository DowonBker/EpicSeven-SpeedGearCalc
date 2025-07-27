#ifndef CALC_H
#define CALC_H

#define MAX_SPD 35  //속도 최댓값이 34, spd_perc[34]가 속도 34를 가르키기위해 1을 더한 값을 선언

void enh_proc_lgd(double perc[MAX_SPD]);
void enh_proc_epic(double perc[MAX_SPD]);
void reforge(double perc[MAX_SPD], int times);
void enhance_lgd(double perc[MAX_SPD]);
void enhance_epic(double perc[MAX_SPD]);
void copy_array(double dest[MAX_SPD], double src[MAX_SPD]);

#endif