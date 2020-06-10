class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m == 0){
            if(n % 2){
                return nums2[(n+1)/2-1];
            }else{
                return (double)(nums2[n/2-1] + nums2[n/2])/2.;
            }
        }else if(n == 0){
            if(m % 2){
                return nums1[(m+1)/2-1];
            }else{
                return (double)(nums1[m/2-1] + nums1[m/2])/2.;
            }
        }
        
        int left_size = (m+n+1)/2;
        int l = 0, r = min(left_size, m);
        int i, j;
        while(true){
            i = (l+r)/2; // nums1[0,i)
            j = left_size - i; // nums2[0, j)

            // j is too big
            if(j > n){
                l = i+1;
                continue;
            }
            assert(i <= m and j <= n);
            
            /*
               Idea:
                   Originally, we want to find:
                    nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]

                   However, directly solve it is laborious (involving too much if else)
                   Therefore, we try to solve it by:
                   if nums1[i-1] > nums2[j] || nums2[j-1] > nums1[i]:
                   then: we continue the loop.
                   Turns out this logic is easier to write!
            */
            if(i > 0 and j < n and nums1[i-1] > nums2[j]){
                // if nums1[i-1] and nums2[j] have numbers and violate the condition
                r = i-1;
            }else if(i < m and j > 0 and nums2[j-1] > nums1[i]){
                // if nums1[m] and nums[j-1] have numbers
                l = i+1;
            }else{
                // if the code executes into this section, it means:
                // (nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i-1]) condition are met
                double ans;
                if(i == 0){
                    ans = nums2[j-1];
                }else if(j == 0){
                    ans = nums1[i-1];
                }else{
                    ans = max(nums1[i-1], nums2[j-1]);
                }
                if((m+n)%2) return ans; // odd case
                
                if(i == m){
                    // if nums1[i] has no number, nums2[j] must have a number
                    // Otherwise, our right partition will be empty!!!
                    ans += nums2[j];
                }else if(j == n){
                    // Similarly, if nums2[j] has no number, nums1[i] must have a number
                    // Otherwise, our right partition will be empty!!!
                    ans += nums1[i];
                }else{
                    // Both nums have right numbers
                    ans += min(nums1[i], nums2[j]);
                }
                return ans / 2.;
            }
        }
    }
};
