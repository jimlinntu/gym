class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Assumption: nums contains no duplicates
        // map[num]: the length of the longest consecutive containing this number
        unordered_map<int, int> map;
        int max_len = 0;
        for(int num: nums){
            if(map.find(num) == map.end()){
                int left_len = 0, right_len = 0;
                if(map.find(num-1) != map.end())
                    left_len = map[num-1];
                if(map.find(num+1) != map.end())
                    right_len = map[num+1];

                int len = left_len + right_len + 1;
                max_len = max(max_len, len);

                // Only the leftmost or rightmost boundary will be accessed again
                // so we only need to update two ends!!!
                // Ex. 1 2 3 4 5 6
                //     l   ^     r
                // We only need to inform map[1] == 6 and map[6] == 6
                map[num+right_len] = len;
                map[num-left_len] = len;
                // touches it, otherwise like
                // 1 2 3 4 3
                //     ^
                // will cause bug
                map[num]; 
            }
        }
        return max_len;
    }
};
