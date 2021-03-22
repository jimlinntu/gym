class RandomizedSet {
public:
    // v[i] == a val
    vector<int> v;
    // m[val] == an index to v
    unordered_map<int, int> m;
    default_random_engine g;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // already exists
        if(m.find(val) != m.end()) return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // not present
        if(m.find(val) == m.end()) return false;
        int idx = m[val];
        // imagine move val at v[idx] to the end of v and then pop_back
        int lastval = v.back();
        m[lastval] = idx; // now lastval is placed at v[idx]
        v[idx] = lastval;
        // val is pop_back.
        // NOTE: We don't actually put val at the end.
        //       because it will immediately be pop back,
        //       we can just ignore that assignment.
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution d(0, (int)v.size()-1);
        return v[d(g)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
