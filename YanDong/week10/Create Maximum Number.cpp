/**
基本思路：假设 nums1放入了k1个数 nums2放入了k2个数
枚举 k1、k2 得到最大值
子问题为对一个数组取 k1 个数，保证这k1个数的顺序不变 且组成的数字最大
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        int len1 = nums1.size();
        int len2 = nums2.size();
        // intuitively  k-len2 < k < len1 再考虑边界条件就是下面的值
        for(int k1 = max(k-len2,0);k1 <= min(len1,k);++k1){
            ret = max(ret,mergeV(subMax(nums1,k1),subMax(nums2,k-k1)));
        }
        return ret;
    }
    vector<int> subMax(vector<int> &nums,int k){

        vector<int> ret;
        // 我们需要舍弃 drop个元素  think [5,5,2] 2
        int drop = nums.size() - k;
        for(int num:nums){
            while(drop && ret.size() && ret.back()< num ){
                drop --;
                ret.pop_back();
            }
            ret.push_back(num);
        }
        //考虑 [6 7 5] 0
        ret.resize(k);
        return ret;
    }
    /*借鉴大神的解法*/
    vector<int> mergeV(vector<int> nums1,vector<int> nums2){
        vector<int> ret;
        while(nums1.size() + nums2.size()){
            //max 可能不会返回引用
            vector<int> &m = nums1 > nums2 ? nums1 : nums2;
            ret.push_back(m[0]);
            m.erase(m.begin());
        }
        return ret;
    }
};
