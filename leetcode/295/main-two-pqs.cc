class MedianFinder {
public:
    /** initialize your data structure here. */
    int n;
    priority_queue<int, vector<int>, less<int>> max_pq; // left
    priority_queue<int, vector<int>, greater<int>> min_pq; // right
    
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        n++;
        //
        if(max_pq.empty() or num <= max_pq.top()){
            max_pq.push(num);
        }else{
            min_pq.push(num);
        }
        // Balancing: 
        // # of left <= # of right + 1
        int max_pq_size = max_pq.size();
        int min_pq_size = min_pq.size();
        // if # of left achieves 2, we need to move the largest value to the right
        if(max_pq_size - min_pq_size == 2){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }else if(min_pq_size - max_pq_size == 1){
            // if # of right is greater than # of left, move the smallest value
            // to the left
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        return;
    }
    
    double findMedian() {
        if(n % 2) return max_pq.top();
        return (double)(max_pq.top() + min_pq.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
