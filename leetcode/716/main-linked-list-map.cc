struct Node{
    int val;
    Node *prev, *next;
    Node(): val(0), prev(nullptr), next(nullptr){
    }
};

class MaxStack {
public:
    /** initialize your data structure here. */
    map<int, vector<Node*>, greater<int>> m;
    Node *head, *tail;
    MaxStack() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void push(int x) {
        Node *node = new Node();
        node->val = x;
        
        tail->prev->next = node;
        node->prev = tail->prev;
        
        node->next = tail;
        tail->prev = node;
        
        m[x].push_back(node);
    }
    
    int pop() {
        Node *last = tail->prev;
        int x = last->val;
        assert(m[x].back() == last);

        m[x].pop_back();
        if(m[x].size() == 0) m.erase(x); // erase it

        // remove it from the linked list stack
        last->prev->next = tail;
        tail->prev = last->prev;
        delete last;
        return x;
    }
    
    int top() {
        return tail->prev->val;
    }
    
    int peekMax() {
        return m.begin()->first;
    }
    
    int popMax() {
        auto it = m.begin();
        int x = it->first;
        
        vector<Node*> &v = it->second;

        Node *node = v.back();

        // remove it from the list
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        // remove it from the map
        v.pop_back();
        if(v.size() == 0) m.erase(it);

        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
