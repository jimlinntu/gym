class Solution {
public:
    int parse_time(const string &time){
        int t;
        string::size_type idx = time.find(':', 0);
        t = stoi(time.substr(0, idx)) * 60;
        t += stoi(time.substr(idx+1));
        return t;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, queue<int>> map;
        vector<string> ans;
        int n = keyName.size();
        vector<pair<string, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({keyName[i], parse_time(keyTime[i])});
        }
        sort(v.begin(), v.end(),
             [](const pair<string, int> &l,
                const pair<string, int> &r) -> bool{
            return l.second < r.second;
        });
        for(int i = 0; i < n; i++){
            int t = v[i].second;
            queue<int> &q = map[v[i].first];
            if(q.size() < 3){
                while(!q.empty() and t - q.front() > 60){
                    q.pop();
                }
                q.push(t);
                if(q.size() >= 3)
                    ans.push_back(v[i].first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
