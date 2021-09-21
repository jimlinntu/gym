struct E{
    char c;
    int count;
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<E> stk;
        int n = s.size();
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(!stk.empty() and stk.top().c == c){
                stk.top().count++;
            }else stk.push({c, 1});

            if(!stk.empty() and stk.top().count == k){
                stk.pop();
            }
        }
        string ans;
        while(!stk.empty()){
            E t = stk.top();
            stk.pop();
            for(int i = 0; i < t.count; i++){
                ans.push_back(t.c);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
