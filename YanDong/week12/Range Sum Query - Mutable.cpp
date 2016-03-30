
/**二叉索引树
树状数组
*/
class NumArray {
public:
	NumArray(vector<int> &nums):sum_array(nums.size()+1,0){
		this->n = nums.size();
		this->nums = nums;
		for(int i = 0;i<nums.size();++i){
			init(i,nums[i]);
		}
	}
	void init(int i,int val){
		i++;
		while(i<=n){
			sum_array[i]+=val;
			i+=lowbit(i);
		}
	}
	void update(int i, int val) {
		int diff = val - nums[i];
		nums[i] = val;
		init(i,diff);
	}

	int sumRange(int i, int j) {
		return sum(j) - sum(i-1);
	}
	int sum(int i){
		i+=1;
		int res = 0;
		while(i > 0){
			res += sum_array[i];
			i-=lowbit(i);
		}
		return res;
	}
private:
	inline int lowbit(int x){return x & -x;}
private:
	vector<int> sum_array;
	vector<int> nums;
	int n;
};



