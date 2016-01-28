int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int dp[101][101];
    int m = obstacleGridRowSize;
    int n = obstacleGridColSize;
    int i,j;
    /*初始化部分发生了变化*/
    dp[m][n] = obstacleGrid[m-1][n-1]==1?0:1;
    for(i=m-1;i>=1;--i){
        dp[i][n] = obstacleGrid[i-1][n-1]==1?0:dp[i+1][n];
    }
    for(i=n-1;i>=1;--i){
        dp[m][i] = obstacleGrid[m-1][i-1]==1?0:dp[m][i+1];
    }
    for(i=m-1;i>=1;--i){
        for(j=n-1;j>=1;--j){
            if(obstacleGrid[i-1][j-1] == 1){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
            printf("%d %d :%d\n",i,j,dp[i][j]);
        }
    }
    return dp[1][1];
}
