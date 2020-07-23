class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bank_set(bank.begin(), bank.end());
        string genes("ACGT");
        queue<string> q({start});
        bank_set.erase(start);
        
        int dist = 0;
        while(!q.empty()){
            for(int k = q.size(); k > 0; k--){
                string w = q.front();
                q.pop();
                for(int i = 0; i < 8; i++){
                    char c = w[i];
                    for(int j = 0; j < 4; j++){
                        if(c == genes[j]) continue; // no mutation
                        w[i] = genes[j];
                        if(bank_set.find(w) != bank_set.end()){
                            if(w == end) return dist+1;
                            q.push(w);
                            bank_set.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            dist++;
        }
        return -1;
    }
};
