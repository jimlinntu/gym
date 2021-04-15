class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<int> last(26, -1);
        int n = S.size();
        for(int i = 0; i < n; i++) last[S[i]-'a'] = max(last[S[i]-'a'], i);
        for(int i = 0; i < n; ){
            int next = i;
            int right = last[S[i]-'a'];
            assert(right != -1);
            // Keep pushing the right boundary as right as possible
            while(next <= right){
                right = max(right, last[S[next]-'a']);
                next++;
            }
            // Compute the partition [i, next)
            ans.push_back(next-i);
            i = next;
        }
        return ans;
    }
};
