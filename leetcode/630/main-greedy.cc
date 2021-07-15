class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        int ans = 0, D_c = 0;
        sort(courses.begin(), courses.end(),
              [](const vector<int> &cleft, const vector<int> &cright) -> bool{
            return cleft[1] < cright[1]; // compare last_i and last_j
        });
        // pq.top() records the largest d_i currently
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i < n; i++){
            int d = courses[i][0], l = courses[i][1];
            
            // check if D(c* U {i}) <= l, if yes, we add it
            if(D_c + d <= l){
                pq.push(d);
                ans++; // add a course
                D_c += d; // the new duration
            }else if(!pq.empty() and pq.top() > d){
                // Otherwise, we check if we can make D(c*)
                // by substitute i with j = argmax(d_j)
                // if yes, we will replace that course with course i
                D_c = D_c - pq.top() + d;
                pq.pop();
                pq.push(d);
            }else{
                // do nothing, because we cannot make D(c*) smaller
            }
        }

        return ans;
    }
};
