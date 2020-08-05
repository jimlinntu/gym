using LL = long long int;
bool init = false;
LL ugly_number[1691];

class Solution {
public:
    void initialize_ugly_numbers(){
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        unordered_set<LL> visit;
        visit.insert(1);
        pq.push(1);
        for(int i = 1; i < 1691; i++){
            LL cur = pq.top();
            pq.pop();
            ugly_number[i] = cur; // the t-th ugly number is cur

            auto end = visit.end();
            // Once a node is pushed into the pq, we tag it as visited
            if(visit.find(cur*2) == end){
                visit.insert(cur*2);
                pq.push(cur*2);
            }
            if(visit.find(cur*3) == end){
                visit.insert(cur*3);
                pq.push(cur*3);
            }
            if(visit.find(cur*5) == end){
                visit.insert(cur*5);
                pq.push(cur*5);
            }
        }
        init = true;
    }
    int nthUglyNumber(int n) {
        // Precompute the result so that we don't have to recompute for an n every time
        if(!init) initialize_ugly_numbers();
        return (int)ugly_number[n]; // return the i-th ugly number
    }
};
