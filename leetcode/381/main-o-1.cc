class RandomizedCollection {
public:
    // v[i].first == a val
    // v[i].second == an index into m[val] (we will need it when we remove val)
    vector<pair<int, int>> v;
    // m[val] == vector<int> which contain indices of the vector
    unordered_map<int, vector<int>> m;
    default_random_engine g;
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = m.find(val) == m.end();
        // val is about to be appended to v
        m[val].push_back(v.size());
        // {val, its index to m[val]}
        v.push_back({val, m[val].size()-1});
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // Trick: we swap a element of val with the last element of v
        //        and then pop_back v
        auto it = m.find(val);
        // not found
        if(it == m.end()) return false;

        auto &indices = it->second;
        int idx = indices.back();
        // move the last element of v to v[idx]
        int lastval = v.back().first;
        int lastidx = v.back().second;
        m[lastval][lastidx] = idx;
        // Replace v[idx] with the last element
        v[idx] = {lastval, lastidx};
        // imagine the original val at idx is moved to the last element
        // and then be poped back
        v.pop_back();
        // NOTE: (Corner case) if v.size() == 1, lastidx will be equal to idx
        //       that's why indices.pop_back() is placed in the end
        //       Otherwise, m[lastval][lastidx] will throw exception
        indices.pop_back();
        if(indices.size() == 0) m.erase(it->first);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        uniform_int_distribution dist(0, (int)v.size()-1); 
        return v[(int)dist(g)].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
