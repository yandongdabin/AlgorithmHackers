class FenwickTree(object):
    def __init__(self,n):
        self.n = n
        self.C = [0] * (n+1)
    def lowbit(self,x):
        return x & (-x)
    def sum(self,x):
        ret = 0
        while x > 0:
            ret += self.C[x]
            x-=self.lowbit(x)
        return  ret
    def add(self,i,x):
        while i <= self.n:
            self.C[i] += x
            i += self.lowbit(i)
class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        sums = [lower-1,upper]
        total = 0
        for num in nums:
            total += num
            sums += [total+lower-1,total+upper,total]
        index = {}
        i=0
        for s in sorted(set(sums)):
           index[s] = i+1
           i += 1
        tree = FenwickTree(len(index))
        ans = 0
        for i in xrange(len(nums)-1,-1,-1):
            tree.add(index[total],1)
            total-=nums[i]
            ans += tree.sum(index[total+upper]) - tree.sum(index[total+lower-1])
        return ans
        
