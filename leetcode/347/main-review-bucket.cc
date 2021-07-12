class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // freq_count[i] == # of nums having freq == i
        // because the number of frequency <= n
        vector<int> freq_count(n+1, 0);
        unordered_map<int, int> map;
        for(int num: nums){
            map[num]++;
        }
        for(auto it = map.begin(); it != map.end(); it++){
            freq_count[it->second]++;
        }
        
        int split_freq = -1;
        int acc = 0;
        for(int i = n; i >= 0; i--){
            acc += freq_count[i];
            if(acc == k){
                split_freq = i;
                break;
            }
        }
        assert(split_freq != -1);
        vector<int> ans;
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second >= split_freq) ans.push_back(it->first);
        }
        return ans;
    }
};
