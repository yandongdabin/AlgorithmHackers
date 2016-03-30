
/**dfs求拓扑排序 思想是当一个节点没有后继的时候就可以输出 最后的结果是逆拓扑排序
bfs思路是一个节点没有前驱的时候就可以输出 输出的结果就是拓扑排序的结果

*/

int graph[2000][2000];
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> ret;
        memset(graph,0,sizeof(graph));
        for(int i = 0;i<prerequisites.size();++i){
            graph[prerequisites[i].second][prerequisites[i].first] = 1;
        }
        for(int u = 0;u<numCourses;++u){
            if(!visited[u] && !dfs(visited,ret,u,numCourses)) return vector<int>();
        }
        reverse(ret.begin(),ret.end());
        return ret;

    }
    bool dfs(vector<int> &visited,vector<int> &ret,int u,int numCourses){
        //表示该节点正在被访问
        visited[u] = -1;
        for(int v = 0;v<numCourses;++v){
            if(graph[u][v]){
                if(visited[v] < 0) return false;
                if(!visited[v] && !dfs(visited,ret,v,numCourses)) return false;
            }
        }
        //表示该节点及其子节点已经访问完毕
        visited[u] = 1;
        ret.push_back(u);
        return true;
    }
};
