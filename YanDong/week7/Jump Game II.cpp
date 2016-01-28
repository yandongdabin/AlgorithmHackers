class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        int res = 0;
        int canReach = 0;
        for(int i = 0;i<nums.size();++i){
            if( i > maxReach ){
                res += 1;
                canReach = maxReach;
            }
            maxReach = max(maxReach,nums[i]+i);
        }
        return res;
    }
};
