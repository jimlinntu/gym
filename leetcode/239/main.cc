struct Elem{
  int val, idx;
  Elem(int v, int i): val(v), idx(i){}
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_slide_window;
        if(n == 0) return max_slide_window;
        deque<Elem> dq;

        for(int i = 0; i < k; i++){
            Elem e(nums[i], i);
            // if the values in front of e is smaller than e.val
            // we do not need them anymore since e.val will ALWAYS be a better choice
            // in the windows afterward
            while(!dq.empty() and e.val >= dq.back().val){
                dq.pop_back();
            }
            dq.push_back(e);
        }

        max_slide_window.push_back(dq.front().val);

        if(n <= k) return max_slide_window;

        for(int i = k; i < n; i++){
            Elem e(nums[i], i);
            if(!dq.empty() and dq.front().idx == i-k){
                dq.pop_front(); // pop the leftmost element
            }
            while(!dq.empty() and e.val >= dq.back().val){
                dq.pop_back();
            }
            // add the new element for this window
            dq.push_back(e);
            // add the maximum value into the answer vector
            max_slide_window.push_back(dq.front().val);
        }

        return max_slide_window;
    }
};
