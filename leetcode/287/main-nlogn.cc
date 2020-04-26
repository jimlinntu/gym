class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, u = nums.size()-1; // start range: [1, n]
        // Reduce the lower bound and upper bound size by 2
        for(; l != u;){
            // Compute which side's num of numbers > num of slots
            // left: [l, mid]
            // right: [mid+1, u]
            int mid = (l+u) / 2;
            int left_size = 0;
            int left_num_slots = mid - l + 1;
            for(int num: nums){
                if(l <= num && num <= mid) left_size++;
            }
            // left range contains the duplicate numbers
            if(left_size > left_num_slots){
                u = mid; // update the upper bound
            }
            // right range contains the duplicate numbers
            else{
                l = mid+1;// update the lower bound
            }
        }
        return l;
    }
};
