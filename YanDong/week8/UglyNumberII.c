#define MIN(x1,x2,x3) x1>x2?(x2>x3?x3:x2):(x1>x3?x3:x1)

// 4ms AC
/*
list1: 1 1*2 2*2 3*2 ...  list1[n] = nthUglyNumber*2
list2: 1 1*3 2*3 3*3 ...  list1[n] = nthUglyNumber*3
list3: 1 1*5 2*5 3*5 ...  list1[n] = nthUglyNumber*5
*/
int nthUglyNumber(int n) {
    int i;
    int p1=1,p2=1,p3=1;
    int dp[1000];
    dp[1] = 1;
    for(i=1;i<=n;i++){
        dp[i] = MIN(dp[p1] * 2,dp[p2] * 3,dp[p3] * 5);
        if(dp[i] == dp[p1] * 2)
            p1 += 1;
        if(dp[i] == dp[p2] * 3)
            p2 += 1;
        if(dp[i] == dp[p3] * 5)
            p3 += 1;
    }
    return dp[n];
}
int main(){
    return 0;
}
