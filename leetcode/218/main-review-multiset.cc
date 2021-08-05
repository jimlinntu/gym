class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> v;
        for(auto &b: buildings){
            int l = b[0], r = b[1], h = b[2];
            v.push_back({l, -h});
            v.push_back({r,  h});
        }
        sort(v.begin(), v.end());

        multiset<int, greater<int>> tree; // maximum at front
        tree.insert(0);

        vector<vector<int>> ans;
        for(int i = 0; i < v.size(); i++){
            int x = v[i][0], h = v[i][1];
            int prev_h = *tree.begin();
            if(h < 0){
                h = -h;
                tree.insert(h);
                int after_h = *tree.begin();
                if(prev_h < after_h) ans.push_back({x, after_h});
            }else{
                // remove a height
                // NOTE: we need to start from the smallest height
                tree.erase(tree.find(h));
                int after_h = *tree.begin();
                if(prev_h > after_h) ans.push_back({x, after_h});
            }
        }
        return ans;
    }
};
