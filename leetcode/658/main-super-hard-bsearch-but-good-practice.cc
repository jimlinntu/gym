class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // Directy use binary search to find the left bound
        int l = 0, r = n-k; // because n-k is the last one we allow
        while(l < r){
            int mid = (l+r)/2;
            if(arr[mid+k] <= x){
                // Case 1:
                // a b c d e f g
                //     ^^^^^  ^
                //     m      x is here!
                // must move right
                l = mid+1;
            }else if(x <= arr[mid]){
                // Case 2:
                // a b   c d e f g
                //    ^  ^^^^^
                //    x  m      
                // the left bound can be at most `mid`
                // but every left bound > m will be worse!!!
                r = mid;
            }else if(abs(arr[mid]-x) < abs(arr[mid+k]-x)){
                r = mid;
            }else if(abs(arr[mid]-x) > abs(arr[mid+k]-x)){
                l = mid+1;
            }else r = mid;
        }
        // Copy
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};
