class Solution {
public:
    int qselect(vector<pair<int, int>> &arr,
                int start, int end){
        // [start, end)
        int split_freq = arr[start].first;
        int idx = start;
        for(int i = start+1; i < end; i++){
            // swap to the left halve
            // left halve >= right halve
            if(arr[i].first >= split_freq) swap(arr[++idx], arr[i]);
        }
        // put arr[start] to the split point
        swap(arr[start], arr[idx]);
        return idx;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<pair<int, int>> arr;
        for(int num: nums) map[num]++;
        for(auto &it: map){
            // {freq, num}
            arr.push_back({it.second, it.first});
        }
        assert(k <= arr.size());
        // make it random order to speed up qselect
        shuffle(arr.begin(), arr.end(), default_random_engine(0));
        // arr[i] == {freq, num}
        // Perform qselect on the first element of arr[i]
        int start = 0, end = arr.size();
        while(start < end){
            int pivot = qselect(arr, start, end);
            if(pivot == k-1) break;
            else if(pivot > k-1){
                end = pivot;
            }else{
                start = pivot+1;
            }
        }
        // arr[0] ~ arr[k-1] are the k most frequent elements
        vector<int> ans;
        for(int i = 0; i <= k-1; i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
