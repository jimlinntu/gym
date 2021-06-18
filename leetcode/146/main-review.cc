struct Node{
    int k, v;
    Node *prev, *next;
    Node(): prev(nullptr), next(nullptr){
    }
};

class LRUCache {
public:
    int c;
    Node *head;
    Node *tail;

    unordered_map<int, Node*> map;

    LRUCache(int capacity): c(capacity) {
        assert(c > 0);
        head = new Node();
        tail = new Node();
        // head <-----> tail
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache(){
        Node *cur = head;
        for(Node *next; cur != nullptr; cur = next){
            next = cur->next;
            delete cur;
        }
    }

    void update(int key){
        Node *node = map[key];
        // remove it
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // put this node in the beginning
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void evict(){
        Node *node = tail->prev;
        map.erase(node->k);
        node->prev->next = tail;
        tail->prev = node->prev;
        delete node;
    }
    
    int get(int key){
        auto it = map.find(key);
        if(it == map.end()) return -1;
        update(key);
        return map[key]->v;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if(it == map.end()){
            if(map.size() == c) evict();
            Node *node = new Node();
            node->k = key;
            node->v = value;
            // add this node
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;

            map[key] = node;
        }else{
            map[key]->v = value; // update its value
            update(key); // update its position
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
