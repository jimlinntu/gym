class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // if n % 3 == 0: n = 3 * q     ==> num that has >= q+1 occurrences
        // if n % 3 != 0: n = 3 * q + r ==> num that has >= q+1 occurrences
        // Q: How many that kind of num can we have at most?
        // A: Let's try 3:
        // 3 * (q+1) == 3 q + 3 <= 3 q ==> 3 < 0 ==> impossible
        // 3 * (q+1) == 3 q + 3 <= 3 q + r ==> 3 < r ==> impossible
        // Therefore, it is impossible.
        // Let's try 2:
        // if n % 3 == 0: 2 * (q + 1) == 2 q + 2 <= 3 q ==> q >= 2
        // if n % 3 != 0: 2 * (q + 1) == 2 q + 2 <= 3 q + r ==> q + r >= 2
        // So we can as most have 2 num s.t. has >= q+1 occurrences
        
        // Short Proof:
        // Because if each pair containing 3 unique numbers
        // there are at most floor(n/3) pairing will happen when all numbers are different
        // Because a majority number will have >= floot(n/3) + 1,
        // after at most floor(n/3) pairings, it will have at least 1 left!!!!!
        // Generalization to pairing k unique numbers will be the same concept!
        int n = nums.size();
        int count1 = 0, count2 = 0;
        // NOTE: candidate1/2 can be any numbers
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        for(int num: nums){
            // Try to form (candidate1, candidate2, num) pair
            // NOTE: they must be unique!
            if(candidate1 == num){
                count1++;
                continue;
            }
            if(candidate2 == num){
                count2++;
                continue;
            }
            if(count1 == 0){
                // put num at this candidate(or slot)
                candidate1 = num;
                count1++;
                continue;
            }
            if(count2 == 0){
                // put num at this candidate(or slot)
                candidate2 = num;
                count2++;
                continue;
            }
            // If num is not candidate1 nor candidate2
            // and there is no slot to be inserted
            // we have to pair out this number
            assert(count1 > 0 and count2 > 0);
            count1--, count2--;
        }
        // Check if the candidate1/2 are truly majority numbers (>= floor())
        count1 = 0, count2 = 0;
        for(int num: nums){
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
        }
        vector<int> ans;
        if(count1 >= (n/3)+1) ans.push_back(candidate1);
        if(count2 >= (n/3)+1) ans.push_back(candidate2);
        return ans;
    }
};
