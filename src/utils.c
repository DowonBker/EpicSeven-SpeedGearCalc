#include <math.h>
#include "utils.h"

//이항분포
int facto(int n){
    static const int fac[]={
        1, 1, 2, 6, 24, 120
    };
    return fac[n];
}

int binomi_coeffi(int n, int k){
    return facto(n)/(facto(k)*facto(n-k));
}

double binomi_probabil(int n, int k, double p){
    return binomi_coeffi(n,k)*pow(p,k)*pow(1-p,n-k);
}