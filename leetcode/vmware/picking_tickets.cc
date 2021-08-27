#include <bits/stdc++.h>
using namespace std;

/*
 * Description:
 * 1.picking tickets
n 个票价, a number m is defined as the size of some subsequence s of tickets where each element covers an unbroken range of integers.如果你sort s 里的element，j 和 j+1的difference should be either 0 or 1.
返回subsequence最长长度
Eg：[8,5,4,8,4] return 3  因为[4,4,5]
 */
int solve(vector<int> tickets){
    // Observe: although this problem requires to have a subsequence
    // the result subsequence can be sorted,
    // this makes this problem becomes actually finding a subset!
    sort(tickets.begin(), tickets.end());
    int ans = 1;
    int dp = 1;
    for(int i = 1; i < tickets.size(); i++){
        if(tickets[i] == tickets[i-1] or tickets[i] == tickets[i-1]+1){
            dp = dp+1;
        }else{
            dp = 0;
        }
        ans = max(ans, dp);
    }

    return ans;
}
int main(){
    vector<int> tickets = {8, 5, 4, 8, 4};
    cout << solve(tickets) << endl;
    tickets = {2, 9, 2, 3, 1, 3,6, 7, 5, 6, 4};
    cout << solve(tickets) << endl;
    return 0;
}
