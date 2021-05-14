class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        // table[i] == the alphabes digit i can represent
        vector<string> table = {"", "", "abc", "def", "ghi", "jkl",
                                "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.size();
        if(n == 0) return ans;
        ans.push_back("");
        // A DP style iteration
        for(int i = 0; i < n; i++){
            int d = digits[i]-'0';
            int ans_n = ans.size();
            string &choices = table[d];
            for(int j = 0; j < ans_n; j++){
                // Each string can be expanded x fold
                // where x is determined by table[d].size();
                // Ex. 23
                // 2: [a, b, c]
                // 23: [a, b, c] + d, [a, b, c] + e, [a, b, c] + f
                for(int k = 1; k < choices.size(); k++){
                    ans.push_back(ans[j]);
                    ans.back().push_back(choices[k]);
                }
                // inplace expanding
                ans[j].push_back(choices[0]);
            }
        }
        return ans;
    }
};
