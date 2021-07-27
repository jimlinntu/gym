/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<NestedInteger> nl;
    stack<vector<NestedInteger>::reverse_iterator> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        nl = nestedList;
        
        for(auto it = nl.rbegin(); it != nl.rend(); it++){
            s.push(it);
        }
    }
    

    // prepare the next integer
    // after this function, an integer will stay on the top of the stack
    // if this is empty, that means we are running out of integers
    // Ex. [[], [[], []], [[[[]]]]]
    void prepare(){
        // Iterative DFS
        while(!s.empty() and s.top()->isInteger() == false){
            auto it = s.top();
            s.pop();
            // add all its children
            auto &l = it->getList();
            for(auto i = l.rbegin(); i != l.rend(); i++){
                s.push(i);
            }
        }
    }

    int next() {
        // implicitly move if the top of the stack is not an integer
        assert(hasNext());
        int nxt = s.top()->getInteger();
        s.pop();
        return nxt;
    }
    
    bool hasNext() {
        prepare();        
        return !s.empty(); // the top must be an integer
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
