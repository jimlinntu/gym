class Solution {
public:
    int quickselect(vector<pair<int, int>> &v, int start, int end){
        if(start >= end) return -1;
        auto pivot = v[start];
        int left = start;
        for(int i = start+1; i < end; i++){
            // Put the larger number on the left
            if(v[i].first >= pivot.first){
                left++;
                swap(v[i], v[left]);
            }
        }
        swap(v[start], v[left]);
        return left;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num]++;
        }
        vector<pair<int, int>> v;
        for(auto it = freq.begin(); it != freq.end(); it++){
            // (freq, num) 
            v.push_back({it->second, it->first});
        }

        shuffle(v.begin(), v.end(), default_random_engine(0));
        int start = 0, end = v.size();
        while(start < end){
            int pidx = quickselect(v, start, end);
            if(pidx == k-1) break;
            else if(pidx < k-1){
                start = pidx+1;
            }else{
                end = pidx;
            }
        }

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
