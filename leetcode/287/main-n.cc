class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // A functional graph:
        // f(i) = nums[i] = another state
        vector<int> &graph = nums;
        // Floyd algorithm (tortoise and hare)
        // Initial state: 0
        int t = 0, h = 0, head = 0; // tortoise and hare
        // 1. Detect the loop
        while(true){
            t = graph[t]; // jump 1 step
            h = graph[graph[h]]; // jump 2 step
            if(t == h){
                break;
            }
        }
        // 2. Find the start of the loop state
        while(head != t){
            head = graph[head];
            t = graph[t];
        }
        
        return head;
    }
};
