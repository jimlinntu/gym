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
    vector<NestedInteger> *nl;
    // this must exist, otherwise we cannot know how to check if an iterator reaches the end
    stack<vector<NestedInteger>*> lstk;
    stack<vector<NestedInteger>::iterator> idxstk;

    NestedIterator(vector<NestedInteger> &nestedList) {
        nl = &nestedList;

        lstk.push(nl);
        idxstk.push(nl->begin());
    }

    void prepare(){
        // Iterative DFS, adapted from Solution Approach 3: Two Stacks
        // (A nice solution!)
        // NOTE: I think Approach 4 does not work for C++ is because
        //       C++ iterator does not have hasNext() method to check whether this iterator
        //       reaches the end.
        //       C++ requires us to have both iterator and the vector container simultaneously
        while(!idxstk.empty() and !lstk.empty()){
            vector<NestedInteger> *l = lstk.top();
            auto it = idxstk.top();

            // if this list is running out of elements
            // then we pop both stacks and then continue this loop
            if(it == l->end()){
                lstk.pop();
                idxstk.pop();
            }else if(it->isInteger() == false){
                // This is a list, we must keep traverse this list
                idxstk.top()++; // advance one (like a pop)

                lstk.push(&(it->getList())); // save the vector pointer
                idxstk.push(it->getList().begin());
            }else{
                // this is an integer, we stop here
                break;
            }
        }
        return;
    }

    int next() {
        prepare();
        assert(hasNext());
        auto it = idxstk.top();
        idxstk.top()++; // advance the index (iterator)
        return it->getInteger();
    }
    
    bool hasNext() {
        prepare();
        // if there is still elements one top of the index stack
        // we still has Next
        return !idxstk.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
