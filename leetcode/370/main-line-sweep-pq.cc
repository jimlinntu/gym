struct E{
    int end;
    int inc;
    bool operator>(const E &r) const{
        return end > r.end;
    }
};
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        sort(updates.begin(), updates.end());
        int cur = 0;
        int p = 0;
        priority_queue<E, vector<E>, greater<E>> pq;
        // Line sweeping
        for(int i = 0; i < length; i++){
            while(p < updates.size() and updates[p][0] == i){
                cur += updates[p][2]; // add its effect
                pq.push({updates[p][1], updates[p][2]});
                p++;
            }
            // pop outdated
            while(!pq.empty() and pq.top().end < i){
                cur -= pq.top().inc; // remove that range's inc
                pq.pop();
            }
            result[i] = cur;
        }
        return result;
    }
};
