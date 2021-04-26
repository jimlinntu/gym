using Point = vector<int>;

class Solution {
public:
    int d_square(Point &p){
        return p[0] * p[0] + p[1] * p[1];
    }
    int quick_partition(vector<Point> &points, int start, int end){
        // [start, end)
        if(start >= end) return -1;
        Point pivot = points[start]; // just choose the first point as the pivot
        int d_pivot = d_square(pivot);
        // NOTE: At first, points[start] is a place to put a moved point
        int left = start, right = end;
        while(left < right){
            // Search if there is a number < d_pivot
            // and put it at points[left]
            while(left < right && d_square(points[--right]) >= d_pivot) {};
            points[left] = points[right];
            // Put it at points[right]
            while(left < right && d_square(points[++left]) < d_pivot){};
            points[right] = points[left];
            // Ex. NOTE: when left == right, there will be at most two operations redundant
        }
        assert(left == right);
        points[left] = pivot;
        return left; // the pivot's index
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int start = 0, end = n;
        while(start < end){
            // Each time at best we can elmininate half of the array
            // i.e. run time = n + n/2 + n / 4 ... = O(2 * n)
            int pivot_idx = quick_partition(points, start, end);
            assert(pivot_idx >= 0);
            // [start, pivot_idx), pivot_idx, [pivot_idx+1, end)
            // Ex. k == 3, [1, 2, 3, 4]
            //              0  1  2  3
            //                    ^ this is what we want
            if(pivot_idx == k-1){
                return vector<Point>(points.begin(), points.begin()+k);
            }else if(pivot_idx < k-1){
                start = pivot_idx+1;
            }else{
                end = pivot_idx;
            }
        }
        assert(false);
        return vector<Point>();
    }
};
