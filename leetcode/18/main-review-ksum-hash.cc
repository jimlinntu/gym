using LL = long int;

class Solution {
public:
    int n;
    unordered_set<LL> S;
    void ksum(vector<vector<int>> &ans, vector<int> &nums, int target, int k,
                             int start){
        // two sum
        if(k == 2){
            // Hash
            
            for(int i = start; i < n; i++){
                // Ex.
                // Let a + d == target
                // a b c d d d
                //       ^     <--- the first we see d, (a, d) is a feasible pair
                //         ^   <--- the second time we see, d, (a, d) is duplicate!
                // Ex. 2 2 2 2 and target == 4
                // In this case, {2, 2} is a feasible pair, but after 

                if(S.find((LL)target-nums[i]) != S.end()){
                    if(target-nums[i] == nums[i]){
                        // if this is the third duplicate numbers
                        // Ex. 2 2 2 2
                        if(i >= start+2 and nums[i-2] == nums[i])
                            continue;
                    }else{
                        // duplicates
                        if(i >= start+1 and nums[i-1] == nums[i])
                            continue;
                    }
                    ans.push_back({nums[i], target-nums[i]});
                }
                S.insert(nums[i]);
                
            }
            S.clear();
            return;
        }
        int ans_n = ans.size();
        for(int i = start; i < n; i++){
            // avoid duplicates
            if(i >= start+1 and nums[i-1] == nums[i]) continue;

            // Recursion
            ksum(ans, nums, target-nums[i], k-1, i+1);

            // add nums[i] to the newly added set
            for(int j = ans_n; j < ans.size(); j++){
                ans[j].push_back(nums[i]);
            }
            ans_n = ans.size();
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<vector<int>> ans;
        ksum(ans, nums, target, 4, 0);
        return ans;
    }
};
