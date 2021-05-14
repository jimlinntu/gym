class Solution {
public:
    // table[i] == the alphabes digit i can represent
    vector<string> table = {"", "", "abc", "def", "ghi", "jkl",
                                "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string path;
    int n;

    void backtrack(string &digits, int i){
        if(i >= n){
            ans.push_back(path);
            return;
        }
        string &choices = table[digits[i]-'0'];
        for(int j = 0; j < choices.size(); j++){
            path.push_back(choices[j]);
            backtrack(digits, i+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        n = digits.size();
        if(n == 0) return ans;
        backtrack(digits, 0);
        return ans;
    }
};
