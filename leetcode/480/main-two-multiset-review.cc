class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // Simulate deletable PQ
        multiset<int, greater<int>> left;
        multiset<int> right;
        vector<double> ans;
        
        for(int i = 0; i < k; i++){
            left.insert(nums[i]);
        }
        while(left.size() > right.size()+1){
            right.insert(*left.begin());
            left.erase(left.begin());
        }
        ans.push_back((k%2)?(*left.begin()):(((double)*left.begin() + *right.begin())/2.0));
        for(int i = k; i < n; i++){
            // add nums[i]
            if(nums[i] <= *left.begin()){
                left.insert(nums[i]);
            }else right.insert(nums[i]);
            // remove nums[i-k]
            if(nums[i-k] <= *left.begin()){
                left.erase(left.find(nums[i-k]));
            }else right.erase(right.find(nums[i-k]));
            // Balance
            if(left.size() > right.size() + 1){
                right.insert(*left.begin());
                left.erase(left.begin());
            }else if(left.size() < right.size()){
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            
            ans.push_back((k%2)?(*left.begin()):(((double)*left.begin() + *right.begin())/2.0));
        }
        return ans;
    }
};
