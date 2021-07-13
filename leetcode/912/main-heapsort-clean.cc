class Solution {
public:
    // a: the input array
    // idx: the root of the current heap
    // n: the right boundary (open boundary)
    void heapify(vector<int> &a, int idx, int n){
        while(true){
            int max_idx = idx;
            int l = 2*idx+1, r = 2*idx+2;
            // if a left child exists
            if(l < n and a[max_idx] < a[l]) max_idx = l;
            // if a right child exists
            if(r < n and a[max_idx] < a[r]) max_idx = r;

            if(max_idx == idx) break;
            else{
                swap(a[idx], a[max_idx]);
                idx = max_idx;
            }
        }
    }
    vector<int> sortArray(vector<int>& a) {
        int n = a.size();
        // Build the heap in a bottom-up manner
        // NOTE: Let x be the last index has a child
        //       2*x+1 < n
        //    => x < (n-1)/2
        // if n == 3, (n-1)/2 == 1, x == 0
        // if n == 4, (n-1)/2 == 3/2, x == 1
        for(int i = n/2-1; i >= 0; i--){
            // move the root down if its is smaller than 
            // one of its children
            heapify(a, i, n);
        }
        // pop the root to the last index
        for(int i = n-1; i >= 0; i--){
            swap(a[0], a[i]);
            heapify(a, 0, i);
        }        

        return a;
    }
};
