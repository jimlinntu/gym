class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> folders;
        for(int i = 0, j; i < n; i = j){
            assert(path[i] == '/');
            for(j = i+1; j < n and path[j] != '/'; j++){
            }
            if(i+1 >= n) continue;
            string f = path.substr(i+1, j-(i+1));
            if(f == ".."){
                // go back two folders
                int new_n = max((int)folders.size()-1, 0);
                folders.resize(new_n);
            }else if(f == "."){
                // do nothing
            }else if(f.size() != 0){
                folders.push_back(f);
            }
        }
        //
        string ans;
        if(folders.size() == 0) return "/";
        for(string &f: folders){
            ans += "/" + f;
        }
        return ans;
    }
};
