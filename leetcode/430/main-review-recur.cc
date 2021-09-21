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
    Node *solve(Node *head){
        Node *cur = head;
        Node *last = nullptr;
        for(Node *next; cur != nullptr; cur = next){
            next = cur->next;
            if(cur->child){
                Node *tail = solve(cur->child);
                tail->next = next;
                if(next) next->prev = tail;

                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr; // set null
                
                last = tail; // be the last of the flatten list
            }else last = cur;
        }
        return last;
    }
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};
