class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        unordered_set<int> s;
        for(int num: nums){
            s.insert(num);
        }
        // Start from 1, until a number doesn't exist
        // O(n)
        for(; s.count(ans); ans++){
        }
        return ans;
    }
};
