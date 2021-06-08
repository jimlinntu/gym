/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int get_n(ListNode *head){
        int n = 0;
        while(head != nullptr){
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode *move(ListNode *head, int step){
        ListNode *cur = head;
        while(step > 0){
            cur = cur->next;
            step--;
        }
        return cur;
    }
    ListNode *reverse(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur != nullptr){
            ListNode *next = cur->next;
            cur->next = prev; // point to the previous one
            prev = cur; // save the previous one
            cur = next; // move to the next
        }
        return prev;
    }
    ListNode *join(ListNode *a, ListNode *b){
        ListNode *cur_a = a, *cur_b = b;
        // Case 1: len(a) == len(b)+1
        // Case 2: len(a) == len(b);
        while(cur_a != nullptr and cur_b != nullptr){
            ListNode *next_a = cur_a->next;
            ListNode *next_b = cur_b->next;
            cur_a->next = cur_b;
            cur_b->next = next_a;
            //
            cur_a = next_a;
            cur_b = next_b;
        }
        return a;
    }
    void reorderList(ListNode* head) {
        int n = get_n(head);
        ListNode *firstend = move(head, n/2);
        ListNode *mid = firstend->next;
        // Split it
        firstend->next = nullptr;
        ListNode *head2 = reverse(mid);
        join(head, head2);
    }
};
