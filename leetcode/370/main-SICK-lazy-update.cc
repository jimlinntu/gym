class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        // Intuition: lazy update!
        // [start, end, inc] -> result[start] += inc, result[end+1] -= inc
        // Ex. [0, 2, 0, -2]
        //  -> [0, 2, 2, 0, ]
        for(int i = 0; i < updates.size(); i++){
            int start = updates[i][0], end = updates[i][1], inc = updates[i][2];
            result[start] += inc;
            if(end+1 < length) result[end+1] -= inc;
        }
        for(int i = 1; i < length; i++){
            result[i] += result[i-1];
        }
        return result;
    }
};
