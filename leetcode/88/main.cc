class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        assert(nums1.size() == m + n);
        int i = m-1, j = n-1;
        int k = m+n-1;
        // fill numbers backward
        while(i >= 0 or j >= 0){
            if(i >= 0 and j >= 0){
                // put this number to nums1[k]
                if(nums1[i] > nums2[j]){
                    nums1[k] = nums1[i--];
                }else{
                    nums1[k] = nums2[j--];
                }
            }else if(i >= 0){
                assert(k == i); // it will just be the same
                nums1[k] = nums1[i--];
            }else{
                nums1[k] = nums2[j--];
            }
            k--;
        }
    }
};
