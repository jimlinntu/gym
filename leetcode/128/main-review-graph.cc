class Solution {
public:
    void dfs(int startnum, int &count,
            unordered_map<int, vector<int>> &g, unordered_map<int, bool> &visit){
        if(visit[startnum]) return;

        count++;
        visit[startnum] = true;
        for(int nei: g[startnum]){
            dfs(nei, count, g, visit);
        }
        return;
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, vector<int>> g;
        int n = nums.size();
        // O(n)
        for(int i = 0; i < n; i++){
            if(g.find(nums[i]-1) != g.end()){
                g[nums[i]-1].push_back(nums[i]);
                g[nums[i]].push_back(nums[i]-1);
            }
            
            if(g.find(nums[i]+1) != g.end()){
                g[nums[i]+1].push_back(nums[i]);
                g[nums[i]].push_back(nums[i]+1);
            }
            g[nums[i]]; // touch it
        }
        // DFS to find the maximum length of a tree in the forest
        unordered_map<int, bool> visit;
        int max_len = 0;
        for(auto &kv: g){
            int count = 0;
            dfs(kv.first, count, g, visit);
            max_len = max(max_len, count);
        }
        return max_len;
    }
};
