#include<stdio.h>
#include<malloc.h>
int maxProfit(int* prices, int pricesSize) {
    if(pricesSize <= 1){
        return 0;
    }
    int opt[100000];

    int lowest = prices[0];
    int i;
    opt[0] = 0;
    for(i = 1;i<pricesSize;++i){
        int tmp = prices[i] - lowest;
        opt[i] = tmp < opt[i-1] ?  opt[i-1]:tmp;
        lowest = lowest < prices[i] ? lowest : prices[i];

    }
    int maxmize = prices[pricesSize-1];
    int opt1[100000];
    opt1[pricesSize-1] = 0;
    for(i = pricesSize-2;i>=0;--i){
        int tmp = maxmize - prices[i];
        maxmize = prices[i] > maxmize ? prices[i]:maxmize;
        opt1[i] = tmp > opt1[i+1] ? tmp:opt1[i+1];
    }
    int ret = 0;
    for(i=0;i<pricesSize;++i){
        int tmp = opt[i] + opt1[i];
        ret = ret > tmp ? ret : tmp;
    }
    return ret;
}
int main(){
    int *arr = (int *)malloc(sizeof(int)*2);
    arr[0] = 2;
    arr[1] = 1;
    maxProfit(arr,2);
    return 0;
}
