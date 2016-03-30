class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> ans;
        permute(ret,nums,ans,0);
        return ret;

    }
    void permute(vector<vector<int> > &ret,vector<int>& nums,vector<int> &ans,int cnt){
        if(cnt == nums.size()){
            ret.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();++i){
            int ok = 1;
            for(int j=0;j<ans.size();++j){
                if(ans[j] == nums[i]) ok=0;
            }
            if(ok){
                ans.push_back(nums[i]);
                permute(ret,nums,ans,cnt+1);
                ans.pop_back();
            }
        }
    }
};
