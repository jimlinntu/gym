#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool DEBUG = false;

bool isPalindromic(string &s){
    // O(n)
    // even
    int len = s.length();
    if(len % 2 == 0){
        for(int i = 0; i < len / 2; i++){
            if(s[i] != s[len-i-1]) return false;
        }
    }else{
        for(int i = 0; i < (len - 1) / 2; i++){
            if(s[i] != s[len-i-1]) return false;
        }
    }
    return true;
}

void createCandidates(string &s, vector<LL> &candidates){
    int len = s.length();

    if(len % 2 == 0){
        assert(len >= 2);
        int left_end = len/2-1;
        LL front = stoll(s.substr(0, left_end+1));
        int front_length = left_end+1;
        string front_str = to_string(front);
        string front_added_str = to_string(front+1);
        string front_subtracted_str = to_string(front-1);
        string candidate;

        // if it is not a palindrome
        if(!isPalindromic(s)){
            candidate = front_str;
            candidate.append(front_str.rbegin(), front_str.rend());
            candidates.push_back(stoll(candidate));
        }

        if((int)front_added_str.length() == front_length){
            candidate = front_added_str;
            candidate.append(front_added_str.rbegin(), front_added_str.rend());
            candidates.push_back(stoll(candidate));
        }else{
            // Ex. 99 -> 101, 9999 -> 10001
            candidate = front_added_str;
            candidate.append(front_added_str.rbegin()+1, front_added_str.rend());
            candidates.push_back(stoll(candidate));
        }

        if((int)front_subtracted_str.length() == front_length &&
                front_subtracted_str.compare("0") != 0){
            candidate = front_subtracted_str;
            candidate.append(front_subtracted_str.rbegin(), front_subtracted_str.rend());
            candidates.push_back(stoll(candidate));
        }else{
            // Ex. 10 -> 9, 10|00 -> 999, 100|000 -> 99999
            candidates.push_back(stoll(string(len-1, '9')));
        }
    }else{
        assert(len >= 3);
        int mid = (len - 1) / 2;
        LL front = stoll(s.substr(0, mid+1));
        int front_length = mid+1;
        string front_str = to_string(front);
        string front_added_str = to_string(front+1);
        string front_subtracted_str = to_string(front-1);

        string candidate;
        
        // if itself is not a palindrome, add this [front_str; rev(front_str)[1:]]
        if(!isPalindromic(s)){
            candidate = front_str;
            candidate.append(front_str.rbegin()+1, front_str.rend());
            candidates.push_back(stoll(candidate));
        }

        if((int)front_added_str.length() == front_length){
            candidate = front_added_str;
            candidate.append(front_added_str.rbegin()+1, front_added_str.rend());
            candidates.push_back(stoll(candidate));
        }else{
            // Ex. 999 -> 100|1, 99999 -> 1000|01
            candidate = front_added_str;
            candidate.append(front_added_str.rbegin()+2, front_added_str.rend());
            candidates.push_back(stoll(candidate));
        }

        if((int)front_subtracted_str.length() == front_length){
            candidate = front_subtracted_str;
            candidate.append(front_subtracted_str.rbegin()+1, front_subtracted_str.rend());
            candidates.push_back(stoll(candidate));
        }else{
            // Ex. 100 -> 9|9, 10000 -> 99|99
            candidate = front_subtracted_str;
            candidate.append(front_subtracted_str.rbegin(), front_subtracted_str.rend());
            candidates.push_back(stoll(candidate));
        }
    }
}

LL take_nearest(LL target, vector<LL> &candidates){
    LL min_distance = numeric_limits<LL>::max();
    LL nearest = -1;
    if(DEBUG) cout << "=====" << endl;
    for(auto candidate: candidates){
        LL distance = abs(candidate - target);
        if(DEBUG){
            cout << "distance: " << distance << endl;
            cout << "candidate: " << candidate << endl;
        }

        if(distance < min_distance){
            min_distance = distance;
            nearest = candidate;
        }else if(distance == min_distance){
            // break tie by choosing the smallest one
            if(candidate < nearest) nearest = candidate;
        }
    }
    return nearest;
}

class Solution{
public:
    string nearestPalindromic(string n){
        if(n.length() == 1){
            char c = n[0];
            if(c == '0'){
                return to_string(1); // add it by 1
            }else return to_string(stoi(n)-1); // subtract it by 1
        }
        vector<LL> candidates;
        createCandidates(n, candidates);
        LL nearest = take_nearest(stoll(n), candidates);
        return to_string(nearest);
    }
};

int main(){
    string s;
    Solution sol;
    while(!cin.eof()){
        getline(cin, s);
        if(s.length() == 0) break;
        cout << sol.nearestPalindromic(s) << "\n";
    }
}
