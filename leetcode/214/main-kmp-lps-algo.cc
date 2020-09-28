class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string rev_s(s);
        reverse(rev_s.begin(), rev_s.end());
        string t = s + "#" + rev_s;
        // https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
        // lps (longest proper prefix which is also a suffix)
        // lps[i] == the lps of s[0:i]
        vector<int> lps(2*n+1);
        lps[0] = 0;
        int len = 0;
        for(int i = 1; i < 2*n+1; i++){
            if(t[i] == t[len]){
                lps[i] = ++len;
            }else{
                // if len == 0 or t[i] == t[len], our lps[i] value is determined
                while(len != 0 and t[i] != t[len]){
                    len = lps[len-1];  
                }
                // if t[i] and t[len] do not match, we do not add 1
                if(t[i] == t[len]) len++;
                lps[i] = len;
            }
        }
        // lps[2*n] == the longest palindrome
        // (i.e. s[0:t[2*n]-1] is the longest palindrome starting from the index 0)
        // Ex. aacecaaa
        //     ^^^^^^^  <--- is the longest palindrome
        // front == a (in this case)
        string front(s.begin()+lps[2*n], s.end());
        reverse(front.begin(), front.end());
        return front + s;
    }
};
