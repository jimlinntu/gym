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

struct cmp{
    bool operator()(const ListNode* l, const ListNode* r) const{
        return l->val > r->val; // if it is true, r->val will be put on top of l
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        int k = lists.size();
        for(int i = 0; i < k; i++){
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode *merged = nullptr, *now = nullptr;
        while(!pq.empty()){
            ListNode *cur = pq.top();
            pq.pop();
            if(cur->next) pq.push(cur->next);
            if(now){
                now->next = new ListNode(cur->val);
                now = now->next;
            }else{
                now = new ListNode(cur->val);
                merged = now;
            }
        }
        return merged;
    }
};
