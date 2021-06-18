struct Node{
    int k, v;
};

class LRUCache {
public:
    int c;
    unordered_map<int, list<Node>::iterator> map;
    list<Node> l;
    LRUCache(int capacity): c(capacity) {
    }

    bool update(int key){
        auto it = map.find(key);
        if(it == map.end()) return false;
        list<Node>::iterator lit = it->second;
        // move to the first one
        l.insert(l.begin(), *lit);
        l.erase(lit);
        map[key] = l.begin(); // point to the new position
        return true;
    }

    int get(int key) {
        if(!update(key)) return -1;
        return map[key]->v;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it == map.end()){
            if(map.size() == c){
                int k = l.back().k;
                // evict the last one
                l.pop_back();
                map.erase(k); // delete this key
            }
            // insert it in front
            l.push_front({key, value});
            // record its iterator
            map[key] = l.begin();
        }else{
            // update its value
            map[key]->v = value;
            // update it to the most recently used
            update(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
