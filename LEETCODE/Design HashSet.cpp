// first approach
class MyHashSet {
public:
    int numBuckets;
    vector<vector<int>> buckets;
    
    int hash_fn(int key)
    {
        return key%numBuckets;
    }
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<vector<int>>(numBuckets, vector<int>{});
        
    }
    
    void add(int key) {
        int i = hash_fn(key);
        if(find(buckets[i].begin(), buckets[i].end(), key) == buckets[i].end())
            buckets[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash_fn(key);
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        
        if(it != buckets[i].end()) {
            buckets[i].erase(it);
        }      
           
            
    }
    
    bool contains(int key) {
        int i = hash_fn(key);
        if(find(buckets[i].begin(), buckets[i].end(), key) == buckets[i].end())
            return false;
        return true;
    }
};

// 2nd approach

class MyHashSet {
public:

vector<bool> ht;
MyHashSet() {
    ht=vector<bool>(1000001,false);
}
void add(int key) {
    ht[key]=true;
}

void remove(int key) {
    ht[key]=false;
}

bool contains(int key) {
    return ht[key]==true;
}
};