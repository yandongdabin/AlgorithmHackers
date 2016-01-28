/*从后往前算
dp[i][j] = dp[i+1][j]+dp[i][j+1]
dp[m][1-n]=1
dp[1-m][n]=1
*/
int uniquePaths(int m, int n) {
    int dp[101][101];
    dp[m][n] = 0;
    int i,j;
    for(i=0;i<=n;++i){
        dp[m][i] = 1;
    }
    for(i=0;i<=m;++i){
        dp[i][n] = 1;
    }
    for(i = m-1;i>=1;--i){
        for(j=n-1;j>=1;--j){
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }
    }
    return dp[1][1];
}
