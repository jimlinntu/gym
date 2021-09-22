struct Node{
    Node *next;
    Node *prev;
    int key, val;
    Node(): next(nullptr), prev(nullptr){
        
    }
};

class LRUCache {
public:
    int capacity;
    int n;
    Node dummy1;
    Node dummy2;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> map;
    LRUCache(int capacity) {
        this->capacity = capacity;
        n = 0;
        head = &dummy1;
        tail = &dummy2;
        head->next = tail;
        tail->prev = head;
    }
    void move_front(int key){
        // move it to head->next
        if(map.count(key) == 0) return;
        Node *node = map[key];
        // node->prev --> node->next
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        // node <--> head->next
        head->next->prev = node;
        node->next = head->next;

        // head <--> node
        head->next = node;
        node->prev = head;
        return;
    }
    // Evict tail->prev
    void evict(){
        Node *node = tail->prev;
        map.erase(node->key);

        node->prev->next = node->next;
        node->next->prev = node->prev;
        n--;
        delete node; // delete it
    }
    int get(int key) {
        if(map.count(key) == 0) return -1;
        move_front(key); // used
        return map[key]->val;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            move_front(key);
            map[key]->val = value;
        }else{
            // Create a new node and put it in front
            Node *node = new Node();
            node->key = key;
            node->val = value;
            map[key] = node;
            node->next = head->next;
            head->next->prev = node;

            head->next = node;
            node->prev = head;
            n++;
            // Evict tail->prev
            if(n > capacity)
                evict();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
