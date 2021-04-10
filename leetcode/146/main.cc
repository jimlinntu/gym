struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(): prev(nullptr), next(nullptr) {}
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    int size;
    int capacity;
    Node *head;
    Node *tail;
    // m[key] == a Node* for key
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        // dummy head and tail
        // head <--> tail
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
        assert(capacity > 0);
        this->capacity = capacity;
    }
    ~LRUCache(){
        Node *next = nullptr;
        for(Node *cur = head; cur != nullptr; cur=next){
            next = cur->next;
            delete cur;
        }
    }
    
    void remove(Node *cur){
        // remove cur from its original place
        Node *prev = cur->prev;
        Node *next = cur->next;
        //     prev <--> cur <--> next
        // ==> prev <-----------> next
        prev->next = next;
        next->prev = prev;
    }
    
    void append(Node *cur){
        // move to the right (most recently used)
        //     prev <--> tail
        // ==> prev <--> cur  <--> tail
        cur->prev = this->tail->prev;
        cur->next = this->tail;

        (this->tail->prev)->next = cur;
        this->tail->prev = cur;
    }
    
    int get(int key) {
        auto it = m.find(key);
       if(it != m.end()){
            // move to the most recently used
            Node *cur = it->second;
            remove(cur);
            append(cur);
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()){
            Node *cur = it->second;
            // update its value
            cur->val = value;
            remove(cur);
            append(cur);
        }else{
            Node *cur = new Node(key, value);
            m[key] = cur; // save the address into the hashmap
            append(cur);
            if(size == capacity){
                // evict the least recently used Node
                Node *lru = head->next;
                assert(lru != nullptr); // because size == capacity >= 1
                m.erase(lru->key);
                remove(lru);
            }else size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
