struct E{
    int timestamp;
    string val;
    bool operator<(const E &r) const{
        return timestamp < r.timestamp;
    }
    bool operator==(const E &r) const{
        return timestamp == r.timestamp;
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
    
    int bsearch_upperbound(vector<E> &v, E &e){
        int l = 0, r = v.size();
        while(l < r){
            int mid = (l+r)/2;
            if(v[mid] < e or v[mid] == e){
                // Because we want to find the first object > e
                // this mid is not we want
                l = mid+1;
            }else{
                r = mid;   
            }
        }
        return l;
    }
    
    string get(string key, int timestamp) {
        if(map.count(key) == 0) return "";
        vector<E> &v = map[key];
        // Binary search
        E e = {timestamp, ""};
        int idx = bsearch_upperbound(v, e);
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
