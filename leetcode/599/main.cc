class Solution {
public:
    unordered_map<string, pair<int, int>> map; // map[string] = (indexsum, ref count)
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int m = list1.size();
        int n = list2.size();
        int minimum = m+n;
        vector<string> ans;
        for(int i = 0; i < m; i++){
            map[list1[i]] = {i, 1};
        }
        for(int i = 0; i < n; i++){
            auto it = map.find(list2[i]);
            if(it != map.end()){
                it->second.first += i; // indexsum
                it->second.second += 1; // increment reference count

                if(it->second.first < minimum) minimum = it->second.first;
            }else{
                map[list2[i]] = {i, 1};
            }
        }
        // only consider values of reference count == 2
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second.second == 2 and it->second.first == minimum)
                ans.push_back(it->first);
        }
        return ans;
    }
};
