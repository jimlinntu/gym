class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int num: nums){
            s.insert(num);
        }
        int max_len = 0;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            // if this number if the minimum of this consecutive sequence
            // Ex. 1 2 3 4 5
            //     ^
            // NOTE: 2 will not fall into below piece of code
            if(s.find(num-1) == s.end()){
                // Go all the way to the right (num+1)
                int len = 1;
                // if the next number exist, keep go right
                for(int cur = num+1; s.find(cur) != s.end(); cur++){
                    len++;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
