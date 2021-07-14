class MyHashMap {
public:
    /** Initialize your data structure here. */
    // a[i] == {key, value}
    vector<pair<int, int>> a;
    MyHashMap() {
        // key == -1 means unused
        // key == INT_MIN means this place is removed and cannot be used
        a = vector<pair<int, int>>(1024, {-1, -1});
    }

    int h(int key){
        return key % a.size();
    }

    void rehash(){
        // double the table size
        int n = a.size();
        vector<pair<int, int>> copy = a;
        a = vector<pair<int, int>>(2*n, {-1, -1});

        // reinsert these elements back to the array
        for(auto &p: copy){
            if(p.first == -1 or p.first == INT_MIN) continue;
            put(p.first, p.second);
        }
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int n = a.size();
        int idx = h(key);
        // search until we find a place to put {key, value}
        bool success = false;
        for(int i = 0; i < n; i++){
            int j = (idx+i) % n;
            // if this is a vacant one or a delete place, place here
            if(a[j].first == -1 or a[j].first == INT_MIN){
                a[j] = {key, value};
                success = true;
                break;
            }else if(a[j].first == key){
                // update it
                a[j].second = value;
                success = true;
                break;
            }
        }

        if(!success){
            rehash(); // double the base array
            put(key, value);
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int n = a.size();
        int idx = h(key);
        for(int i = 0; i < n; i++){
            int j = (idx+i) % n;
            if(a[j].first == key) return a[j].second;
            else if(a[j].first == -1) break;
            // when we find a vacant space, we know we need to break
            // NOTE: when we encounter a INT_MIN, we should keep searching
            //       because it is just a tombstone, there might be elements after it
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int n = a.size();
        int idx = h(key);
        for(int i = 0; i < n; i++){
            int j = (idx+i) % n;
            if(a[j].first == key) a[j].first = INT_MIN; // a tombstone
            else if(a[j].first == -1) break; // this key does not exist
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
