/*
2reductor array
对于两个integer arrays, the comparator value 是total number of elements in the 1st array that there exist no interger in the 2nd arrat with a abs diff <= d. 返回comparator value
eg: [7,5,9][13,1,4] d=3
7-13 = 6 7-1=6 7-4 = 3 3<=d no
5-13 > d 5-1>d 5-4<d no
9-13>d 9-1>d 9-3>d right return  1
 */

#include <bits/stdc++.h>
using namespace std;

// Find the first index s.t. b[i] >= lb
int lb_bsearch(vector<int> &b, int lb){
    int l = 0, r = b.size();
    while(l < r){
        int mid = (l+r)/2;
        if(b[mid] < lb){
            l = mid + 1;
        }else if(b[mid] >= lb){
            r = mid;
        }
    }
    return l;
}
// Find the first index s.t b[i] > ub
int ub_bsearch(vector<int> &b, int ub){
    int l = 0, r = b.size();
    while(l < r){
        int mid = (l+r)/2;
        if(b[mid] <= ub){
            l = mid + 1; // [l, mid] <= ub, we should move right
        }else if(b[mid] > ub){
            r = mid; // [mid, l] > ub, we should move left
        }
    }
    return l;
}

int solve(vector<int> a, vector<int> b, int d){
    assert(d >= 0);
    sort(b.begin(), b.end());
    int ans = 0;
    // Overall: m = a.size(), n = b.size()
    // O(nlogn) + O(m log n)
    for(int i = 0; i < a.size(); i++){
        // O(log b.size())
        /* auto lb = lower_bound(b.begin(), b.end(), a[i] - d); */
        /* auto ub = upper_bound(b.begin(), b.end(), a[i] + d); */
        int lb = lb_bsearch(b, a[i]-d);
        int ub = ub_bsearch(b, a[i]+d);

        if(ub - lb == 0){
            ans++;
        }
    }
    return ans;
}

// Sliding window: O(mlogm) + O(n log n) + O(m+n)
int solve2(vector<int> a, vector<int> b, int d){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int p = 0;
    int ans = 0;
    deque<int> q;
    for(int i = 0; i < a.size(); i++){
        // adding numbers in a[i]+d]
        while(p < b.size() and b[p] <= a[i]+d){
            q.push_back(b[p++]);
        }
        // pop things not in [a[i]-d, a[i]+d]
        // because a[i] <= a[j] where i <= j
        // x < a[i]-d => x < a[j]-d
        // Therefore, we can safely delete that
        while(!q.empty() and q.front() < a[i]-d){
            q.pop_front();
        }
        if(q.empty()){
            ans++;
        }
    }
    return ans;
}

int main(){
    cout << solve2({7, 5, 9}, {13, 1, 4}, 3) << endl;
    return 0;
}
