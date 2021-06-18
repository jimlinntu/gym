
void update(vector<int> &bit, int i, int val){
    // propagate the information to the right
    for(; i < bit.size(); i += i & (-i)){
        bit[i] += val;
    }
}

// compute prefix sum over a virtual array (a 1-indexed array)
// i.e. sum(array within [1, i])
int query(vector<int> &bit, int i){
    int ret = 0;
    for(; i > 0; i -= i & (-i)){
        ret += bit[i];
    }
    return ret;
}

// compute triplet[i] on an array
int find_triplet(vector<int> &r){
    int n = r.size();
    vector<int> sorted = r;
    // map[value] = the index to the virtual array
    unordered_map<int, int> map;
    sort(sorted.begin(), sorted.end());
    // Map each value to their index to the virtual array
    // Ex. [2, 7, 9, 5, 4]
    // sorted == [2, 4, 5, 7, 8]
    // map[2] == 1, map[4] == 2, map[5] == 3, map[7] == 4, map[8] == 5
    // i.e:
    //                     2   4   5   7   8
    //                     v   v   v   v   v
    // The virtual array: [1] [2] [3] [4] [5]
    // You can see that whenever we perform a prefix sum on that array
    // we will only get the sum of things from smaller values!
    for(int v: sorted){
        int idx = map.size();
        map[v] = idx+1; // 1-index
    }

    // less[i] == sum(1 for j < i and r[j] > r[i])
    vector<int> less(n, 0);
    vector<int> bit_for_less(map.size()+1, 0);
    // triplet[i] == sum(1 for k < j < i and r[k] < r[j] < r[i])
    //            == sum(less[j] for j < i and r[j] < r[i])
    //               (Because for each triplet ending at r[i],
    //                it can choose any r[j] < r[i] and j < i to form a triplet)
    vector<int> triplet(n, 0);
    vector<int> bit_for_triplet(map.size()+1, 0);
    // Compute less[i]
    for(int i = 0; i < n; i++){
        // compute sum(1 for j < i and r[j] > r[i])
        // NOTE: 1. We have only seen numbers on the left so j < i is ensured
        //       2. Binary Indexed Tree will help us compute the prefix sum in O(log n)
        //       3. map[r[i]] will reindex to the virtual array so that every things
        //          in front of this index must be smaller than r[i]! See visualization above
        less[i] = query(bit_for_less, map[r[i]]);
        update(bit_for_less, map[r[i]], 1);
    }
    // Compute triplet[i]
    int s = 0;
    for(int i = 0; i < n; i++){
        // compute sum(less[j] for j < i and r[j] < r[i])
        triplet[i] = query(bit_for_triplet, map[r[i]]);
        s += triplet[i];
        // NOTE: You can imagine: array[r[i]] = less[i]
        update(bit_for_triplet, map[r[i]], less[i]);
    }
    return s;
}

class Solution {
public:
    int numTeams(vector<int>& r) {
        
        int ans = 0;
        ans += find_triplet(r);
        // reverse it and do it again
        // to compute > >
        reverse(r.begin(), r.end());
        ans += find_triplet(r);
        return ans;
    }
};
