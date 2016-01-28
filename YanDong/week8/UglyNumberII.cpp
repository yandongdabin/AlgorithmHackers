#include<queue>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> q;
        set<int> s;
        q.push(3);
        q.push(2);
        q.push(1);
        int seq = 1;
        while(!q.empty()){
            int cur = q.top();
            q.pop();
            if(s.find(cur)!=s.end())
                continue;
            s.insert(cur);
            if(seq == n){
                return cur;
            }
            seq += 1;
            q.push(cur * 2);
            q.push(cur * 3);
            q.push(cur * 5);
        }
    }
};
