
/***
基本思想：
将矩形抽象成一条条的线段 并按照 x轴坐标的大小排序
用一个数据结构记录当前x坐标上起作用的height高度，并能随时的取到最大值（可以考虑优先队列，但是优先队列不提供删除操作，
因为我们同时还希望能够控制高度的影响范围，所以有的解答上提示可以使用multiset，因为multiset内部是使用BST实现的 具体是红黑树）
能够构成拐点的原因是：当前的最高线段发生了变化

需要特殊考虑的情况：
如果两条线短 x轴坐标相同 则如果为同时为左边 则优先处理高边  同时为右边则先处理低边 否则会有冗余解产生

技巧：
为了区分左右边 左边负值编码 右边正值编码
***/


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> ret;
        vector<pair<int,int>> heights;
        for(auto &b : buildings){
            //拆解线段并且编码
            heights.push_back({b[0],-b[2]});
            heights.push_back({b[1],b[2]});
        }
        sort(heights.begin(),heights.end());

        multiset<int> heap;
        heap.insert(0);
        //用来记录最高线段是否发生了变化
        int pre = 0,cur = 0;
        for(auto &h:heights){
            if(h.second < 0){
                heap.insert(-h.second);
            }else{
                heap.erase(heap.find(h.second));
            }
            //当前高度最大值
            cur = *heap.rbegin();
            //高度发生了改变
            if(pre != cur){
                ret.push_back({h.first,cur});
                pre = cur;
            }

        }
        return ret;
    }
};
