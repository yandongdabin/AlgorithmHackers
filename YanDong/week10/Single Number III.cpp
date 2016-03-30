class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = 0;
        for(int i = 0;i<nums.size();++i){
            _xor ^= nums[i];
        }
        // xor = a ^ b
        //a与b不相同 我们知道xor中必定有一个 1 ，那么对应的位上 a与 b异号 以此可以区分 a与b
        _xor &= -_xor;
        vector<int> ret(2,0);
        for(int i = 0;i<nums.size();++i){
            if(_xor & nums[i]){
                ret[0] ^= nums[i];
            }else{
                ret[1] ^= nums[i];
            }
        }
        return ret;
    }
};
