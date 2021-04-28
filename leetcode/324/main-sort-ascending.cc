int reindex(int i, int n){
    // See my illustrations for more info
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

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // Ascending
        vector<int> c = nums;
        sort(c.begin(), c.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[reindex(i, n)] = c[i];
        }
    }
};  
