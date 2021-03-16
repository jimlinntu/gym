class Solution {
public:
    map<int, int> counter; // counter[i] == how many i are there
    unordered_map<int, int> s; // s[i] == the number of (num < i)
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            counter[nums[i]]++;
        }
        int sum = 0;
        // Loop ascendingly
        for(auto it = counter.begin(); it != counter.end(); it++){
            s[it->first] = sum;
            sum += it->second;
        }
        for(int i = 0; i < n; i++){
            ans[i] = s[nums[i]];
        }
        return ans;
    }
};
