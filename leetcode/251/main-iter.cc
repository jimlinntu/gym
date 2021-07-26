class Vector2D {
public:
    vector<vector<int>> v;
    bool is_empty;
    vector<vector<int>>::iterator row_it;
    vector<int>::iterator col_it;

    Vector2D(vector<vector<int>>& vec) {
        v = vec;
        row_it = v.begin();
        if(row_it != v.end()){
            col_it = row_it->begin();
            is_empty = false;
        }else{
            is_empty = true;
        }
    }

    int next() {
        if(is_empty) return INT_MIN;
        if(row_it == v.end()) return INT_MIN;
        // reach column end, go one step
        if(col_it == row_it->end()){
            row_it++;
            if(row_it == v.end()) return INT_MIN;
            col_it = row_it->begin();// reset
            return next();
        }else{
            int r = *col_it;
            col_it++;
            return r;
        }
        // recursion because cases like:
        // [[], [], [], [1], [], [], [2]]
    }

    bool hasNext() {
        if(is_empty) return false;
        if(row_it == v.end()) return false;
        auto tmp_row_it = row_it;
        auto tmp_col_it = col_it;
        // move until we find an element
        while(tmp_row_it != v.end() and tmp_col_it == tmp_row_it->end()){
            tmp_row_it++; // move one row
            
            if(tmp_row_it != v.end()){
                // reset column iterator
                tmp_col_it = tmp_row_it->begin();
            }
        }
        return tmp_row_it != v.end();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
