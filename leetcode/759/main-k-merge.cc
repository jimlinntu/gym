/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

struct MyInterval{
    int i, j;
    int start, end;
    bool operator>(const MyInterval &r) const{
        return start > r.start;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        // push all first schedule to the pq
        // min pq
        priority_queue<MyInterval, vector<MyInterval>, greater<MyInterval>> pq;
        for(int i = 0; i < schedule.size(); i++){
            pq.push({i, 0, schedule[i][0].start, schedule[i][0].end});
        }
        vector<Interval> ans;
        int start = -1, end = -1;
        // K-way merging algorithm
        while(!pq.empty()){
            auto my_int = pq.top();
            pq.pop();

            // in the previous interval, merge it
            if(my_int.start <= end){
                end = max(end, my_int.end);
            }else{
                // there is a free time
                if(end != -1)
                    ans.push_back(Interval(end, my_int.start));
                start = my_int.start;
                end = my_int.end;
            }

            // add its next, like k-way mering algorithm
            if(my_int.j+1 < schedule[my_int.i].size()){
                pq.push({my_int.i, my_int.j+1,
                         schedule[my_int.i][my_int.j+1].start,
                         schedule[my_int.i][my_int.j+1].end});
            }
        }
        return ans;
    }
};
