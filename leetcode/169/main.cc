class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        int count = 1;
        int cur_num = nums[0];
        // Intuition: there is a competition among numbers
        // if two numbers are not equal, they will compete to death
        // if two numbers are equal, this number will be stronger
        // Ex. [1, 2, 2]
        // when 1 meets 2, they will compete to death,
        // and 2 will be the last number remaining
        // Ex. [1, 4, 3, 4, 4, 4]
        // (1, 4) -> to death
        // (3, 4) -> to death
        // Ex. [2, 2, 4, 4, 4]
        // (2, 2, 4) -> (2)
        // (2, 4) -> ()
        // 4 will be the remaining number
        for(int i = 1; i < n; i++){
            if(count == 0){
                cur_num = nums[i];
                count = 1;
                continue;
            }
            if(nums[i] == cur_num){
                count++;
            }else{
                // two numbers will compete to death
                // cur_num will lose one
                --count;
            }
        }
        return cur_num;
    }
};
