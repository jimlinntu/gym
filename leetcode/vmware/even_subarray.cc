#include<bits/stdc++.h>
using namespace std;

struct Hasher{
    size_t operator()(const vector<int> &v) const{
        size_t h = 0;
        for(int e: v) h = (h << 1) ^ hash<int>()(e);
        return h;
    }
};

int solve(vector<int> a, int k){
    // Count # of "distinct" subarrays that can be formed at most `k` of odd elements
    int n = a.size();
    int count_odd = 0;
    unordered_set<vector<int>, Hasher> s;
    int l = 0;
    int ans = 0;
    // Overall: O(n) * O(n) <-- hash finding
    for(int r = 0; r < n; r++){
        // add a[r]
        if(a[r] % 2 == 1) count_odd++;
        // move l until [l, r]'s count_odd <= k
        while(l <= r and count_odd > k){
            if(a[l] % 2 == 1) count_odd--;
            l++;
        }
        // [l, r] is the longest window ending at r
        if(l > r) continue;
        vector<int> tmp(a.begin()+l, a.begin()+r+1);
        // Ex. [1, 2, 3, 4, 5] -> [5, 4, 3, 2, 1]
        reverse(tmp.begin(), tmp.end()); // reverse because we want to pop the leftmost element first
        int len = tmp.size();
        for(int i = 0; i < len; i++){
            if(s.count(tmp) == 0){
                /* for(auto it = tmp.rbegin(); it != tmp.rend(); it++) cout << *it << ","; */
                /* cout << endl; */
                ans++;
                s.insert(tmp); // put it into the hash table
            }
            tmp.pop_back();
        }
    }
    return ans;
}

int main(){
    /* cout << solve({1, 2, 3, 4}, 1) << endl; */
    cout << solve({1, 2, 3, 4, 1, 2, 3, 4}, 1) << endl;
    return 0;
}
