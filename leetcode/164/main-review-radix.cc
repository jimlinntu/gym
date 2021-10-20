class Solution {
public:
    int get_digits(int num){
        int d = 0;
        while(num > 0){
            d++;
            num /= 10;
        }
        return d;
    }
    void radix_sort(vector<int> &nums){
        int n = nums.size();
        int mx = nums[0];
        for(int i = 1; i < n; i++){
            mx = max(mx, nums[i]);
        }
        int d = get_digits(mx);
        int base = 1; // to extract the i's digit from a number
        vector<int> out(n);
        for(int i = 0; i < d; i++, base *= 10){
            int count[10] = {0};
            // counting
            for(int j = 0; j < n; j++){
                int num = nums[j];
                int digit = (num / base) % 10;
                count[digit]++;
            }
            
            // prefix sum
            for(int j = 1; j < 10; j++){
                count[j] += count[j-1];
            }
            // reindex the data according to the index
            // NOTE: must loop from back to be a stable sort
            for(int j = n-1; j >= 0; j--){
                int num = nums[j];
                int digit = (num / base) % 10;
                out[--count[digit]] = num;
            }
            // reassign back
            nums = out;
        }
    }
    int maximumGap(vector<int>& nums) {
        radix_sort(nums);
        int n = nums.size();
        if(n <= 1) return 0;
        int ans = INT_MIN;
        for(int i = 1; i < n; i++){
            ans = max(ans, nums[i]-nums[i-1]);
        }
        return ans;
    }
};
