

/*
 递归 TLE
 存在重复计算
 如123 在12 3 和 1 2 3时 3被计算了两遍
 也有逻辑错误 比如没有处理 00 0N N0 的情况
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 1;
        if(s.size()==1)
            return 1;
        else{
            int tmp = atoi(s.substr(0,2).c_str());
            if(tmp <= 26)
                return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            else
                return numDecodings(s.substr(1));

        }
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        int *dp = new int[s.size()];
        int ret;
        dp[0] = dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2;i<=s.size();++i){
            int tmp = atoi(s.substr(i-2,2).c_str());
            if(s[i-2] == '0' && s[i-1] == '0')
                return 0;
            else if(s[i-2]=='0'){
                dp[i] = dp[i-1];
            }
            else if(s[i-1]=='0'){
                if(tmp > 26)
                    return 0;
                dp[i] = dp[i-2];
            }else{
                dp[i] = tmp <= 26 ? dp[i-1] + dp[i-2] : dp[i-1];
            }
        }
        ret = dp[s.size()];
        delete dp;
        return ret;
    }
};
