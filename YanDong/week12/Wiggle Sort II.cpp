
/**native 先排一下序 然后大小交叉放上*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> backup(nums);
        sort(backup.begin(),backup.end());
        for(int i = nums.size()-1,j = 0,k=i/2 + 1;i>=0;--i){
            nums[i] = backup[i & 1 ? k++ : j++];
        }
    }
};
/**最优解  不排序 首先找出 nums中的中间元素 然后以中间元素为基准进行交叉放置
没看懂
**/
