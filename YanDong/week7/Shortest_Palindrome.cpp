class Solution {
public:
    /*Manacher算法*/
    /*http://blog.csdn.net/ggggiqnypgjg/article/details/6645824*/
    string shortestPalindrome(string s) {
        string ss(2 * s.length(),'0');
        int i = 1;
        for(char c:s){
            ss[i++] = c;
            ss[i++] = '#';
        }
        vector<int> p(ss.length(),0);
        int max_id = 0;
        int res = 0;
        for(int i = 0;i<ss.length();++i){
            if(p[max_id] + max_id > i){
                p[i] = min(p[2*max_id-i],p[max_id] + max_id-i);
            }else{
                p[i] = 1;
            }
            while(ss[i+p[i]] == ss[i-p[i]]) ++p[i];
            if(p[max_id] + max_id < i + p[i]){max_id = i;}
            if(i == p[i]) res = max(i,res);
        }
        int pos = res;
        cout<<pos<<endl;
        string tmp = "";
        for(int i = s.length()-1;i >= pos;i--){
            tmp.push_back(s[i]);
        }
        return tmp + s;

    }
};
/*还有一种 通过  s + '#' + reverse_s 字符串进行KMP算法的，暂时还没看*/
/*http://www.tuicool.com/articles/Uv6byyU*/
