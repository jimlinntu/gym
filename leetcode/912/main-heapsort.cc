class Solution {
public:
    void heapify(vector<int> &a){
        int n = a.size();
        for(int i = 0; i < n; i++){
            // a[i] is placed, we need to float it
            // if it is greater than its parent
            int j = i;
            while(j > 0 and a[j] > a[(j-1)/2]){
                swap(a[j], a[(j-1)/2]);
                j = (j-1)/2;
            }
        }
    }
    vector<int> sortArray(vector<int>& a) {
        vector<int> &b = a;
        heapify(b);
        // pop the root to the last index
        int n = b.size();
        for(int i = n-1; i >= 0; i--){
            // pop it
            // things in [i, n) are sorted
            swap(b[0], b[i]);
            int j = 0;
            while((j*2+1 < i and b[j] < b[j*2+1]) or
                  (j*2+2 < i and b[j] < b[j*2+2])){
                if(j*2+1 < i and j*2+2 < i){
                    // choose the bigger one
                    if(b[j*2+1] >= b[j*2+2]){
                        swap(b[j], b[j*2+1]);
                        j = j*2+1;
                    }else{
                        swap(b[j], b[j*2+2]);
                        j = j*2+2;
                    }
                }else if(j*2+1 < i){
                    swap(b[j], b[j*2+1]);
                    j = j*2+1;
                }else{
                    swap(b[j], b[j*2+2]);
                    j = j*2+2;
                }
            }
        }
        return b;
    }
};
