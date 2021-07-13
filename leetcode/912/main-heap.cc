struct Heap{
    // a binary tree represented by an array
    vector<int> arr;

    void insert(int num){
        if(arr.size() == 0) arr.push_back(num);
        else{
            arr.push_back(num);
            // move this number up
            int idx = arr.size()-1;
            while(idx > 0 and arr[idx] < arr[(idx-1)/2]){
                swap(arr[idx], arr[(idx-1)/2]);
                idx = (idx-1)/2;
            }
        }
    }

    int pop(){
        assert(arr.size() != 0);
        int ret = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        // move this number down
        int n = arr.size();
        int idx = 0;
        while(true){
            int min_idx = idx;
            int l = 2*idx+1, r = 2*idx+2;
            if(l < n and arr[min_idx] > arr[l]) min_idx = l;
            if(r < n and arr[min_idx] > arr[r]) min_idx = r;
            if(min_idx == idx) break;
            else{
                swap(arr[min_idx], arr[idx]);
                idx = min_idx;
            }
        }
        return ret;
    }
};

class Solution {
public:

    vector<int> sortArray(vector<int>& a) {
        Heap pq;
        for(int x: a) pq.insert(x);
        for(int i = 0; i < a.size(); i++){
            a[i] = pq.pop();
        }
        return a;
    }
};
