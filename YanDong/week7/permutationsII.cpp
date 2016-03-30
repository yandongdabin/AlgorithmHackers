class Solution {
private:
    bool visited[1000];
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> ans;
        memset(visited,false,sizeof(visited));
        permute(ret,nums,ans,0);
        return ret;

    }
    void permute(vector<vector<int> > &ret,vector<int>& nums,vector<int> &ans,int cnt){
        if(cnt == nums.size()){
            ret.push_back(ans);
            return;
        }
        /*排序后防止 每次选取某一位置元素的时候 防止 以相同的元素开始递归*/
        for(int i=0;i<nums.size();++i){
            if(visited[i]) continue;
            if(i!=0 && nums[i]==nums[i-1] && !visited[i-1])
                continue;
            ans.push_back(nums[i]);
            visited[i] = true;
            permute(ret,nums,ans,cnt+1);
            visited[i] = false;
            ans.pop_back();
        }
    }
};
