class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answers(2, 0);
        int entangled = 0;
        // XOR all elements to get an entangled state
        for(int num: nums){
            entangled ^= num;
        }
        // Find an arbitrary bit to divide the nums into two group
        int first_meet = 0;
        while((entangled & 1) == 0){
            first_meet++;
            entangled >>= 1; // right shift by 1
        }
        // divider = 0000...1...0000
        int divider = 1 << (first_meet);
        for(int num: nums){
            if(num & divider){
                // those whose r-th bit is 1
                answers[0] ^= num;
            }else{
                // those whose r-th bit is 0
                answers[1] ^= num;
            }
        }
        return answers;
    }
};
