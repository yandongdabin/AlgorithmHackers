/**
AC 20ms

dp[i][j] 表示 以 i,j为右下角的最大 square
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        if(!n) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxRet = 0;
        for(int i = 0;i<m;++i){
            dp[i][0] = matrix[i][0] - '0';
            maxRet = max(dp[i][0],maxRet);
        }
        for(int i = 0;i<n;++i){
            dp[0][i] = matrix[0][i] - '0';
            maxRet = max(dp[0][i],maxRet);
        }
        for(int i = 1;i<m;++i){
            for(int j = 1;j<n;++j){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + 1;
                    if(dp[i][j] > maxRet)
                        maxRet = dp[i][j];

                }
            }
        }
        return maxRet * maxRet;
    }
};

/**换成 O（n）空间消耗
12ms
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        if(!n) return 0;
        int pre = 0;
        /*多加一列和一行 使得 第一列不区别对待*/
        vector<int> dp(n+1,0);
        int maxRet = 0;
        for(int i = 0;i<m;++i){
            for(int j = 1;j<=n;++j){
                int tmp = dp[j];
                if(matrix[i][j-1] == '1'){
                    dp[j] = min(min(dp[j-1],dp[j]),tmp) + 1;
                    maxRet = max(dp[j],maxRet);

                }
                else{
                    dp[j] = 0;
                }
                pre = tmp;
            }
        }
        return maxRet * maxRet;
    }
};
