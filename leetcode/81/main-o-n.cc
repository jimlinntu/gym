class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // It WILL affect the runtime complexity:
        // Case:
        // 1. [7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 7]
        //     ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^ <-------- are in the "left" part
        // because front == 7 and back == 7
        // if we stand in a index `mid` within [start, end)
        // we have idea: start = mid+1 or end = mid
        // Therefore, finding the maximum number in the "left" part
        // cannot be finished in O(log n) time
        // And due to unable to find maximum's index in O(log n),
        // it is impossible from us to find `target` in O(log n) by the binary search.
        for(auto num: nums){
            if(target == num) return true;
        }
        return false;
    }
};
