/** 用3个map加一个时间戳的方式实现,268ms,
一旦操作个数超过INT_MAX,time就会溢出
**/
class LRUCache{
public:
    map<int,int> keyValue;
    map<int,int> timeKey;
    map<int,int> keyTime;
    int time,mCapacity;
    LRUCache(int capacity) {
        time = 0;
        mCapacity = capacity;
        keyValue.clear(),keyTime.clear(),timeKey.clear();
    }
    
    int get(int key) {
        if(keyValue.find(key) != keyValue.end()){
            int preTime = keyTime[key];
            timeKey.erase(preTime);
            timeKey[time] = key;
            keyTime.erase(key);
            keyTime[key] = time++;
            return keyValue[key];
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(keyValue.find(key) != keyValue.end()){
            int preTime = keyTime[key];
            timeKey.erase(preTime);
            timeKey[time] = key;
            keyTime.erase(key);
            keyTime[key] = time++;
        }
        else{
            if(keyValue.size() == mCapacity){
                map<int,int>::iterator first = timeKey.begin();
                int firstKey = (*first).second;
                int firstTime = (*first).first;
                timeKey.erase(firstTime);
                keyTime.erase(firstKey);
                keyValue.erase(firstKey);
            }
            timeKey[time] = key;
            keyTime[key] = time++;
        }
        keyValue[key] = value;
    }
};
/** 版本二,利用unordered_map和deque实现,由于deque的实现机制，
在删除一个迭代器时可能造成很大的时间代价，可以用双向链表实现
**/
class LRUCache{
public:
    typedef pair<int,int> pii;
    typedef list<pii>::iterator iterator;
    list<pii> q;
    unordered_map<int,iterator> hash;
    int mCapacity;
    LRUCache(int capacity) {
        mCapacity = capacity;
        q.clear();
        hash.clear();
    }
    
    int get(int key) {
        if(hash.find(key) != hash.end()){
            iterator it = hash[key]; 
            pii tmp = *it;
            q.erase(it);
            q.push_front(tmp);
            hash[key] = q.begin();
            return q.front().second;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(hash.find(key) != hash.end()){
            iterator it = hash[key];
            q.erase(it);
            q.push_front(make_pair(key,value));
            hash[key] = q.begin();
        }
        else{
            if(q.size() == mCapacity){
                pii last = q.back();
                q.pop_back();
                hash.erase(last.first);
            }
            q.push_front(make_pair(key,value));
            hash[key] = q.begin();
        }
    }
};
