class Solution {
public:
    string arrangeWords(string text) {
        if(text.size() == 0) return "";
        string::size_type idx = 0;
        vector<string> v;
        while(true){
            string::size_type next = text.find(' ', idx);
            if(next == string::npos) break;
            v.push_back(text.substr(idx, next-idx));
            idx = next+1;
        }
        v.push_back(text.substr(idx));
        // Sort
        stable_sort(v.begin(), v.end(), [](const string &left, const string &right) -> bool{
            return left.size() < right.size();
        });

        string out;
        v[0][0] = toupper(v[0][0]);
        out += v[0];
        for(int i = 1; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                v[i][j] = tolower(v[i][j]);
            }
            out += " " + v[i];
        }
        return out;
    }
};
