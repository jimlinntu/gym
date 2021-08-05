class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bull = 0, cow = 0;
        int map[256] = {0};
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) bull++;
            else{
                // secret = ....x
                // guess  = ....y
                // Observe that cows' only have two cases:
                // Case 1: a character appear in `secret` earlier than `guess`
                // Case 2: a character appear in `guess` earlier than `guess`
                // So we let `secret` increment in `map` and `guess` decrement it
                // When we encounter Case 1: we know map[y] must < 0
                // When we encounter Case 2: we know map[x] must > 0
                // And because this algorithm only trigger each pair by the character later
                // it will not generate duplicates
                char x = secret[i];
                char y = guess[i];
                if(map[x] < 0) cow++; // this number has been guessed earlier
                if(map[y] > 0) cow++; // this number has appeared in secret earlier
                // add a number
                map[x]++;
                // dig a hole: indicates that we need this number
                map[y]--;
            }
        }
        
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
