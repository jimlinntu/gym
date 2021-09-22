struct T{
    int idx;
    string name;
    int time;
    int amt;
    string city;
    T(){}
    T(int t){
        time = t;
    }
    bool operator<(const T &r)const{
        return time < r.time;
    }
};


class Solution {
public:
    pair<int, string> get_next(string &s, int i){
        string::size_type next = s.find(',', i);
        if(next == string::npos) return {(int)s.size(), s.substr(i)};
        return {(int)next, s.substr(i, next-i)};
    }
    T parse(int idx, string &s){
        T t;
        t.idx = idx;
        int i = 0;
        string r;
        
        tie(i, t.name) = get_next(s, i);
        
        tie(i, r) = get_next(s, i+1);
        
        t.time = stoi(r);
        tie(i, r) = get_next(s, i+1);
        t.amt = stoi(r);
        
        tie(i, t.city) = get_next(s, i+1);

        return t;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        // Bucket
        // [0, 60] is the first bucket (index == 0)
        // [61, 121] is the second bucket (index == 1)
        unordered_map<string, vector<T>> map;
        int n = transactions.size();
        for(int i = 0; i < n; i++){
            T t = parse(i, transactions[i]);
            // different name can be dealed separately
            map[t.name].push_back(t);
        }

        for(auto it = map.begin(); it != map.end(); it++){
            auto &v = it->second;
            // sort based on their time, for binary search
            sort(v.begin(), v.end());
        }
        vector<string> ans;
        for(int i = 0; i < n; i++){
            T t = parse(i, transactions[i]);
            if(t.amt > 1000){
                ans.push_back(transactions[i]);
            }else{
                // Search time frame 
                // [t-60, t+60]
                auto &v = map[t.name];
                auto lit = lower_bound(v.begin(), v.end(), T(t.time-60));
                auto uit = upper_bound(v.begin(), v.end(), T(t.time+60));
                
                bool valid = true;
                // brute force
                for(auto it = lit; it != uit; it++){
                    if(it->city != t.city){
                        valid = false;
                        break;
                    }
                }
                if(!valid) ans.push_back(transactions[i]);
            }
        }
        return ans;
    }
};
