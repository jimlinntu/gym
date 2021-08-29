class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int left, const int right)->bool{
            int l = left, r = right;
            int lbits = 0, rbits = 0;
            while(l > 0){
                lbits++;
                l = l & (l-1);
            }
            while(r > 0){
                rbits++;
                r = r & (r-1);
            }
            if(lbits < rbits) return true;
            if(lbits > rbits) return false;
            return left < right;
        });
        return arr;
    }
};
