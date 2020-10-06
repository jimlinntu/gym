// a segment of [bottom, top]
struct Seg{
    int top; // the largest one in this segment
    int bottom; // the smallest one in this segment
    Seg(){};
    Seg(int num): top(num), bottom(num){};
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, Seg> map;
        int max_len = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            auto it = map.find(nums[i]);
            // a duplicate number will not increase the length
            // of any consecutive sequences
            if(it != map.end()) continue;
            it = map.insert({nums[i], Seg(nums[i])}).first;
            // propagate the length information
            auto ahead = map.find(nums[i]-1);
            auto behind = map.find(nums[i]+1);
            auto end = map.end();
            int top, bottom;
            int l = 1;
            // Note: the trick is that we only 
            //       need to update the endpoints!
            if(ahead != end and behind != end){
                top = behind->second.top;
                bottom = ahead->second.bottom;
            }else if(ahead != end){
                top = nums[i];
                bottom = ahead->second.bottom;
            }else if(behind != end){
                top = behind->second.top;
                bottom = nums[i];
            }else{
                top = nums[i];
                bottom = nums[i];
            }
            map[top].bottom = bottom;
            map[bottom].top = top;
            l = top - bottom + 1;
            if(l > max_len) max_len = l;
        }
        return max_len;
    }
};
