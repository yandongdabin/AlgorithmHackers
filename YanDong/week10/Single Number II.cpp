/* int 类型为 32 位所以可以通过 统计每位出现的数目
最后每位对3 取模得到
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32] = {0};
        int ret = 0;
        for(int j = 0;j<32;++j){
             for(int i =0;i<nums.size();++i){
                /*bit[j] += nums[i] & (1<<j) 可能会出错 在有负数的时候*/
                if(nums[i] & (1<<j)){
                    bit[j] += 1;
                }

            }
            if(bit[j] % 3){
                ret |= (1<<j);
            }

        }
        return ret;
    }
};

/**
用三个变量分别统计 每一位上 1 出现数目 为 1次 2次，3次的情况
http://blog.csdn.net/ahero_happy/article/details/39178811
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0,two=0,three=0;
        for(int i = 0;i<nums.size();++i){
            two = two | one & nums[i];
            one ^= nums[i];
            three = one & two;
            //取模
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};
