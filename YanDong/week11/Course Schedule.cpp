
int graph[2000][2000];
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        memset(graph,0,sizeof(graph));
        for(int i = 0;i<prerequisites.size();++i){
            graph[prerequisites[i].first][prerequisites[i].second] = 1;
        }
        for(int u = 0;u<numCourses;++u){
            if(!visited[u] && !dfs(visited,u,numCourses)) return false;
        }
        return true;

    }
    bool dfs(vector<int> &visited,int u,int numCourses){
        //表示该节点正在被访问
        visited[u] = -1;
        for(int v = 0;v<numCourses;++v){
            if(graph[u][v]){
                if(visited[v] < 0) return false;
                if(!visited[v] && !dfs(visited,v,numCourses)) return false;
            }
        }
        //表示该节点及其子节点已经访问完毕
        visited[u] = 1;
        return true;
    }
};
