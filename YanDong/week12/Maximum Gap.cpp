/**排序
O(nlgn)
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        sort(nums.begin(),nums.end());
        int ret = 0;
        int pre = nums[0];
        for(int i = 1;i<nums.size();++i){
            int tmp = nums[i] - pre;
            if(tmp > ret)
                ret = tmp;
            pre = nums[i];

        }
        return ret;
    }
};

/***基数排序的思想
先进行基数排序 然后再进行遍历
**/
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if(nums.size() < 2) return 0;
		int ret = 0;
		const int R = 10;
		int *bucket = new int[nums.size()+1];

		int maxValue = nums[0];
		for(int i = 1;i<nums.size();++i){
			maxValue = max(nums[i],maxValue);
		}

		int exp = 1;
		while(maxValue / exp){
			int cnt[10];
			memset(cnt,0,sizeof(cnt));
			for(int i = 0;i<nums.size();++i){
				cnt[(nums[i]/exp)%10]+=1;
			}
			for(int i = 1;i<R;++i){
				cnt[i] += cnt[i - 1];
			}
			for(int i = nums.size()-1;i>=0;--i){
				int radix = (nums[i]/exp)%10;
				bucket[cnt[radix]-1] = nums[i];
				cnt[radix] -= 1;

				//cout<<cnt[radix]<<endl;
				//cout<< bucket[count[(nums[i]/exp)%10]]<<endl;
			}

			for(int i = 0;i<nums.size();++i){
				nums[i] = bucket[i];

			}
			exp *= 10;

		}

		for(int i = 1;i<nums.size();++i){
			ret = max(ret,bucket[i]-bucket[i-1]);
		}
		delete bucket;

		return ret;
	}
};
