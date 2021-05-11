class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    unordered_map<int, int> counter; // represent how many choices we have now
    void solve(){
        // choices we can make in this step
        vector<int> choices;
        for(auto it = counter.begin(); it != counter.end(); it++){
            choices.push_back(it->first);
        }
        if(choices.size() == 0){
            ans.push_back(path);
            return;
        } 
        for(int num: choices){
            path.push_back(num);
            // remove the num from the hash table
            if(--counter[num] == 0) counter.erase(num);
            solve();
            path.pop_back();
            counter[num]++; // put it back
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int num: nums){
            counter[num]++;
        }
        solve();
        return ans;
    }
};
