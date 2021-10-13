class Solution {
public:
    bool leq(string &prefix, string &word){
        int n = min(prefix.size(), word.size());
        for(int i = 0; i < n; i++){
            if(prefix[i] > word[i]) return false;
            if(prefix[i] < word[i]) return true;
        }
        // Same prefix! check size
        if(prefix.size() <= word.size()) return true;
        return false;
    }
    // prefix < word
    bool gt(string &prefix, string &word){
        int n = min(prefix.size(), word.size());
        for(int i = 0; i < n; i++){
            if(prefix[i] > word[i]) return false;
            if(prefix[i] < word[i]) return true;
        }
        return false;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = products.size();
        vector<vector<string>> ans;
        string prefix;
        for(int i = 0; i < searchWord.size(); i++){
            prefix += searchWord[i];
            // Bsearch first
            int l = 0, r = n;
            while(l < r){
                int mid = (l+r)/2;
                // prefix <= products[mid]
                if(leq(prefix, products[mid])){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }

            int start = l;
            // Bsearch second (upper bound)
            l = 0, r = n;
            while(l < r){
                int mid = (l+r)/2;
                if(gt(prefix, products[mid])){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            int end = l;

            ans.push_back({});
            for(int i = start; i < end; i++){
                ans.back().push_back(products[i]);
                if(ans.back().size() == 3) break;
            }
        }
        return ans;
    }
};
