#define MAX(x1,x2) x1>x2?x1:x2
int rob(int* nums, int numsSize) {
    int dp[1000][2];
    int i;
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for(i=1;i<numsSize;++i){
        dp[i][0] = MAX(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + nums[i];
    }
    return MAX(dp[numsSize-1][0],dp[numsSize-1][1]);
}
