class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        // psum[i+1] == the sum of nums[0]~nums[i]
        // or psum[i] == the sum of nums[0]~nums[i-1]
        vector<int> psum(n+1, 0);
        for(int i = 0; i < n; i++){
            psum[i+1] = psum[i] + nums[i];
        }
        // Observe that:
        // psum[j]-psum[i]: represents a nonempty subarray [i, j)
        // So the problem becomes:
        // finding the # of i < j where psum[j]-psum[i] == goal
        
        // map[value] == # of value == psum[i] we have seen before
        // (like two sum, but two sum is finding nums[i] + nums[j] == target
        //  but I will say it is pretty similar! Cool!)
        int ans = 0;
        unordered_map<int, int> map;
        for(int j = 0; j <= n; j++){
            // find if # of i s.t.
            // psum[j] - psum[i] == goal
            if(map.count(psum[j]-goal)) ans += map[psum[j]-goal];
            
            map[psum[j]]++;
        }
        return ans;
    }
};
