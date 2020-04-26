class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int num: nums){
            // XOR into the first element of nums
            answer ^= num;
        }
        return answer;
    }
};
