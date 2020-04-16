#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL gcd(LL a, LL b){
    assert(a > 0 && b > 0);
    if(a < b) swap(a, b);
    while(true){
        LL remainder = a % b;
        if(remainder == 0){
            break;
        }else{
            // swap
            a = b;
            b = remainder;
        }
    }
    return b;
}

struct Line{
    // y = a x + b
    // where
    // a = (a_sign) * y_diff / x_diff,
    // b = (b_sign) * det / x_diff
    // Note: y_diff / x_diff are normalized by dividing gcd(y_diff, x_diff)
    //  det / x_diff are normalized by dividing gcd(det, x_diff)
    int a_sign;
    LL y_diff;
    LL x_diff;

    int b_sign;
    LL det;
    LL x_diff_2;
    // x = k line (when x_diff == 0)
    int k;
    // Given point1 and point2, compute their corresponding line information
    Line(vector<int> &p1, vector<int> &p2){
        y_diff = (LL)p1[1] - (LL)p2[1];
        x_diff = (LL)p1[0] - (LL)p2[0];
        det = (LL)p1[0] * (LL)p2[1] - (LL)p2[0] * (LL)p1[1];
        x_diff_2 = x_diff;
        
        // x = k line
        if(x_diff == 0LL){
            a_sign = b_sign = 0;
            y_diff = x_diff = det = x_diff_2 = 0LL;
            k = p1[0];
        }else{
            // Set k = 0 as default
            k = 0;
            // a part
            if(y_diff == 0LL){
                a_sign = 0;
                x_diff = 1;
            }else if(y_diff * x_diff > 0LL){
                a_sign = 1;
                y_diff = abs(y_diff), x_diff = abs(x_diff);
                LL gcd_ = gcd(y_diff, x_diff);
                y_diff /= gcd_, x_diff /= gcd_; // normalize
            }else if(y_diff * x_diff < 0LL){
                a_sign = -1;
                y_diff = abs(y_diff), x_diff = abs(x_diff);
                LL gcd_ = gcd(y_diff, x_diff);
                y_diff /= gcd_, x_diff /= gcd_; // normalize
            }else assert(false);

            // b part
            if(det == 0LL){
                b_sign = 0;
                x_diff_2 = 1;
            }else if(det * x_diff_2 > 0LL){
                b_sign = 1;
                det = abs(det), x_diff_2 = abs(x_diff_2);
                LL gcd_ = gcd(det, x_diff_2);
                det /= gcd_, x_diff_2 /= gcd_; // normalize
            }else if(det * x_diff_2 < 0LL){
                b_sign = -1;
                det = abs(det), x_diff_2 = abs(x_diff_2); // normalize
                LL gcd_ = gcd(det, x_diff_2);
                det /= gcd_, x_diff_2 /= gcd_;
            }else assert(false);
        }
    }

    bool operator==(const Line &l) const{
        if(x_diff == 0LL && l.x_diff == 0LL){
            if(k == l.k) return true;
            else return false;
        }else if(x_diff != 0 && l.x_diff != 0){
            // a == l.a and b == l.b
            if(a_sign == l.a_sign && y_diff == l.y_diff && x_diff == l.x_diff
               && b_sign == l.b_sign && det == l.det && x_diff_2 == l.x_diff_2){
                return true;
            }else return false;
        }else{
            return false;
        }
    }
};

ostream &operator<<(ostream &os, Line const &l){
    return (os << "(a_sign, b_sign, k, y_diff, x_diff, det, x_diff_2) =  " <<
            "(" << l.a_sign << "," << l.b_sign << "," <<  l.k << "," << l.y_diff << "," << l.x_diff <<
            "," << l.det << "," << l.x_diff_2 << ")");
}

struct Point{
    int x;
    int y;
    Point(vector<int> &p){
        x = p[0], y = p[1];
    }
    bool operator==(const Point &p) const{
        if(x == p.x && y == p.y){
            return true;
        }
        return false;
    }
};

namespace std{
    template<>
    struct hash<Line>{
        size_t operator()(const Line &l) const{
            auto int_hash = hash<int>();
            auto ll_hash = hash<LL>();
            size_t h = int_hash(l.a_sign) ^ (int_hash(l.b_sign) << 1) ^ (ll_hash(l.y_diff) << 2) ^ (ll_hash(l.x_diff) << 3)
                ^ (ll_hash(l.det) << 4) ^ (ll_hash(l.x_diff_2) << 5) ^ (int_hash(l.k) << 6);
            return h;
        }
    };
    template<>
    struct hash<Point>{
        size_t operator()(const Point &p) const{
            auto int_hash = hash<int>();
            size_t h = int_hash(p.x) ^ (int_hash(p.y) << 1);
            return h;
        }
    };
}


class Solution{
public:
    int maxPoints(vector<vector<int>>& points){
        unordered_map<Line, int> line_counter;
        unordered_map<Line, int> line_belong_index;
        unordered_map<Point, int> point_counter;
        vector<vector<int>> unique_points;

        int num_max_points = 0;

        for(auto &p: points){
            Point point(p);
            point_counter[point]++;
        }
        // Unique points
        for(auto iter = point_counter.begin(); iter != point_counter.end(); iter++){
            vector<int> tmp;
            tmp.push_back(iter->first.x);
            tmp.push_back(iter->first.y);

            unique_points.push_back(tmp);
        }

        if(unique_points.size() == 1){
            Point point(unique_points[0]);
            num_max_points = point_counter[point];
        }
        // Consider each pair of point
        for(int i = 0; i < unique_points.size(); i++){
            for(int j = i+1; j < unique_points.size(); j++){
                Line l(unique_points[i], unique_points[j]);
                Point p_i(unique_points[i]), p_j(unique_points[j]);
                if(line_counter[l] == 0) line_belong_index[l] = i;
                // if this line "belongs" to i
                auto result = line_belong_index.find(l);
                if(result != line_belong_index.end() &&
                    result->second == i){
                    if(line_counter[l] == 0) line_counter[l] += point_counter[p_i] + point_counter[p_j]; // itself and the other
                    else line_counter[l] += point_counter[p_j]; // the other

                    // update the maximum points on a line
                    num_max_points = max(num_max_points, line_counter[l]);
                }
            }
        }
        return num_max_points;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> points(n);
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        points[i].push_back(x);
        points[i].push_back(y);
    }
    Solution s;
    cout << s.maxPoints(points);
    return 0;
}
