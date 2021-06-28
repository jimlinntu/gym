/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

enum Token {
    LBRA, RBRA, INT, COMMA, NONE
};

class Solution {
public:
    // CFG:
    // NI -> [ NI {, NI} ]
    // NI -> []
    // NI -> int

    // return the next index
    int NI(string &s, int start, NestedInteger &ni){
        Token t = lookahead(s, start);
        if(t == INT){
            int next = consume(s, start, INT);
            int num = stoi(s.substr(start, next-start));
            ni.setInteger(num);
            return next;
        }else if(t == LBRA){
            int next = consume(s, start, LBRA);
            // N -> []
            if(lookahead(s, next) == RBRA){
                return consume(s, next, RBRA);
            }
            NestedInteger ni2;
            next = NI(s, next, ni2);
            // add this nested integer
            ni.add(ni2);

            start = next; // move to a new start
        }else assert(false);

        // NI -> [ NI {, NI} ]
        for(t = lookahead(s, start); t == COMMA; t = lookahead(s, start)){
            NestedInteger ni2;
            int next = consume(s, start, COMMA);
            next = NI(s, next, ni2);
            ni.add(ni2);

            start = next;
        }

        return consume(s, start, RBRA);
    }

    Token lookahead(string &s, int start){
        for(int i = start; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(s[i] == '[') return LBRA;
            if(s[i] == ']') return RBRA;
            if(s[i] == ',') return COMMA;
            if(isdigit(s[i]) or s[i] == '-') return INT;
        }
        return NONE;
    }
    
    int consume(string &s, int start, Token t){
        if(t == INT){
            for(int i = start; i < s.size(); i++){
                if(s[i] == ' ') continue;
                if(!isdigit(s[i]) and s[i] != '-') return i;
            }
            return s.size();
        }else{
            for(int i = start; i < s.size(); i++){
                if(s[i] == ' ') continue;
                if(s[i] == '[' or s[i] == ']' or s[i] == ',') return i+1;
            }
            assert(false);
        }
        assert(false);
        return -1;
    }

    NestedInteger deserialize(string s) {
        NestedInteger ni;
        NI(s, 0, ni);
        return ni;
    }
};
