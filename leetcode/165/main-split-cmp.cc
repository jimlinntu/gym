class Solution {
public:
    void parse(string &s, vector<int> &v){
        string::size_type idx = 0, next;
        while((next = s.find('.', idx)) != string::npos){
            v.push_back(stoi(s.substr(idx, next-idx)));
            idx = next+1;
        }
        v.push_back(stoi(s.substr(idx)));
        return;
    }
    int compareVersion(string version1, string version2) {
        vector<int> left, right;
        parse(version1, left);
        parse(version2, right);
        // Compare
        int m = left.size(), n = right.size();
        int mn = min(m, n);
        for(int i = 0; i < mn; i++){
            if(left[i] > right[i]) return 1;
            if(left[i] < right[i]) return -1;
        }
        for(int i = mn; i < m; i++){
            if(left[i] > 0) return 1;
        }
        for(int i = mn; i < n; i++){
            if(right[i] > 0) return -1;
        }
        return 0;
    }
};
