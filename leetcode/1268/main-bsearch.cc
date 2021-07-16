const int MAX_PROD = 3;

class Solution {
public:
    bool contain(string &prefix, string &p){
        if(prefix.size() > p.size()) return false;
        for(int i = 0; i < prefix.size(); i++){
            if(prefix[i] != p[i]) return false;
        }
        return true;
    }

    int cmp(string &prefix, string &p){
        // Case 1: if p contains prefix: return 0
        // Case 2: if prefix > p: return 1
        // Case 3: if prefix < p: return -1
        
        if(contain(prefix, p)) return 0;
        if(prefix > p) return 1;
        return -1;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int m = products.size();
        int n = searchWord.size();
        // O(m log m)
        sort(products.begin(), products.end());

        vector<vector<string>> ans(n);
        // Search for the leftmost matching
        // O(n) * (O(log m) + O(3))
        for(int i = 0; i < n; i++){
            int l = 0, r = m;
            string prefix = searchWord.substr(0, i+1);
            while(l < r){
                int mid = (l+r)/2;
                int ret = cmp(prefix, products[mid]);
                if(ret == 0) r = mid;
                else if(ret == -1) r = mid;
                else l = mid+1;
            }
            // The first index j s.t. products[j] >= p
            int ub = min(l+MAX_PROD, m);
            for(int j = l; j < ub; j++){
                // p > prefix
                // NOTE: directly using p > prefix will not be correct!
                // Ex. products = [hat], searchWord = [ha]
                // hat should be output, but hat > ha
                // That's why we still have to implement this compare function by ourself
                if(cmp(prefix, products[j]) == -1) break;
                ans[i].push_back(products[j]);
            }
        }
        return ans;
    }
};
