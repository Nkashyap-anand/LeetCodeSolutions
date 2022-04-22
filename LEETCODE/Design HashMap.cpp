// simple approach

class MyHashMap {
public:
     int map[1000001];
    
    
    MyHashMap() {
        for(int i=0; i<size(map); i++)
        {
            map[i] = -1;
        }
    }
    
    void put(int key, int value) {
       map[key] = value;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
    }
};

// 2nd approach a little optimized

class MyHashMap {
public:
    
    vector<list<pair<int,int>>> map;
    int size;
    
    MyHashMap() {
        size = 769;
        map.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<pair<int,int>> :: iterator search (int key){
        
        int i = hash(key);
        list<pair<int,int>> :: iterator it = map[i].begin();
        
        while(it != map[i].end()){
            if(it->first == key) return it;
            it++;
        }
         return it;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        map[i].push_back({key,value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        
        if(it==map[i].end()) return -1;
        else return it-> second;
    }
    
    void remove(int key) {
         int i = hash(key);
         list<pair<int,int>> :: iterator it = search(key);
         
        if(it != map[i].end()) map[i].erase(it);
    }
};