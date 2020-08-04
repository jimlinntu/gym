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

struct Tuple{
    int val, idx;
    Tuple(int v, int i): val(v), idx(i){}
    bool operator<(const Tuple &rhs) const{
        return val >= rhs.val;
    }
    
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Tuple> pq;
        // Initialize the pq
        int k = lists.size();

        vector<ListNode*> cur_lists = lists; // copy the whole list
        for(int i = 0; i < k; i++){
            ListNode *node = lists[i];
            if(node) pq.push(Tuple(node->val, i));
        }

        ListNode *merged = nullptr, *now = nullptr;
        while(!pq.empty()){
            Tuple t = pq.top(); // pop the lowest value
            pq.pop();
            ListNode *cur = cur_lists[t.idx];

            if(cur->next) pq.push(Tuple(cur->next->val, t.idx));
            cur_lists[t.idx] = cur->next; // move the cur pointer
            
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
