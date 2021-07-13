class Solution {
public:
    int qselect(vector<int> &a, int start, int end){
        int num = a[start];
        int idx = start;
        for(int i = start+1; i < end; i++){
            if(a[i] <= num) swap(a[i], a[++idx]);
        }
        // [start, idx-1] <= num
        // [idx+1, end) > num
        swap(a[start], a[idx]);
        return idx; // the split idx
    }
    void qsort(vector<int> &a, int start, int end){
        if(start >= end) return;
        // choose a random to partition the array into two parts
        int split_idx = qselect(a, start, end);
        // Because a[split_idx] is already at the right position
        // we only need to sort [start, split_idx), [split_idx+1, end)
        // D&C
        qsort(a, start, split_idx);
        qsort(a, split_idx+1, end);
    }
    vector<int> sortArray(vector<int>& a) {
        shuffle(a.begin(), a.end(), default_random_engine(0));
        qsort(a, 0, a.size());
        return a;
    }
};
