class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Ex. [(7, 0), (4, 4), (7, 1), (5, 0), (6, 1), (5,2)]
        // after sorted:
        // (7, 0), (7, 1), (6, 1), (5, 0), (5, 2), (4, 4)
        // When we see (7, 0) at first, we will know that no matter what numbers
        // we put in front of it, they will not affect its 'k' value (except 7 itself)
        // So we can safely put 7 at first
        // Then we see (7, 1), we know that 7 is already the greatest number
        // so the only way we can increase its 'k' value to 1 is to put it after 7
        // ==> (7, 0), (7, 1)
        // And then we see (6, 1), we know that anything smaller than 6 will not affect
        // its 'k', we know that we can just put 6 after one 7
        // ==> (7, 0), (6, 1), (7, 1)
        //
        // Then we know (5, 0), (5, 2) follows
        // Let's say we first consider (5, 2)
        // we will get (7, 0), (6, 1), (5, 2), (7, 1), but we soon find that
        // if we put (5, 0) at front, (5, 2)'s k becomes 3, which is wrong!!!
        // So we should first put (5, 0) first, and then consider (5, 2) later!
        int n = people.size();
        vector<vector<int>> q;
        sort(people.begin(), people.end(), [](
            const vector<int> &left, const vector<int> &right) -> bool{
            // if left's h > right'h, left should go before right
            if(left[0] > right[0]) return true;
            if(left[0] == right[0]) return (left[1] < right[1]);
            return false;
        });

        for(int i = 0; i < n; i++){
            int h = people[i][0];
            int k = people[i][1];
            q.insert(q.begin()+k, {h, k});
        }
        
        return q;
    }
};
