int maxProfit(int* prices, int pricesSize) {
    if(pricesSize <= 1){
        return 0;
    }
    int i;
    int ret = 0;
    for(i = 1;i<pricesSize;++i){
        int tmp = prices[i] - prices[i-1];
        if(tmp > 0 ){
            ret += tmp;
        }
    }
    return ret;
}
