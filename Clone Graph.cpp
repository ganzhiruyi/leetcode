/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        unordered_map<int,UndirectedGraphNode*> mp;
        UndirectedGraphNode *u,*v,*ret,*newU,*newV;
        ret = new UndirectedGraphNode(node->label);
        mp[node->label] = ret;
        while(!q.empty()){
            u = q.front();
            q.pop();
            newU = mp[u->label];
            for(int i = 0;i < u->neighbors.size();++i){
                v = u->neighbors[i];
                if(mp.find(v->label) == mp.end()){
                    q.push(v);
                    newV = new UndirectedGraphNode(v->label);
                    newU->neighbors.push_back(newV);
                    mp[v->label] = newV;
                }
                else{
                    newU->neighbors.push_back(mp[v->label]);
                }
            }
        }
        return ret;
    }
};
