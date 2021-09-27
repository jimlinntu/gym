class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int n = arr.size();
        int r = it-arr.begin();
        int l = r-1;
        deque<int> dq;
        for(; k > 0; k--){
            if(r >= n){
                dq.push_front(arr[l--]);
            }else if(l < 0){
                dq.push_back(arr[r++]);
            }else if(x-arr[l] <= arr[r]-x){
                dq.push_front(arr[l--]);
            }else{
                dq.push_back(arr[r++]);
            }
        }
        vector<int> ans;
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};
