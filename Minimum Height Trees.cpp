class Solution {
public:
    typedef pair<int,int> pii;
    struct Edge{
        int v,next;
    };
    vector<Edge> e;
    vector<int> head,degree;
    int ne;
    void add_edge(int u,int v){
        e[ne].v=v,e[ne].next=head[u],head[u]=ne++;
    }
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return vector<int>(1,0); 
        ne = 0;
        head = vector<int>(n,-1);
        degree = vector<int>(n,0);
        e = vector<Edge>(n*2);
        for(int i = 0;i < edges.size();++i){
            add_edge(edges[i].first,edges[i].second);
            add_edge(edges[i].second,edges[i].first);
            ++degree[edges[i].first];
            ++degree[edges[i].second];
        }
        queue<int> q;
        for(int i = 0;i < n;++i) // 把所有叶节点加入队列
            if(degree[i] == 1) q.push(i);
        while(n > 2){
            int cnt = q.size(); // 不要直接在for中用q.size()
            while(cnt--){
                int u = q.front();
                q.pop();
                --n;
                for(int i = head[u];i != -1;i=e[i].next){
                    int v = e[i].v;
                    if(--degree[v]==1){
                        q.push(v);
                    }
                }
            }
        }
        vector<int> ret;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ret.push_back(u);
        }
        return ret;
    }
};
