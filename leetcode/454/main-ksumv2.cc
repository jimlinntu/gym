class Solution {
public:
    // map[a+b+c+d+...] == frequency of it
    void build_ht(vector<vector<int>> &v, int left, unordered_map<int, int> &map,
                  int s){
        if(left == 0){
            map[s]++;
            return;
        }
        auto &nums = v[left-1]; // the last array
        for(int num: nums){
            build_ht(v, left-1, map, s+num);
        }
    }
    // probe if -(q+p+r+....) exists in the hash table
    void probe_ht(vector<vector<int>> &v, int left, unordered_map<int, int> &map,
                 int s, int &count){
        if(left == v.size()){
            if(map.count(-s)){
                count += map[-s];
            }
            return;
        }

        auto &nums = v[left];
        for(int num: nums){
            probe_ht(v, left+1, map, s+num, count);
        }
    }

    int ksumv2(vector<vector<int>> &v){
        int k = v.size();
        int n = v[0].size();
        // NOTE, when k is odd, left will be smaller
        // This is the desired result because we want space usage be smaller as possible
        int left = k/2;
        int right = k - left;
        // Build a hash table
        unordered_map<int, int> map;
        map.reserve(1000000);

        build_ht(v, left, map, 0);
        int count = 0;
        probe_ht(v, left, map, 0, count);
        return count;
    }
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<vector<int>> v = {nums1, nums2, nums3, nums4};
        return ksumv2(v);
    }
};
