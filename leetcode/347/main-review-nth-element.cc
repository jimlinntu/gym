class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<pair<int, int>> arr;
        for(int num: nums) map[num]++;
        for(auto &it: map){
            // {freq, num}
            arr.push_back({-it.second, it.first});
        }
        assert(k <= arr.size());
        // arr[i] == {freq, num}
        // Perform qselect on the first element of arr[i]
        nth_element(arr.begin(), arr.begin()+k-1, arr.end());
        // arr[0] ~ arr[k-1] are the k most frequent elements
        vector<int> ans;
        for(int i = 0; i <= k-1; i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
