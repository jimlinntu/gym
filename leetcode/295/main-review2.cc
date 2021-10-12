class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l.empty() or num <= l.top()){
            l.push(num);
        }else r.push(num);
        
        if(l.size() > r.size()+1){
            r.push(l.top());
            l.pop();
        }else if(l.size() < r.size()){
            l.push(r.top());
            r.pop();
        }
    }
    
    double findMedian() {
        int s = l.size() + r.size();
        return (s%2)? (l.top()):((l.top() + r.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
