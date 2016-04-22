class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<pair<int,int>> a;
        a.clear();
        for(int i = 0;i < numbers.size();i++){
            a.push_back(make_pair(numbers[i],i+1));
        }
        sort(a.begin(),a.end());
        int i = 0,j = numbers.size()-1;
        while(i<j){
            if(a[i].first+a[j].first==target){
                vector<int> ans;
                ans.clear();
                ans.push_back(a[i].second);
                ans.push_back(a[j].second);
                sort(ans.begin(),ans.end());
                return ans;
            }
            else if(a[i].first+a[j].first<target)
                i++;
            else j--;
        }
    }
};
// 版本二
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        typedef pair<int,int> pii;
        vector<pii> v;
        for(int i = 0;i < numbers.size();++i)
            v.push_back(make_pair(numbers[i],i));
        sort(v.begin(), v.end());
        int first = 0,last = v.size()-1;
        while(first < last){
            if(v[first].first+v[last].first==target){
                int a = v[first].second,b = v[last].second;
                if(a < b) return {a,b}
                else return {b,a};
            }
            else if(v[first].first+v[last].first>target)
                --last;
            else ++first;
        }
        return {}
    }
};
