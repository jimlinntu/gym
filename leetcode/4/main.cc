class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double ans;
        // handle edge cases
        if(m == 0){
            if(n % 2 == 0){
                ans = nums2[n/2-1] + nums2[n/2];
                ans /= 2.;
            }else{
                ans = nums2[(n+1)/2-1];
            }
            return ans;
        }else if(n == 0){
            if(m % 2 == 0){
                ans = nums1[m/2-1] + nums1[m/2];
                ans /= 2.;
            }else{
                ans = nums1[(m+1)/2-1];
            }
            return ans;
        }
        assert(m >= 1 && n >= 1);
        
        // the total number of elements on the left side
        int total = (m+n+1)/2; // a small integer trick here
        // the nums1 left partition size boundary
        int l = 0, r = min(total, m);
        int size1, size2;
        
        while(true){
            // size1 is for nums1, size2 is for nums2
            size1 = (l+r)/2;
            size2 = total - size1;
            if(l == r) break;
            if(n < size2){
                l = size1+1;
                continue;
            }
            // handle edge cases
            if(size1 == 0){
                if(nums2[size2-1] <= nums1[size1]){
                    break;
                }else if(nums2[size2-1] > nums1[size1]){
                    l = size1+1;
                    continue;
                }else assert(false);
            }else if(size2 == 0){
                if(nums1[size1-1] <= nums2[size2]){
                    break;
                }else if(nums1[size1-1] > nums2[size2]){
                   r = size1-1;
                    continue;
                }else assert(false);
            }else if(size1 == m){
                if(nums1[size1-1] <= nums2[size2]){
                    break;
                }else if(nums1[size1-1] > nums2[size2]){
                    r = size1-1;
                    continue;
                }else assert(false);
            }else if(size2 == n){
                if(nums2[size2-1] <= nums1[size1]){
                    break;
                }else if(nums2[size2-1] > nums1[size1]){
                    l = size1+1;
                    continue;
                }else assert(false);
            }
            
            if(nums1[size1-1] <= nums2[size2] &&
               nums2[size2-1] <= nums1[size1]){
                break;
            }else if(nums1[size1-1] > nums2[size2]){
                r = size1-1;
            }else if(nums2[size2-1] > nums1[size1]){
                l = size1+1;
            }else{
                // this should not happen
                // Ex. x1 x2 | x3 x4
                //     y1 y2 | y3 y4
                //    x2 > y3 and y2 > x3
                // => x2 > y3 >= y3 > x3 (contradiction to x2 <= x3)
                assert(false);
            }
        }

        if((m+n)%2 == 0){
            // left side
            if(size1 == 0){
                ans = nums2[size2-1];
            }else if(size2 == 0){
                ans = nums1[size1-1];
            }else{
                ans = max(nums1[size1-1], nums2[size2-1]);
            }
            // right side
            if(size1 == m){
                ans += nums2[size2];
            }else if(size2 == n){
                ans += nums1[size1];
            }else{
                ans += min(nums1[size1], nums2[size2]);
            }
            return ans / 2;
        }else{
            // Only need to know the max of the left side elements
            if(size1 == 0){
                ans = nums2[size2-1];
            }else if(size2 == 0){
                ans = nums1[size1-1];
            }else{
                ans = max(nums1[size1-1], nums2[size2-1]);
            }
            return ans;
        }
    }
};
