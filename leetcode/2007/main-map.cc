class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> map;
        for(int num: changed){
            map[num]++;
        }
        vector<int> ans;
        if(map.count(0)){
            // odd, no way!
            if(map[0] % 2) return {};
            for(int i = 0; i < map[0]/2; i++){
                ans.push_back(0);
            }
            map.erase(0);
        }
        // [1, 1, 1, 2, 2, 2]
        // O(n/2 log n)
        while(!map.empty()){
            // Take the smallest and its double
            int num = map.begin()->first;
            ans.push_back(num);
            if(map.count(2*num) == 0) return {};
            // Pair out {num, 2*num}
            if(--map[num] == 0) map.erase(num);
            if(--map[2*num] == 0) map.erase(2*num);
        }
        return ans;
    }
};
