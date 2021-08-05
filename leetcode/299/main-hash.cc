class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        // 1. Count bulls: Scan over secret and guess
        //    and implicitly maintain a hashmap to later count cows
        int bull = 0, cow = 0;
        int smap[10] = {0};
        int gmap[10] = {0};
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) bull++;
            else{
                smap[secret[i]-'0']++;
                gmap[guess[i]-'0']++;
            }
        }
        // 2. Count cows
        for(int i = 0; i < 10; i++){
            int c = min(smap[i], gmap[i]);
            cow += c;
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
