struct Hasher{
    size_t operator()(const pair<int, int> &p) const{
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    // dp_cached((amt, i)) == the fewest number of coins from 0 to i (i.e. [0, i])
    unordered_map<pair<int, int>, int, Hasher> dp_cached;

    int dp(int amt, int i, vector<int> &coins){
        // Base cases
        if(amt == 0) return 0;
        // if it can be divided by coins[i], directly return the optimal solution
        if(amt % coins[i] == 0) return amt / coins[i];
        // if it cannot be divided by coins[i], and it is the last one, return -1
        if(i == 0) return -1;
        auto it = dp_cached.find({amt, i});
        if(it != dp_cached.end()) return it->second;
        int max_num_coin = amt / coins[i];
        int minimum = -1; // the initial value of minimum is -1 (invalid)
        for(int ii = 0; ii <= max_num_coin; ii++){
            // use `ii` `coins[i]`
            int num_coin = dp(amt - ii * coins[i], i-1, coins);
            if(num_coin == -1) continue; // invalid
            if(minimum == -1) minimum = ii + num_coin;
            else minimum = min(ii + num_coin, minimum);
        }
        // cache it
        dp_cached[{amt, i}] = minimum;
        return minimum;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        assert(n >= 1);
        sort(coins.begin(), coins.end());
        return dp(amount, n-1, coins);
    }
};
