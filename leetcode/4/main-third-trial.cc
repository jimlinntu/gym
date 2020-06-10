class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *a;
        vector<int> *b;
        
        // m <= n have several good properties
        // plus we can reduce the range when performing binary search
        if(nums1.size() > nums2.size()){
            a = &nums2;
            b = &nums1;
        }else{
            a = &nums1;
            b = &nums2;
        }
        
        // for the ease of access
        vector<int> &A = *a;
        vector<int> &B = *b;

        int m = A.size(), n = B.size();
        int left_size = (m+n+1)/2;
        int l = 0, r = m;
        int i, j;
        while(true){
            i = (l+r)/2; // A[0,i)
            j = left_size - i; // B[0, j)
            /*
              Note:
                 Originally, we need to check if j's range is in [0, n], but
                    m <= n give us these properties.
                 
                 (1) if i == m:
                        if m+n is odd:
                            j = (m+n+1)/2 - m >= (m+n+1)/2 - (m+m+1)/2 = (n-m)/2 >= 0
                        else:
                            j = (m+n)/2 - m = (m+n)/2 - (m+m)/2 = (n-m)/2 >= 0
                 (2) if i == 0:
                        if m+n is odd (in this case: m+1 <= n):
                            j = (m+n+1)/2 - 0 <= (n+n)/2 = n
                        else:
                            j = (m+n)/2 - 0 <= (n+n)/2 = n
            */
            assert(0 <= j <= n);
            /*
               Idea:
                   Originally, we want to find:
                    nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]

                   However, directly solve it is laborious (involving too much if else)
                   Therefore, we alternatively solve it by:
                   if nums1[i-1] > nums2[j] || nums2[j-1] > nums1[i]:
                   then: we continue the loop.
                   Turns out this logic is easier to write!
                 
                Note:
                (1) if i > 0:
                    similar to the above derivation, j < 0
                (2) if i < m:
                    similar to the above derivation, j > 0
            */
            if(i > 0 and A[i-1] > B[j]){
                r = i-1;
            }else if(i < m and B[j-1] > A[i]){
                l = i+1;
            }else{
                // if the code executes into this section, it means:
                // (A[i-1] <= B[j] && B[j-1] <= A[i]) condition are met
                double ans;
                if(i == 0){
                    ans = B[j-1];
                }else if(j == 0){
                    ans = A[i-1];
                }else{
                    ans = max(A[i-1], B[j-1]);
                }
                if((m+n)%2) return ans; // odd case
                
                if(i == m){
                    // if A[i] has no number, B[j] must have a number
                    // Otherwise, our right partition will be empty!!!
                    ans += B[j];
                }else if(j == n){
                    // Similarly, if B[j] has no number, A[i] must have a number
                    // Otherwise, our right partition will be empty!!!
                    ans += A[i];
                }else{
                    // Both nums have right numbers
                    ans += min(A[i], B[j]);
                }
                return ans / 2.;
            }
        }
    }
};
