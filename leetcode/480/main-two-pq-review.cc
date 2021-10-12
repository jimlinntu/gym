class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        int left_size = 0, right_size = 0;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        unordered_map<int, int> invalid;

        for(int i = 0; i < k; i++){
            if(max_heap.empty() or max_heap.top() >= nums[i]){
                max_heap.push(nums[i]);
            }else{
                min_heap.push(nums[i]);
            }
            if(max_heap.size() > min_heap.size()+1){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }else if(max_heap.size() < min_heap.size()){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        left_size = max_heap.size();
        right_size = min_heap.size();
        ans.push_back((k%2)?(max_heap.top()):(((double)max_heap.top() + min_heap.top()) / 2.0));
        for(int i = k; i < n; i++){
            // remove nums[i-k] (lazily)
            invalid[nums[i-k]]++;
            // always delete the left first
            if(nums[i-k] <= max_heap.top()){
                left_size--; // lazy delete
            }else{
                right_size--; // lazy delete
            }
            // add nums[i]
            if(nums[i] <= max_heap.top()){
                max_heap.push(nums[i]);
                left_size++;
            }else{
                min_heap.push(nums[i]);
                right_size++;
            }

            // Rebalance
            if(left_size - right_size > 1){
                // NOTE: max_heap.top() must not be invalid number!
                //       because this condition only happens
                //       when there is an element deleted on the right
                min_heap.push(max_heap.top());
                max_heap.pop();
                left_size--;
                right_size++;
            }else if(left_size - right_size < 0){
                max_heap.push(min_heap.top());
                min_heap.pop();
                left_size++;
                right_size--;
            }
            // Pop invalid top elements
            while(!max_heap.empty() and invalid[max_heap.top()]){
                invalid[max_heap.top()]--;
                max_heap.pop();
            }
            while(!min_heap.empty() and invalid[min_heap.top()]){
                invalid[min_heap.top()]--;
                min_heap.pop();
            }

            ans.push_back((k%2)?(max_heap.top()):(((double)max_heap.top()+min_heap.top()) / 2.0));
        }
        return ans;
    }
};
