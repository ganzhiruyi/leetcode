class Solution {
public:
    typedef vector<int>::iterator iterator;
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        iterator slow = nums.begin();
        iterator fast = slow + 1;
        while(fast != nums.end()){
            if(*fast == *slow){
                ++fast;
                if(fast-slow > 2){
                    fast = nums.erase(fast-1);
                }
            }
            else{
                slow = fast++;
            }
        }
        return nums.size();        
    }
};
