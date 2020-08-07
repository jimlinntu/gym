class Solution {
public:
    unordered_map<int, int> cache;
    int compute(int n){
        if(n == 0) return 0;
        // Use the cache result
        auto it = cache.find(n);
        if(it != cache.end()) return it->second;

        int upper = (int)sqrt(n);
        int m = n;
        // Test every branches to see which one is better
        for(int i = upper; i > 0; i--){
            m = min(compute(n - i*i), m);
        }

        m++; // add the subtraction from itself to its children
        cache[n] = m;
        return m;
    }

    int numSquares(int n){
        return compute(n);
    }
};
