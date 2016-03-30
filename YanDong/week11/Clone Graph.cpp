class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;
        if(m.find(node)==m.end()){
            m[node] = new UndirectedGraphNode(node->label);
            for(auto &neighbor:node->neighbors){
                m[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return m[node];

    }
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
};
