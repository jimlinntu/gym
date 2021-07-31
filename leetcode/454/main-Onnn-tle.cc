class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());

        // O(n^3): Select two numbers from nums1, nums2 by i, j
        //         And then perform a two sum over nums3, nums4 by k, l
        int n = nums1.size();
        
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int t = -(nums1[i] + nums2[j]);
                int k = 0, l = n-1;
                // Two pointers
                while(k < n and l >= 0){
                    int s = nums3[k] + nums4[l];
                    if(s < t){
                        k++; // nums3[k] must be bigger
                    }else if(s > t){
                        l--; // nums4[l] must be smaller
                    }else{
                        // Ex. [2, 2, 2, 2], [4, 4, 4]
                        int prev_k = k, prev_l = l;
                        while(k+1 < n and nums3[k] == nums3[k+1]) k++;
                        while(l-1 >= 0 and nums4[l-1] == nums4[l]) l--;
                        
                        count += (k - prev_k + 1) * (prev_l - l + 1);

                        k++, l--;
                    }
                }
            }
        }
        return count;
    }
};
