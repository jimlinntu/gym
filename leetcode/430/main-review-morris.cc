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
        for(; cur != nullptr; cur = cur->next){
            if(cur->child){
                Node *next = cur->next;
                // go to the last node
                Node *t = cur->child;
                while(t->next){
                    t = t->next;
                }
                // Morris concatenation
                t->next = next;
                // next can be nullptr
                if(next) next->prev = t;
                // flatten
                cur->next = cur->child;
                cur->child->prev = cur;

                cur->child = nullptr; // set null
            }
        }
        return head;
    }
};
