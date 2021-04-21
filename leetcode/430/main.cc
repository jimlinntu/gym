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

class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head;
        Node *last = nullptr;
        // Morris Traversal: O(n)
        for(; cur != nullptr; cur = cur->next){
            if(cur->child == nullptr) continue;
            last = cur->child;
            while(last->next != nullptr) last = last->next;
            assert(last != nullptr);
            // Move nodes after cur behind last
            if(cur->next != nullptr) cur->next->prev = last;
            last->next = cur->next;
            // Move the child list to behind cur
            cur->child->prev = cur;
            cur->next = cur->child;
            // Nullify cur->child
            cur->child = nullptr;
        }
        return head;
    }
};
