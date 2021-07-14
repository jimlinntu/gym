class MyHashMap {
public:
    /** Initialize your data structure here. */

    vector<vector<pair<int, int>>> a;
    MyHashMap() {
        a = vector<vector<pair<int, int>>>(1024);
    }

    int h(int key){
        return key % a.size();
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = h(key);
        // Search if there is an existing one
        auto &v = a[idx];
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == key){
                v[i].second = value;
                return;
            }
        }
        // Otherwise, put it back behind this vector
        v.push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = h(key);
        auto &v = a[idx];
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == key) return v[i].second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = h(key);
        auto &v = a[idx];
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == key){
                v.erase(v.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
