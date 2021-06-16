struct Info {
    int x; // its x axis
    int type; // 1 for left edge, 2 for right edge (left edge will come first)
    int bidx; // buildings' index
    int neg_h;
    vector<int> v;
    Info(int xx, int ttype, int h, int bbidx): x(xx), type(ttype), neg_h(h), bidx(bbidx){
        v = {xx, ttype, neg_h, bbidx}; // used for comparison
    }
    bool operator<(const Info &r) const{
        return v < r.v;
    }
};

void update(vector<int> &bit, int i, int val){
    // propagate the information to the left
    for(; i > 0; i -= i & (-i)){
        bit[i] = max(bit[i], val);
    }
}

// Compute suffix max (i.e. bit[i] == max(array[i:]))
// NOTE: array is virtual, but conceptually you can imagine it exists
int query(vector<int> &bit, int i){
    // get the information all the way to the right (suffix)
    int mx = 0; // if there is no thing on the right, mx == 0 because it is ground
    for(; i < bit.size(); i += i & (-i)){
        mx = max(mx, bit[i]);
    }
    return mx;
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Info> infos;
        for(int i = 0; i < buildings.size(); i++){
            auto &b = buildings[i];
            int l = b[0], r = b[1], h = b[2];
            infos.emplace_back(l, 1, -h, i); // -h we want higher to appear first
            infos.emplace_back(r, 2, -h, i);
        }
        // sort by their x and its type(left or right)
        sort(infos.begin(), infos.end());

        // Discretize critical points
        // map[x] == [0, 1, 2, ...]
        int idx = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < infos.size(); i++){
            // NOTE: if there are duplicate x's, we can randomly choose one
            // (Here we just simply choose the last one)
            map[infos[i].x] = ++idx;
        }

        // Binary Indexed Tree
        vector<int> bit(idx+1, 0);
        vector<vector<int>> ans;

        for(int i = 0; i < infos.size(); i++){
            int x = infos[i].x;
            // prev_h == the height before we leave this point
            int prev_h = query(bit, map[x]);
            auto &b = buildings[infos[i].bidx];
            int l = b[0], r = b[1], h = b[2];

            if(infos[i].type == 1){
                // Add h to the right at map[r]
                // (i.e. array[map[r]] = h, but notice that array is virtual)
                // NOTE: we use map[r] to get r's index on our discretized array
                update(bit, map[r], h);
                // cur_h is the height after leaving the current point
                // NOTE: +1 is because of [l, r)
                int cur_h = query(bit, map[x]+1);

                if(cur_h != prev_h){
                    ans.push_back({x, cur_h});
                }
            }else{
                // NOTE: because we sort the infos by their x axis and type
                //       left edge must come first then right edge!
                // cur_h is the height after leaving this building
                int cur_h = query(bit, map[x]+1);
                // Edge case: overlapped right edges
                if(ans.size() > 0 and ans.back()[0] == x){
                    // do nothing because this key point has already been
                    // added by a left edge or a right edge on the same x
                }else if(cur_h != prev_h){
                    ans.push_back({x, cur_h});
                }
            }
        }
        return ans;
    }
};
