int reindex(int i, int n){
    // See my illustrations for more info
    return (1 + 2 * i) % (n | 1);
}

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // Descending
        vector<int> c = nums;
        sort(c.begin(), c.end(), greater<int>());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[reindex(i, n)] = c[i];
        }
    }
};  
