class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> table;
        vector<string> answers;
        int bound = s.length()-9;
        for(int i = 0; i < bound; i++){
            string tmp_s(s.begin()+i, s.begin()+i+10);
            int count = (++table[tmp_s]);
            if(count == 2){
                answers.push_back(tmp_s);
            }
        }
        return answers;
    }
};
