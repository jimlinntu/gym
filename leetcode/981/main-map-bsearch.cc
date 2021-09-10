struct E{
    int timestamp;
    string val;
    bool operator<(const E &r) const{
        return timestamp < r.timestamp;
    }
};
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<E>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(map.count(key) == 0) return "";
        vector<E> &v = map[key];
        // Binary search
        // E e = {timestamp, ""};
        auto it = upper_bound(v.begin(), v.end(), E{timestamp, ""});
        int idx = it - v.begin();
        if(idx-1 < v.size()){
            return v[idx-1].val;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
