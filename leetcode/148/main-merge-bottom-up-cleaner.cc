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
    int getLength(ListNode *l){
        int n = 0;
        while(l != nullptr){
            n++;
            l = l->next;
        }
        return n;
    }
    ListNode *merge(ListNode *left, ListNode *right, ListNode *prev){
        assert(prev != nullptr);
        while(left != nullptr and right != nullptr){
            if(left->val <= right->val){
                prev->next = left;
                left = left->next;
            }else{
                prev->next = right;
                right = right->next;
            }
            prev = prev->next; // move on
        }
        // if there are still remaining nodes
        if(left != nullptr){
            prev->next = left;
        }else if(right != nullptr){
            prev->next = right;
        }
        // walk to the end of this list (non nullptr)
        assert(prev != nullptr);
        while(prev->next != nullptr) prev = prev->next;
        return prev; // the last non nullptr node of this merged list
    }
    // split head with n nodes and then return the next_head after this split
    ListNode *split(ListNode *head, int n){
        // split n nodes. If nodes on the right are not enough,
        // just split as more as possible
        while((--n) > 0 && head != nullptr) head = head->next;
        ListNode *next_head;
        if(head == nullptr) next_head = nullptr;
        else{
            next_head = head->next;
            head->next = nullptr;
        }
        return next_head;
    }
    ListNode* merge_sort(ListNode *head, int n){
        // O(log n) steps
        ListNode *fake_head = new ListNode();
        fake_head->next = head;

        for(int len = 1; len < n; len *= 2){
            ListNode *left, *right;
            ListNode *prev = fake_head;
            for(ListNode *cur = prev->next; cur != nullptr;){
                // Merging [i, i+len) and [i+len, i+2*len)
                left = cur; // assign cur to left so that cur can be updated later
                right = split(left, len);
                // move cur to the next one
                // NOTE: after this function, right cannot travel to cur using ->next
                //       because they are split
                cur = split(right, len);
                // merge left and right by appending them behind prev
                // and then update prev immediately after this function returns
                prev = merge(left, right, prev);
            }
        }
        ListNode *real_head = fake_head->next;
        delete fake_head;
        return real_head;
    }
    ListNode* sortList(ListNode* head) {
        int n = getLength(head);
        return merge_sort(head, n);
    }
};
