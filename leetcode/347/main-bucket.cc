class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Bucket sort
        unordered_map<int, int> freq;
        for(int num: nums) freq[num]++;

        // bucket[freq] == [num1, num2, ...]
        // Trick: At most nums.size() frequency, that is why we can use bucket sort
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it = freq.begin(); it != freq.end(); it++){
            int num = it->first;
            int f = it->second;
            bucket[f].push_back(num);
        }
        vector<int> ans;
        for(int f = nums.size(); f >= 0; f--){
            for(int i = 0; i < bucket[f].size() && k > 0; i++, k--){
                ans.push_back(bucket[f][i]);
            }
        }
        return ans;
    }
};
