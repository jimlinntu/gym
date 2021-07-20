#include <bits/stdc++.h>
using namespace std;


bool is_winner(vector<vector<string>> &codeList,
               vector<string> &shoppingCart){

    int n = shoppingCart.size();
    int p = 0;

    // Let m = max({codeList[i].size()})
    // O(mn)
    for(int i = 0; i < codeList.size(); i++){
        // match the fruits inside this group
        while(p < n){
            bool match = true;
            for(int j = 0; j < codeList[i].size(); j++){
                // If running out of shoppingCart => no match
                // If it is not an any and a mismatch => no match
                if(p+j >= n or (codeList[i][j] != "any" and codeList[i][j] != shoppingCart[p+j])){
                    match = false;
                    break;
                }
            }
            // no match, move p and keep searching
            if(!match) p++;
            // a match
            else break;
        }
        if(p == n) return false;

        // move on to next group
        p = p + codeList[i].size();
    }
    return true;
}

bool match(vector<string> &shoppingCart, int i, vector<string> &l){
    int n = shoppingCart.size();
    if(n - i < l.size()) return false; // no enough items to compare

    for(int j = 0; j < l.size(); j++){
        if(l[j] != "any" and shoppingCart[i+j] != l[j]) return false;
    }
    return true;
}

bool is_winner2(vector<vector<string>> &codeList,
               vector<string> &shoppingCart){

    int n = shoppingCart.size();
    int p = 0; // shoppingCart[p] is the next one we want to compute

    for(int i = 0; i < codeList.size(); i++){
        auto &l = codeList[i];
        while(p < n){
            if(match(shoppingCart, p, l)) break;
            else p++; // go to the next one to compare
        }

        if(p == n) return false;

        p = p + l.size(); // go to the next one
    }
    return true;
}

int main(){
    vector<pair<vector<vector<string>>, vector<string>>>\
            testcases = {{{{"a", "a"}, {"b", "any", "b"}}, {"o", "a", "a", "b", "o", "b"}},
                         {{{"a", "a"}, {"b", "any", "b"}}, {"a", "a", "o", "o", "b", "b", "a", "b", "b"}},
                         {{{"a", "a"}, {"b", "any", "b"}}, {"a", "b", "a", "b", "o", "b"}}};
    for(auto &t: testcases){
        cout << is_winner2(t.first, t.second) << endl;
    }
    return 0;
}
