class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // The decreasing stack can emulate the greedily removing the smallest one approach
        // Because for each "valley", the smaller one must be merged with the largest one first
        // throughout the original greedy approarch.

        // The reason why it must be a decreasing stack is
        // An increasing stack will try to check the hill first rather than the valley first
        stack<int> s;
        int ans = 0;
        for(int num: arr){
            // Merged the valley
            while(!s.empty() and s.top() <= num){
                int to_merge = s.top();
                s.pop();
                // to_merge is merged with min(s.top(), num)
                if(s.empty()) ans += num * to_merge;
                else ans += min(s.top(), num) * to_merge;
            }
            s.push(num);
        }
        while(s.size() >= 2){
            int to_merge = s.top();
            s.pop();
            // to_merge is merged with s.top()
            ans += s.top() * to_merge;
        }
        assert(s.size() == 1);
        return ans;
    }
};
