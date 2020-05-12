class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer_triplets;
        int n = nums.size();
        if(n == 0) return answer_triplets;
        // O(n log n)
        sort(nums.begin(), nums.end());
        // Find index that split nums into >= 0 and < 0 (O(log n))
        int left = 0, right = n-1, mid;
        while(left != right){
            mid = (left + right) / 2;
            if(nums[mid] < 0){
                left = mid+1; // [mid+1, right]
            }else if(nums[mid] == 0){
                right = mid; // [left, mid]
            }else{
                right = mid; // [left, mid]
            }
        }
        // If all numbers are either greater or smaller to 0,
        // then the answer is the empty set
        if(left == 0 and nums[0] > 0) return answer_triplets;
        if(right == n-1 and nums[n-1] < 0) return answer_triplets;
        // Find 3 == 0
        int num_zeros = 0;
        for(int i = 0; i < n; i++){
            num_zeros += (nums[i] == 0);
        }
        // Add (0, 0, 0)
        if(num_zeros >= 3) answer_triplets.push_back(vector<int>(3, 0));
        // Find 2 >= 0 and 1 < 0: O(n^2)
        int negative_ptr;
        for(int i = left; i < n; i++){
            // Avoid duplicate numbers
            if(i != left && nums[i-1] == nums[i]) continue;
            negative_ptr = left-1;
            for(int j = i+1; j < n; j++){
                // as i,j increment, target will be monotonically smaller
                int target = -(nums[i] + nums[j]);
                bool found = false;
                // move negative_ptr toward left
                while(negative_ptr != -1){
                     if(nums[negative_ptr] > target){
                         negative_ptr--;
                     }else if(nums[negative_ptr] == target){
                         if(!found){
                             answer_triplets.push_back(
                            vector<int>({nums[i], nums[j], target}));
                             found = true;
                         }
                         negative_ptr--; // move backward
                     }else break;
                }
            }
        }
        // Find 1 >= 0 and 2 < 0
        int positive_ptr;
        for(int i = left-1; i >= 0; i--){
            // Avoid duplicate numbers
            if(i != left-1 && nums[i+1] == nums[i]) continue;
            positive_ptr = left;
            for(int j = i-1; j >= 0; j--){
                // target will monotonic increase
                int target = -(nums[i] + nums[j]);
                bool found = false;
                while(positive_ptr != n){
                    if(nums[positive_ptr] < target){
                        positive_ptr++;
                    }else if(nums[positive_ptr] == target){
                        if(!found){
                            answer_triplets.push_back(vector<int>({nums[i], nums[j], target}));
                            found = true;
                        }
                        positive_ptr++;
                    }else break;
                }
                
            }
        }
        return answer_triplets;
    }
};
