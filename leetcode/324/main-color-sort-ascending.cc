class Solution {
public:
    int quickselect(vector<int> &a, int start, int end){
        if(start >= end) return -1;
        int pivot = a[start];
        int left = start;
        for(int i = start+1; i < end; i++){
            if(a[i] < pivot){
                swap(a[++left], a[i]);
            }
        }
        swap(a[start], a[left]);
        return left;
    }
    int get_median(vector<int> &a){
        int n = a.size();
        shuffle(a.begin(), a.end(), default_random_engine(0));
        // When n is even, len(S) == n / 2, len(L) == n / 2
        // When n is odd, len(S) == (n+1)/2, len(L) == (n-1)/2
        // What we want to know is the largest number of S
        int median_idx = (n+1) / 2 - 1;
        int start = 0, end = n;
        while(start < end){
            int pivot_idx = quickselect(a, start, end);
            if(pivot_idx == median_idx) return a[pivot_idx];
            else if(pivot_idx < median_idx){
                start = pivot_idx+1;
            }else{
                end = pivot_idx;
            }
        }
        assert(false);
        return -1;
    }
    int reindex(int i, int n){
        int ret;
        if(n % 2 == 0){
            ret = n-2-2*i;
            if(ret < 0) ret += n+1;
        }else{
            ret = n-1-2*i;
            if(ret < 0) ret += n;
        }
        return ret;
    }
    void wiggleSort(vector<int>& nums) {
        // O(n) (in average) quick select algorithm
        int median = get_median(nums);
        // Apply color sorting (or three-way partitioning or Dutch national flag algorithm)
        int n = nums.size();
        int idx_for_less = 0, idx_for_greater = n-1;
        // NOTE: i <= idx_for_greater because there might be case like
        // [0, 1, 1, 1, 1, 0, 2]
        //                 ^<----- idx_for_greater
        for(int i = 0; i <= idx_for_greater;){
            if(nums[reindex(i, n)] < median){
                // Place this < median number in front of the array
                swap(nums[reindex(i++, n)], nums[reindex(idx_for_less++, n)]);
            }else if(nums[reindex(i, n)] > median){
                swap(nums[reindex(i, n)], nums[reindex(idx_for_greater--, n)]);
            }else i++;
        }
    }
};
