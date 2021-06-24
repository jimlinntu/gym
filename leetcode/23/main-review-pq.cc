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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode *head = &dummy;
        auto cmp = [](ListNode *l, ListNode *r)->bool{
            return l->val > r->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(ListNode *l: lists){
            if(l != nullptr) pq.push(l);
        }
        ListNode *prev = head;
        while(!pq.empty()){
            ListNode *cur = pq.top();
            pq.pop();
            assert(cur != nullptr);
            if(cur->next != nullptr) pq.push(cur->next);
            // point the head to this node
            prev->next = cur;
            // move on to this ndoe
            prev = cur;
        }

        return head->next;
    }
};
