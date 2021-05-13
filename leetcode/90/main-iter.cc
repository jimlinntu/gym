class Solution {
public:
    int find_section_end(vector<int> &nums, int i){
        int j = i;
        for(; j < nums.size(); j++) if(nums[i] != nums[j]) break;
        return j;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans = {{}};

        sort(nums.begin(), nums.end());
    
        for(int i = 0, j; i < n; i = j){
            j = find_section_end(nums, i);
            // Ex. [x, x, x]
            // --> [], [x], [x, x], [x, x, x]
            int num = nums[i];
            int ans_n = ans.size();
            // Ex. [1, 2, 3, 3, 3]
            // [1, 2]'s power set:
            // = {[], [1], [2], [1, 2]}
            // [3, 3, 3] power set:
            // [], [3], [3, 3], [3, 3, 3]
            // {[], [1], [2], [1, 2]} will be expanded 4 folds!
            vector<int> dup_subset;
            for(int k = 0; k < j-i; k++){
                dup_subset.push_back(num);
                for(int sidx = 0; sidx < ans_n; sidx++){
                    ans.push_back(ans[sidx]);
                    // Insert dup_subset in the back of ans.back()
                    ans.back().insert(ans.back().end(),
                                      dup_subset.begin(), dup_subset.end());
                }
            }
        }
        return ans;
    }
};
