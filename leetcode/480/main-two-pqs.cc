using MaxPQ = priority_queue<int, vector<int>>;
using MinPQ = priority_queue<int, vector<int>, greater<int>>;
    
class Solution {
public:
    MaxPQ left_pq;
    MinPQ right_pq;
    unordered_map<int, int> delete_count;
    void balance_pqs(MaxPQ &left_pq, MinPQ &right_pq, int balance){
        if(balance == 0) return;
        // left_pq contains too many numbers
        if(balance > 0){
            for(int i = 0; i < balance; i++){
                right_pq.push(left_pq.top());
                left_pq.pop();
            }
        }else{
            // right_pq contains too many numbers
            balance = -balance;
            for(int i = 0; i < balance; i++){
                left_pq.push(right_pq.top());
                right_pq.pop();
            }
        }
        return;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> medians;
        if(n == 0) return medians;
        
        for(int i = 0; i < k; i++){
            left_pq.push(nums[i]);
        }
        // k == even: push k / 2 numbers to the right
        // k == odd: push (k-1) / 2 numbers to the right
        balance_pqs(left_pq, right_pq, k / 2);

        if(k % 2) medians.push_back(left_pq.top());
        else medians.push_back(((double)left_pq.top() + (double)right_pq.top()) / 2.);

        // window: [i-k+1, i]
        for(int i = k; i < n; i++){
            int balance = 0;
            // Move nums[i-k] out of window
            int del_num = nums[i-k];

            if(!left_pq.empty() and left_pq.top() == del_num){
                left_pq.pop();
                balance--; // left_pq delete 1 num
            }else if(!right_pq.empty() and right_pq.top() == del_num){
                right_pq.pop();
                balance++; // right_pq delete 1 num
            }else{
                delete_count[del_num]++;
                // left_pq implicitly delete 1 num
                // del_num should be present either at the left_pq or right_pq
                if(del_num <= left_pq.top()){
                    balance--;
                }else{
                    balance++;
                }
            }

            // Add nums[i]
            int add_num = nums[i];
            if(!left_pq.empty() and add_num <= left_pq.top()){
                left_pq.push(add_num);
                balance++;
            }else{
                right_pq.push(add_num);
                balance--;
            }

            // Balance two pqs
            balance_pqs(left_pq, right_pq, balance / 2);
            // Delete numbers on top of pqs if their delete_count are nonzeros
            // Make sure that the top element is not from the delete numbers!
            while(!left_pq.empty() and delete_count[left_pq.top()] > 0){
                delete_count[left_pq.top()]--;
                left_pq.pop();
            }

            while(!right_pq.empty() and delete_count[right_pq.top()] > 0){
                delete_count[right_pq.top()]--;
                right_pq.pop();
            }
            // Note: Before adding a median, we must pop all DELETED numbers!
            // Compute the median
            if(k % 2) medians.push_back(left_pq.top());
            else medians.push_back(((double)left_pq.top() + (double)right_pq.top()) / 2.);
        }
        return medians;
    }
};
