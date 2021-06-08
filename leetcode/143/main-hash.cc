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
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> map;
        int n = 0;
        ListNode *cur = head;
        // map[i] == the ListNode* at i
        for(; cur != nullptr; cur = cur->next, n++){
            map[n] = cur;
        }
        if(n == 0) return;
        // Split the middle poit
        map[(n-1)/2]->next = nullptr;
        // For node at i, insert n-1-i node at its end
        cur = head;
        for(int i = 0; i < n/2; i++){
            ListNode *next = cur->next;
            cur->next = map[n-1-i];
            map[n-1-i]->next = next;
            cur = next;
        }
    }
};
