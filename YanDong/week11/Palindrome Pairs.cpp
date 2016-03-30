class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        unordered_map<string,int> m;
        int i = 0;
        for(auto &s:words){
            m[s] = i ++;
        }
        for(int i = 0;i<words.size();++i){
            for(int j = 0;j<=words[i].length();++j){
                string tmp1 = words[i].substr(0,j);
                string tmp2 = words[i].substr(j);
                string rtmp1 = tmp1;
                string rtmp2 = tmp2;
                reverse(rtmp1.begin(),rtmp1.end());
                reverse(rtmp2.begin(),rtmp2.end());
                if(m.find(rtmp1) != m.end() && m[rtmp1] != i && tmp2 == rtmp2){
                    ret.push_back({i,m[rtmp1]});
                }
                //j ==0 时会有重复解 因为 如果 abc cba 那么 abc的值会和 cba的值重复 所以j !=0 可以抑制这种重复解
                if(j!=0 && m.find(rtmp2)!=m.end() && m[rtmp2]!=i && tmp1 == rtmp1){
                    ret.push_back({m[rtmp2],i});
                }
            }

        }
        return ret;
    }
};
