struct E{
    int profit, capital;
    bool operator<(const E &right) const{
        return this->capital < right.capital;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<E> v;
        for(int i = 0; i < n; ++i){
            v.push_back({profits[i], capital[i]});
        }
        // sort from the least capital to the most
        // O(n log n)
        sort(v.begin(), v.end());
        // We can at most choose n projects
        k = min(k, n);
        // Choose projects to work on
        int end = 0;
        priority_queue<int> pq; // max PQ
        for(int i = 0; i < k; ++i){
            // if we have enough capital to start this project
            // at most add n projects so the complexity of this loop is O(n log n) overall
            while(end < n and v[end].capital <= w){
                pq.push(v[end].profit);
                end++;
            }
            // we have no choices, break and end the loop
            if(pq.empty()) break;
            // Choose the most profitable project and add the project into the capital
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
