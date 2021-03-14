class Solution {
public:
    int maxProduct(vector<int>& nums) {
        nums.push_back(0); // append a zero to trigger computation
        int n = nums.size();
        int max_prod = numeric_limits<int>::min();
        int prod = 1;
        int count_neg = 0;
        int count = 0;
        int f_prod = 1;
        int l_prod = 1;
        int f_neg = 1, l_neg = 1;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            // the max product should be at least the product of a single number
            if(i != n-1) max_prod = max(max_prod, num);

            if(num < 0) {
                count_neg++;
                l_prod = 1; // reset to 1 when we encounter a negative num

                if(count_neg == 1) f_neg = num;
                l_neg = num; // update the last negative number
                prod *= num;
                count++;
            }else if(num > 0){
                if(count_neg == 0){
                    // the front positive product
                    f_prod *= num;
                }else if(count_neg > 0){
                    // the last positive product
                    l_prod *= num;
                }
                prod *= num;
                count++;
            }else if(num == 0){
                // we have already consider count == 1
                if(count > 1){
                    // In this section, we only consider positive product
                    // if the number of negative number are even
                    // simply consider all numbers' product
                    if(count_neg % 2 == 0){
                        max_prod = max(max_prod, prod);
                    }else{
                        // if the number of negative number are odd
                        // we should consider:
                        // a b c d e f g h i j k
                        //     ^     ^     ^  <---- negative numbers
                        // then we should consider (d~k) or (a~h)
                        max_prod = max(max_prod, prod / (f_prod * f_neg));
                        max_prod = max(max_prod, prod / (l_neg * l_prod));
                    }
                }
                // Reset things
                prod = 1;
                count_neg = 0;
                count = 0;
                f_prod = 1;
                l_prod = 1;
                f_neg = 1;
                l_neg = 1;
            }
        }
        return max_prod;
    }
};
