using LL = long long int;

class Solution {
public:
    int n;
    LL t;
    vector<string> ans;
    string path;
    
    bool check_num_str(string &num_str){
        if(num_str.size() == 0) return false;
        if(num_str.size() == 1) return true;
        if(num_str[0] == '0') return false;
        return true;
    }

    void solve(string &s, int start, LL prev_num, LL current){
        if(start >= n){
            // NOTE: prev_num is a dangling number needed to be added
            if(prev_num + current == t) ans.push_back(path);
            return;
        }
        // Cannot choose +/- at the beginning
        if(start == 0){
            int old_size = path.size();
            for(int i = 0; i < n; i++){
                auto num_str = s.substr(0, i+1);
                if(!check_num_str(num_str)) continue;
                LL num = stoll(num_str);
                path += num_str;
                solve(s, i+1, num, 0);
                path.resize(old_size); // backtrack
            }
            return;
        }
        // Find a split point
        for(int i = start; i < n; i++){
            auto num_str = s.substr(start, i-start+1);
            if(!check_num_str(num_str)) continue;
            LL num = stoi(num_str);
            // Case 1, 2: +/-
            // when +/- appears, we are sure the prev_num can be added to current
            int old_size = path.size();
            
            path += "+" + num_str;
            solve(s, i+1, num, prev_num + current);
            path.resize(old_size);

            path += "-" + num_str;
            solve(s, i+1, -num, prev_num + current);
            path.resize(old_size);

            // Case 3: *
            // when * appears, it will need to multiply to the prev_num
            // and we cannot add value here
            // Given a number 12345678
            // Ex. 1 + 2 * 3 * 4
            //                  ^^^^^^
            //                  we do not know if there is a * here, so 2*3*4=24
            //                  cannot be added into it yet
            path += "*" + num_str;
            solve(s, i+1, prev_num * num, current);
            path.resize(old_size);
        }
    }

    vector<string> addOperators(string num, int target) {
        n = num.size();
        if(n == 0) return {}; // prevent num = "", target = 0
        t = target;
        solve(num, 0, 0, 0);
        return ans;
    }

};
