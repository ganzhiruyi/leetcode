class Solution {
public:
    struct Edge{
        int v,next;
    };
    vector<int> head;
    vector<Edge> e;
    int ne;
    void add_edge(int u,int v){
        e[ne].v=v,e[ne].next=head[u],head[u]=ne++;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
         head = vector<int>(numCourses,-1);
         e = vector<Edge>(prerequisites.size());
         ne = 0;
         for(int i = 0;i < prerequisites.size();++i){
             add_edge(prerequisites[i].second,prerequisites[i].first);
             ++inDegree[prerequisites[i].first];
         }
         queue<int> q;
         int u,v,inQueueCnt = 0;
         for(int i = 0;i < numCourses;++i)
             if(!inDegree[i]){
                 q.push(i);
                 ++inQueueCnt;
             }
         vector<int> ret;
         while(!q.empty()){
             u = q.front();
             q.pop();
             ret.push_back(u);
             for(int i = head[u];i != -1;i = e[i].next){
                 v = e[i].v;
                 if(--inDegree[v] == 0){
                     q.push(v);
                     ++inQueueCnt;
                 }
             }
         }
         return inQueueCnt == numCourses ? ret : vector<int>();
    }
};
