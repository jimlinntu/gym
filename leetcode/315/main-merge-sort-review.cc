class Solution {
public:
    void mergesort(vector<int> &nums, vector<int> &indices,
                   vector<int> &result, int l, int r){
        if(r-l == 1) return;

        int mid = (l+r)/2;
        mergesort(nums, indices, result, l, mid);
        mergesort(nums, indices, result, mid, r);

        vector<int> merged(r-l);
        int p = 0;
        int p1 = l, p2 = mid;
        while(p1 < mid and p2 < r){
            // Ex. a1 a2 a3, b1 b2 b3
            //        p1           p2
            // When a2 <= b3, it means there are 2 elements on the b array < a2!
            // NOTE: when a == b, we must put a's number first!
            //       Otherwise, the answer will be wrong
            if(nums[indices[p1]] <= nums[indices[p2]]){
                // # of elements on b < this number
                // or [mid, p2) are smaller than this number(nums[indices[p1]])
                result[indices[p1]] += p2-mid;
                merged[p++] = indices[p1];
                p1++;
            }else{
                merged.push_back(indices[p2]);
                merged[p++] = indices[p2];
                p2++;
            }
        }
        // Case 1: p2 == r
        while(p1 < mid){
            result[indices[p1]] += r-mid;
            merged[p++] = indices[p1];
            p1++;
        }
        while(p2 < r){
            merged[p++] = indices[p2];
            p2++;
        }
        for(int i = 0; i < r-l; i++){
            indices[l+i] = merged[i];
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<int> indices(n);
        for(int i = 0; i < n; i++) indices[i] = i;

        mergesort(nums, indices, result, 0, n);
        return result;
    }
};
