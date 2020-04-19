#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j){
    for(; i < j; i++, j--){
        if(s[i] != s[j]) return false; // do not allow second mismatch
    }
    // if i == j, then s[i] == s[j], no need to check(small speedup)
    return true;
}

class Solution{
public:
    bool validPalindrome(string s){
        // s.length() == 1 => i == j => return true
        for(int i = 0, j = s.length()-1; i < j; i++, j--){
            // find the first mismatch
            if(s[i] != s[j]){
                // (i+1, j): Skip i, (i, j-1): Skip j
                // Note: i+1 <= j because i < j
                // Note: i <= j-1 because i < j
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true; // all chars are the same
    }
};

int main(){
    Solution sol;
    string s;
    while(!cin.eof()){
        getline(cin, s);
        if(s.length() == 0) break;
        if(sol.validPalindrome(s)){
            cout << "True\n";
        }else cout << "False\n";
    }
}
