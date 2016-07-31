class Solution {
public:
    struct Node{
        int num,cnt;
        Node(){}
        Node(int num,int cnt):num(num),cnt(cnt){}
        bool operator<(const Node &node){
            return cnt < node.cnt;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<Node> nodes;
        unordered_map<int,int> mp;
        for(int i = 0;i < nums.size();++i)
            ++mp[nums[i]];
        typedef unordered_map<int,int>::iterator iterator;
        for(iterator it = mp.begin();it != mp.end();++it)
            nodes.push_back(Node(it->first,it->second));
        make_heap(nodes.begin(), nodes.end());
        vector<int> ret;
        while(k--){
            pop_heap(nodes.begin(), nodes.end());
            ret.push_back(nodes.back().num);
            nodes.pop_back();
        }
        return ret;
    }    
};
