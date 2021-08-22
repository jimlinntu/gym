class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(max_pq.empty()){
            max_pq.push(num);
            return;
        }
        if(max_pq.top() <= num){
            min_pq.push(num);
        }else{
            max_pq.push(num);
        }
        // Rebalance:
        int m = max_pq.size();
        int n = min_pq.size();

        if(n > m){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }else if(m >= n+2){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        //    n <= m and m < n+2
        // =>   m-1 <= n <= m
        // =>   n == m-1, m
    }

    double findMedian() {
        assert(max_pq.size() > 0);
        if(max_pq.size() == min_pq.size()){
            return ((double)max_pq.top()+min_pq.top())/2;
        }else if(max_pq.size() == min_pq.size()+1){
            return max_pq.top();
        }
        assert(false);
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
