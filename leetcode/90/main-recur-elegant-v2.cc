class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> ans;

    void backtrack(vector<int> &nums, int i){
        // This backtracking intuition is:
        // For each selection mask,
        // there must be one T starting from a number
        // or there are just all Fs
        // Ex. [1, 2, 3, 3, 3]
        //      F  F  F  F  F
        //      T ...........
        //      F  T  .......
        //      F  F  T .....
        //      F  F  F  T .. (x) <-- this will generate duplicates
        //      F  F  F  F  T (x) <-- this will generate duplicates
        //      F  F  F  F  F
        // NOTE: ... is where recursion magic happens
        // NOTE: for [3, 3, 3], we only want FFF, TFF, TTF, TTT!

        // Each number can be where the first starting T located
        for(int j = i; j < n; j++){
            if(j >= i+1 and nums[j-1] == nums[j]) continue;
            path.push_back(nums[j]);
            backtrack(nums, j+1);
            path.pop_back();
        }
        // Adding FFF...F
        ans.push_back(path);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        // Sort them so that duplicates will be consecutive
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
};
