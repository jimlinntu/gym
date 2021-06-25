enum Token {
    LPAREN, RPAREN, PLUS, MINUS, INTLITERAL, NOTHING
};

struct Ret{
    int next_idx; // every characters before this idx have been consumed
    int result; // the result of this expression
};

class Solution {
public:
    // Token set are: {+, -, (, ), [0-9]}
    // Define its CFG as:
    // Expr -> P { + P }
    // Expr -> P { - P}
    // P -> ( Expr )
    // P -> + P
    // P -> - P
    // P -> INTLITERAL

    // NOTE: Expr - Expr will fail! because 1 - 1 + 2 will be treated as 1 - (1+2)
    //       That's why P must be an () enclosed or simply a literal with +/- in front of it

    int calculate(string s) {
        return expr(s, 0).result;
    }

    // Recursive Descent Parsing
    Ret expr(string &s, int start){
        // Expr -> P { + P }
        // Expr -> P { - P}
        Token t = determine_token(s, start);
        Ret r = P(s, start);

        for(t = determine_token(s, r.next_idx); t == PLUS or t == MINUS;
                t = determine_token(s, r.next_idx)){
            int next = consume_token(s, r.next_idx, t);
            Ret tmp = P(s, next);
            // move on
            r.next_idx = tmp.next_idx;

            if(t == PLUS) r.result += tmp.result;
            else r.result -= tmp.result;
        }
        return r;
    }
    
    Ret P(string &s, int start){
        // P -> ( Expr )
        // P -> + P
        // P -> - P
        // P -> INTLITERAL
        Token t = determine_token(s, start);
        if(t == LPAREN){
            int next = consume_token(s, start, LPAREN);
            Ret r = expr(s, next);
            next = consume_token(s, r.next_idx, RPAREN);
            return {next, r.result};
        }else if(t == PLUS or t == MINUS){
            int next = consume_token(s, start, t);
            Ret r = P(s, next);
            if(t == MINUS) r.result = -r.result;
            return r;
        }else if(t == INTLITERAL){
            int next = consume_token(s, start, t);
            return {next, stoi(s.substr(start, next-start))};
        }
        assert(false);
        return {-1, -1};
    }
    
    Token determine_token(string &s, int start){
        for(int i = start; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(s[i] == '(') return LPAREN;
            if(s[i] == ')') return RPAREN;
            if(s[i] == '+') return PLUS;
            if(s[i] == '-') return MINUS;
            if(isdigit(s[i])) return INTLITERAL;
            assert(false); // it should not come here
        }
        return NOTHING;
    }
    
    int consume_token(string &s, int start, Token t){
        if(t == LPAREN or t == RPAREN or t == PLUS or t == MINUS){
            for(int i = start; i < s.size(); i++){
                if(s[i] == ' ') continue;
                if(s[i] == '(') return i+1;
                if(s[i] == ')') return i+1;
                if(s[i] == '+') return i+1;
                if(s[i] == '-') return i+1;
            }
            // We must be able to consume this character
            assert(false);
        }else if(t == INTLITERAL){
            for(int i = start; i < s.size(); i++){
                if(s[i] == ' ') continue;
                if(!isdigit(s[i])) return i;
            }
            return s.size();
        }
        assert(false);
        return -1;
    }
};
