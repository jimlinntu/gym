class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        int n = words.size();
        for(int i = 0; i < n; i++){
            map[words[i]] = i;
        }
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            string &w = words[i];
            // w acts as a left word
            for(int len = 0; len <= w.size(); len++){
                string left = w.substr(0, len);
                string mid = w.substr(len);
                if(!isP(mid)) continue;
                // left + mid + rev(left) forms a palindrome
                string rev_left(left.rbegin(), left.rend());
                auto it = map.find(rev_left);
                // cannot find a rev(left) in our word list
                if(it == map.end()) continue;
                // {i, j=it->second} can form a palindrome
                // NOTE: when len == w.size(), it might cause duplicates
                // Ex. w = aaaa, w' = aaaa
                // w, w' is a palindrome
                // w',w  is a palindrome
                // However, when words[i] == w', we will generate duplicate pairs
                // i == it->second will generate invalid pairs,
                // and i > it->second will generate duplicate pairs
                if(len == w.size() and i >= it->second) continue;
                ans.push_back({i, it->second});
            }
            // w acts as a right word
            for(int len = 0; len <= w.size(); len++){
                string right = w.substr(w.size()-len);
                string mid = w.substr(0, w.size()-len);
                if(!isP(mid)) continue;
                // rev(right) + mid + right forms a palindrome
                string rev_right(right.rbegin(), right.rend());
                auto it = map.find(rev_right);
                if(it == map.end()) continue;
                if(len == w.size() and i >= it->second) continue;
                ans.push_back({it->second, i});
            }
        }
        return ans;
    }

    bool isP(string &s){
        if(s.size() == 0) return true;
        int l = 0, r = s.size()-1;
        while(l <= r and s[l] == s[r]){
            l++, r--;
        }
        return l > r; // if l > r, then this is a palindrome
    }
};
