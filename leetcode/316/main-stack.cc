class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Actually a stack is enough,
        // but I just do not want to reverse things in the end
        // So I choose a deque
        string dq;
        bool in_stack[26] = {false};
        int freq[26] = {0};
        for(char c: s) freq[c-'a']++;
        for(char c: s){
            // If this c is already in stack, we will skip
            // (As if we replace all characters in the recursive solution)
            // (And also because we will always want the leftmost one)
            freq[c-'a']--;
            if(in_stack[c-'a']) continue;
            // if the top element is c
            // and there is still `dq.back()` character behind
            // Then we can safely pop out it
            while(!dq.empty() and (int)dq.back() > (int)c and freq[dq.back()-'a'] > 0){
                in_stack[dq.back()-'a'] = false;
                dq.pop_back();
            }
            dq.push_back(c);
            in_stack[c-'a'] = true;
        }

        return dq;
    }
};
