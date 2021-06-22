class Solution {
public:
    int reindex(int i, int n){
        // n is even: a b a b a b
        //            2 5 1 4 0 3
        if(i >= (n+1) / 2){
            // {b} indices
            i = i - (n+1) / 2;
            if(n % 2 == 0) return n-1-2*i;
            return n-2-2*i;
         }else{
            // {a} indices
            if(n % 2 == 0) return n-2-2*i;
            return n-1-2*i;
        }
    }

    void wiggleSort(vector<int>& nums) {
        // Divide nums into {a} and {b}
        // where max{a} <= min{b}
        int n = nums.size();
        int num_a = (n+1) / 2, num_b = n / 2;
        // [0, num_a): {a}
        // [num_a, n): {b}
        nth_element(nums.begin(), nums.begin()+num_a-1, nums.end());
        // Divide into 3 parts
        // {a} / middle, {middle}, {b} / middle
        int middle = nums[num_a-1];
        // Put {b} / middle as left as possible
        int i = 0;
        int l = 0, r = n-1;
        // NOTE: i == r still need to check because numbers at r
        //       might be < middle
        // Color Sorting algorithm
        while(i <= r){
            int ii = reindex(i, n);
            int ll = reindex(l, n);
            int rr = reindex(r, n);
            if(nums[ii] > middle){
                // Throw to the back
                swap(nums[ii], nums[rr]);
                r--;
            }else if(nums[ii] < middle){
                // Throw to the beginning
                swap(nums[ii], nums[ll]);
                i++, l++;
            }else{
                // == middle, just keep go right
                i++;
            }
        }
    }
};
