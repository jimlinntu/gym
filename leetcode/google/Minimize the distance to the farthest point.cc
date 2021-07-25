#include <bits/stdc++.h>
using namespace std;

int brute_force(){
    int min_dist = INT_MAX;
    for(int i = 0; i < n; i++){
        unordered_set<int> reqs = {0, 1,2};
        // find the minimum distance
        int d = 0;
        for(d = 0; d <= n-1; d++){
            // i-d ... i ... i+d
            if(i-d >= 0)
                for(int r: block[i-d]){
                    reqs.erase(r);
                }
            if(i+d < n)
                for(int r: block[i+d]){
                    reqs.erase(r);
                }
            // all requirements are satisfied
            if(reqs.size() == 0) break;
        }
        // minimum distance to satisfy all requirements
        min_dist = min(min_dist, d);
    }
}

// O(nm): if n = # of blocks, m = # of requirements
int sliding_window(vector<vector<int>> &block, vector<int> &reqs){
    // window[j] == how many j requirement is inside this window
    unordered_map<int, int> window;
    for(int i: reqs){
        window[i] = 0;
    }
    int win_count = 0;

    int r = 0;
    int best_i = -1;
    int min_win_dist = INT_MAX;
    for(int i = 0; i < n; i++){
        while(r < n and win_count != window.size()){
            for(int j: block[r]){
                // not in the requirements, we don't care
                if(window.find(j) == window.end()) continue;
                if(window[j]++ == 0) win_count++; // # of requirments satisfied
            }
            r++;
        }

        if(win_count != window.size()) break;

        // [i, r) contains all requirements
        if(r-i < min_win_dist){
            min_win_dist = r-i;
            best_i = i;
        }

        // leaving i, remove it
        for(int j: block[i]){
            if(window.find(j) == window.end()) continue;
            if(--window[j] == 0) win_count--;
        }

    }
    // leave at the middle of this window
    return best_i + min_win_dist / 2;
}

int forward_backward_dp(){
    vector<vector<int>> fdp(n, vector<int>(m, INT_MAX));
    vector<vector<int>> bdp(n, vector<int>(m, INT_MAX));
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    for(int j: block[0]){
        fdp[0][j] = 0;
    }

    // Forward DP: look left
    for(int i = 1; i < n; i++){
        for(int j: block[i]){
            fdp[i][j] = 0;
        }

        for(int j = 0; j < m; j++){
            if(fdp[i][j] != INT_MAX) continue;

            // dp step
            if(fdp[i-1][j] != INT_MAX)
                fdp[i][j] = fdp[i-1][j]+1;
        }
    }

    for(int j: block[n-1]){
        bdp[n-1][j] = 0;
    }

    // Backward DP: look right
    for(int i = n-2; i >= 0; i--){
        for(int j: block[i]){
            bdp[i][j] = 0;
        }

        for(int j = 0; j < m; j++){
            if(bdp[i][j] != INT_MAX) continue;

            if(bdp[i+1][j] != INT_MAX)
                bdp[i][j] = bdp[i+1][j]+1;
        }
    }

    int ans_i = -1;
    int ans_d = INT_MAX;
    for(int i = 0; i < n; i++){
        int farest_d = 0;
        for(int j = 0; j < m; j++){
            dp[i][j] = min(fdp[i][j], bdp[i][j]);
            farest_d = max(dp[i][j], farest_d);
        }

        if(farest_d < ans_d){
            ans_d = farest_d;
            ans_i = i;
        }
    }
    return ans_i;
}
