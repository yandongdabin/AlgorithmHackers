int maxProfit(int* prices, int pricesSize) {
    if(pricesSize <= 1){
        return 0;
    }
    int lowest = prices[0];
    int i;
    int ret = 0;
    for(i = 1;i<pricesSize;++i){
        int tmp = prices[i] - lowest;
        if(tmp > ret ){
            ret = tmp;
        }
        lowest = prices[i] < lowest ? prices[i] : lowest;
    }
    return ret;
}
