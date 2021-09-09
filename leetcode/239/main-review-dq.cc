struct E{
    int idx;
    int val;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<E> dq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            // pop too old
            while(!dq.empty() and dq.front().idx <= i - k){
                dq.pop_front();
            }
            // Enqueue the new value
            while(!dq.empty() and dq.back().val <= nums[i]){
                dq.pop_back();
            }
            dq.push_back({i, nums[i]});
            if(i < k-1) continue;
            ans.push_back(dq.front().val);
        }
        return ans;
    }
};
