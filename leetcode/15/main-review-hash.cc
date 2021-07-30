class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<int, int> map;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i >= 1 and nums[i-1] == nums[i]) continue;

            int t = -nums[i];
            // Two sum hashing
            for(int j = i+1; j < n; j++){

                // If t-nums[j] is present in the i-th loop
                if(map.find(t-nums[j]) != map.end() and map[t-nums[j]] == i){
                    // Ex. Handle case like
                    // 2 2 2 where t == 4
                    //     ^ <-- This should be avoided
                    ans.push_back({nums[i], nums[j], t-nums[j]});
                    // Go right until there is no duplicates
                    while(j+1 < n and nums[j] == nums[j+1]) j++;
                }

                map[nums[j]] = i; // appear in the i-th loop
            }
        }
        return ans;
    }
};
