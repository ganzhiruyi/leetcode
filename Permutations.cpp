class Solution {
public:
    typedef vector<int>::iterator iterator;
    bool nextPermutation(iterator first, iterator end){
        if(first == end) return false; // 空集合
        iterator i = end;
        --i;
        if(i == first) return false; // 只有一个元素的集合
        for(;;){
            iterator ii = i;
            --i;
            if(*i < *ii){
                iterator j = end;
                while(*i > *(--j));
                swap(*i,*j); // 这里是交换i,j对应的值，不要交换迭代器本身
                reverse(ii,end);
                return true;
            }
            if(i == first){ // 找不到*i < *ii的情况，即全逆序了
                reverse(first,end); // 恢复成最开始的情况
                return false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        do{
            vector<int> v(nums.size());
            copy(nums.begin(),nums.end(),v.begin());
            ret.push_back(v);
        }while(nextPermutation(nums.begin(),nums.end()));
        return ret;
    }
};
