class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Observe that:
        // [(7, 0), (4, 4), (7, 1), (5, 0), (6, 1), (5, 2)]
        // in sorted form: [4, 5, 5, 6, 7, 7]
        // You can find that the minimum number (4)'s k directy represent where he is!
        // Because all other numbers will be >= them itself (4),
        // how many number are >= than itself will be directly its index!
        // By this idea, we can come up with this algorithm.
        int n = people.size();
        vector<bool> occupied(n, false);
        vector<vector<int>> q(n);
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            int h = people[i][0];
            int k = people[i][1];
            m[h].push_back(k);
        }

        for(auto it = m.begin(); it != m.end(); it++){
            auto &k_s = it->second;
            // this sort is essential!
            // Because we have to mark occupied from behind to avoid
            // like 0, 2 case. If I mark 0 first, then 2 will be marked wrongly!
            sort(k_s.begin(), k_s.end(), greater<int>());
            for(int i = 0; i < it->second.size(); i++){
                int num_in_front = it->second[i];
                int sum = 0;
                for(int j = 0; j < n; j++){
                    if(!occupied[j] and num_in_front == sum){
                        q[j] = {it->first, it->second[i]};
                        break;
                    }
                    // only count non occupied places
                    sum += (int)(occupied[j] == false);
                }
            }
            // mark occupied
            for(int i = 0; i < it->second.size(); i++){
                int num_in_front = it->second[i];
                int sum = 0;
                for(int j = 0; j < n; j++){
                    if(!occupied[j] and num_in_front == sum){
                        occupied[j] = true;
                        break;
                    }
                    // only count non occupied places
                    sum += (int)(occupied[j] == false);
                }
            }
        }
        return q;
    }
};
