#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL gcd(LL a, LL b){
    if(a < b) swap(a, b);
    while(true){
        LL remainder = a % b;
        if(remainder == 0){
            break;
        }
        a = b;
        b = remainder;
    }
    return b;
}

struct Slope{
    LL y_diff; // put sign here
    LL x_diff; // x_diff > 0

    Slope(vector<int> &p1, vector<int> &p2){
        y_diff = p1[1] - p2[1]; // y1 - y2
        x_diff = p1[0] - p2[0]; // x1 - x2

        if(x_diff == 0){
            y_diff = 1;
            return;
        }

        if(y_diff == 0){
            x_diff = 1;
            return;
        }

        if(y_diff * x_diff < 0){
            y_diff = -abs(y_diff); // put sign here
            x_diff = abs(x_diff);
        }else if(y_diff * x_diff > 0){
            y_diff = abs(y_diff);
            x_diff = abs(x_diff);
        }else assert(false);

        LL gcd_ = gcd(y_diff, x_diff);
        y_diff /= gcd_, x_diff /= gcd_; // normalization
        return;
    }

    bool operator==(const Slope &slope) const{
        return (y_diff == slope.y_diff) && (x_diff == slope.x_diff);
    }
};

namespace std{
    template <>
    struct hash<Slope>{
        size_t operator()(const Slope &slope) const{
            auto ll_hasher = hash<LL>();
            return ll_hasher(slope.y_diff) ^ (ll_hasher(slope.x_diff) << 1);
        }
    };
}

class Solution{
public:
    int maxPoints(vector<vector<int>> &points){
        int n = points.size();
        int num_max_point = 0;

        unordered_map<Slope, int> map_counter;
        for(int i = 0; i < n; i++){
            int num_dup_point = 0;
            // O(n)
            for(int j = i+1; j < n; j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 && y1 == y2){
                    num_dup_point++;
                }else{
                    Slope slope(points[i], points[j]);
                    ++map_counter[slope];
                }
            }

            int num_itself = 1 + num_dup_point; // number of itself
            int max_count = 0; // if there is no line for this points[i] then max_count == 0
            // O(n)
            for(auto it = map_counter.begin(); it != map_counter.end(); it++){
                max_count = max(max_count, it->second);
            }
            max_count += num_itself; // add the number of itself
            num_max_point = max(max_count, num_max_point);

            // Probably O(n)
            map_counter.clear();
        }
        return num_max_point;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> points(n);
    for(int i = 0, in; i < n; i++){
        cin >> in;
        points[i].push_back(in);
        cin >> in;
        points[i].push_back(in);
    }

    Solution sol;
    cout << sol.maxPoints(points) << "\n";
    return 0;
}

