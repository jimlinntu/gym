class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int answer = 0, i = 0;
        for(int num: nums){
            answer ^= num ^ (++i); // XOR 1~n
        }
        return answer;
    }
};
