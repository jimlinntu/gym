class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> a;
    MyHashSet() {
        a = vector<vector<int>>(1024);
    }

    constexpr int h(int key){
        return key % a.size();
    }

    void add(int key) {
        int idx = h(key);
        auto &v = a[idx];
        for(int i = 0; i < v.size(); i++){
            if(v[i] == key) return;
        }
        v.push_back(key);
    }

    void remove(int key) {
        int idx = h(key);
        auto &v = a[idx];
        for(int i = 0; i < v.size(); i++){
            if(v[i] == key){
                v.erase(v.begin()+i);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = h(key);
        auto &v = a[idx];
        for(int i = 0; i < v.size(); i++){
            if(v[i] == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
