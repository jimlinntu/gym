struct Bar{
    int h;
    int idx;
};
class Solution {
public:
    int trap(vector<int>& height) {
        //     [6 0 1 2 3]
        // --> [(6, 0), (0, 1), (1, 2), (2, 3), (3, 4)]
        // Stack:
        //      6 0 1 2
        //        x 
        //      ^
        //     top
        // 1: ans += 1
        // 2: ans += (3 - 0 - 1) * (min(6, 2) - 1)
        //
        // ans = # of water we can trap
        int n = height.size();
        int ans = 0;
        stack<Bar> stk;
        for(int i = 0; i < n; i++){
            if(stk.empty()){
                stk.push({height[i], 0});
            }else{
                if(stk.top().h > height[i]){
                    stk.push({height[i], i});
                }else if(stk.top().h == height[i]){
                    // do nothing
                    stk.push({height[i], i});
                }else{
                    // 6 3 2 1 5
                    //         ^
                    //       *
                    // 1 2
                    //   ^
                    // 
                    while(!stk.empty() and stk.top().h <= height[i]){
                        Bar b = stk.top();
                        stk.pop();
                        // width * height
                        if(!stk.empty())
                            ans += (i - stk.top().idx - 1) *\
                                    (min(stk.top().h, height[i]) - b.h);
                    }
                    stk.push({height[i], i});
                }
            }
        }
        return ans;
    }
};
