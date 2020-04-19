#include <bits/stdc++.h>
using namespace std;

bool check(string &s){
    int length = s.length();
    bool is_valid = true;
    // two pointers move closer and match
    bool can_jump = true;
    int i = 0, j = length-1;
    int mismatch_i = -1, mismatch_j = -1;
    // Only allow i to skip
    for(; i < j;){
        // match
        if(s[i] == s[j]){
            i++, j--;
            continue;
        }
        // character lookahead
        if(can_jump){
            mismatch_i = i, mismatch_j = j; // the first mismatch we have met
            if(i < length-1 && s[i+1] == s[j]){
                i++;
            }else{
                is_valid = false;
                break;
            }
            can_jump = false; // disable jump flag
        }else{
            is_valid = false;
            break;
        }
    }
    if(is_valid) return true;
    // This time allow j to skip and check the string again
    i = mismatch_i, j = mismatch_j;
    can_jump = true;
    for(; i < j;){
        // match
        if(s[i] == s[j]){
            i++, j--;
            continue;
        }
        // char lookahead
        if(can_jump){
            if(j >= 1 && s[j-1] == s[i]){
                j--;
            }else{
                return false;
            }
            can_jump = false;
        }else{
            return false;
        }
    }
    return true;
}

class Solution{
public:
    bool validPalindrome(string s){
        return check(s);
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
