class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // Observe:
        // s = s0 s1 s2 s3 s4 s5 s6, k =3
        //     ^^ ^^ ^^ ^^ ^^
        //     If any of characters here contain a, we must use it!
        int n = nums.size();
        vector<int> stk;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(stk.empty()){
                stk.push_back(num);
            }else{
                // if the current number is greater
                // and there are still enough numbers behind
                // we can safely pop it!
                // NOTE: (n-i-1) == how many nums remain
                //
                while(!stk.empty() and
                    stk.back() > num and (stk.size() + (n-i-1)) >= k){
                    stk.pop_back();
                }
                if(stk.size() < k)
                    stk.push_back(num);
            }
        }
        return stk;
    }
};
