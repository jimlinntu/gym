class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int num: nums) map[num]++;
        // freq_nums[i] == a list of numbers having frequency == i
        vector<vector<int>> freq_nums(n+1);
        for(auto &it: map){
            freq_nums[it.second].push_back(it.first);
        }
        
        // from the most frequent to the least frequent
        vector<int> ans;
        for(int f = n; f >= 0; f--){
            for(int i = 0; i < freq_nums[f].size() and k > 0; i++){
                ans.push_back(freq_nums[f][i]);
                k--;
            }
        }
        return ans;
    }
};
