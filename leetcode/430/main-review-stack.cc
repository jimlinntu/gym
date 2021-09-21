/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

struct E{
    Node *node;
    bool need_concat; // a flag indicates whether its parent is broken
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return nullptr;
        stack<E> stk;
        stk.push({head, false});
        // DFS
        Node *prev = nullptr;
        while(!stk.empty()){
            E e = stk.top();
            Node *cur = e.node;
            if(e.need_concat and prev){
                prev->next = cur;
                cur->prev = prev;
            }
            prev = cur; // store the previous visited
            stk.pop();

            if(cur->next) stk.push({cur->next, cur->child != nullptr});
            if(cur->child) stk.push({cur->child, false});

            if(cur->child){
                // Break the link between cur and cur->next
                // Move cur->child to cur->next
                if(cur->next) cur->next->prev = nullptr;

                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
        }
        return head;
    }
};
