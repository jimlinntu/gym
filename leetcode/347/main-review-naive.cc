class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int num: nums){
            map[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push({it->second, it->first});
        }
        vector<int> ans;
        int freq, num;
        while(k > 0){
            k--;
            tie(freq, num) = pq.top();
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};
