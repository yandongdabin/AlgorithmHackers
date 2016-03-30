
/*本题动态规划基本思想，对于每个s中的字符有两个选择 删去还是不删去
dp[s][t] 用于记录 S中 0-s的子串转换为 T中 0-t 子串的次数

dp[s][t] = dp[s-1][t-1] + dp[s-1][t]| if S[s]=T[t]  前一部分表示不删 后半部分表示删去
           dp[s-1][t]               | if S[s]!=T[t] 因为不相等只能删去

*/
int numDistinct(char* s, char* t) {
    //一直在调这个数组的大小 终于试到了...
    int dp[11000][51];
    int ret;
    int sl = strlen(s);
    int tl = strlen(t);
    int i,j;
    dp[0][0] = 1;
    for(i=1;i<=sl;++i){
        dp[i][0] = 1;
    }
    for(j=1;j<=tl;++j){
        dp[0][j] = 0;
    }
    for(i=1;i<=sl;++i){
        for(j=1;j<=tl;++j){
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[sl][tl];
}

