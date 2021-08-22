class Solution {
public:
    int ans = INT_MAX;
    int num_hand;
    void collapse(string &board){
        while(true){
            int n = board.size();
            int pos = -1;
            int len;
            for(int i = 0; i < n; i++){
                // Tricky
                for(len = 0; i+len < n and board[i] == board[i+len]; len++){
                }
                if(len >= 3){
                    pos = i;
                    break;
                }
            }
            if(pos == -1) break;
            // Otherwise, collapse it
            board = board.substr(0, pos) + board.substr(pos+len);
        }
    }
    void solve(string &board, unordered_map<char, int> &hand_freq, int used){
        int n = board.size();
        if(n == 0){
            ans = min(ans, used);
            return;
        }
        if(used == num_hand) return;
        // The color we can use
        for(auto it = hand_freq.begin(); it != hand_freq.end(); it++){
            char color = it->first;
            int count = it->second;
            if(count == 0) continue;

            it->second--;
            // n+1 positions we can insert
            for(int i = 0; i <= n; i++){
                // 1. Pruning: we cannot insert a ball into a place where there will
                //    be 3 different colors:
                //    Ex. YB -> YRB --> impossible to resolve it using 4 balls remaining
                if(i >= 1 and i < n and
                   board[i-1] != board[i] and board[i-1] != color and board[i] != color)
                    continue;
                // 2. Pruning: YY --> YYY
                if(i >= 1 and i < n and
                   board[i-1] == board[i] and color == board[i]) continue;
                if(i >= 2 and board[i-2] == board[i-1] and color == board[i-1]) continue;
                // insert here
                string new_board = board;
                
                new_board.insert(new_board.begin()+i, color);
                collapse(new_board);

                solve(new_board, hand_freq, used+1);
            }
            it->second++;
        }
        
    }
    int findMinStep(string board, string hand) {
        unordered_map<char, int> hand_freq;
        num_hand = 0;
        for(char c: hand){
            hand_freq[c]++;
            num_hand++;
        }

        solve(board, hand_freq, 0);
        return (ans == INT_MAX)? (-1):(ans);
    }
};
