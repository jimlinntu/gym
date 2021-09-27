class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // Directy use binary search to find the left bound
        int l = 0, r = n-k; // because n-k is the last one we allow
        while(l < r){
            int mid = (l+r)/2;
            // You can imagine, if |a[mid+k] - x| is better than
            // |a[mid] - x|
            // This means a[mid] can be removed and move the window right!
            // And if that is the case,
            // we also know that this window should be move right
            // and every left boundary in [l, mid] will be worse than left = `mid`
            // So we exclude [l, mid]
            // That's why we can perform a binary search here
            cout << mid << ":" << arr[mid] << endl;
            if(x < arr[mid]){
                r = mid;
            }else if(arr[mid+k-1] < x){
                l = mid+1;
            }else if(abs(x-arr[mid]) < abs(arr[mid+k]-x)){
                r = mid;
            }else if(abs(x-arr[mid]) > abs(arr[mid+k]-x)){
                l = mid+1;
            }else r = mid;
        }
        // Copy
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};
