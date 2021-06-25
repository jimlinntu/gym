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
    // Expr -> ( Expr )
    // Expr -> Expr + Expr
    // Expr -> Expr - Expr
    // Expr -> + Expr
    // Expr -> - Expr
    // Expr -> INTLITERAL

    int calculate(string s) {
        return expr(s, 0).result;
    }

    // Recursive Descent Parsing
    Ret expr(string &s, int start){
        // lookahead
        Token t = determine_token(s, start);
        Ret expr_ret;

        if(t == LPAREN){
            // Expr -> ( Expr )
            int next = consume_token(s, start, LPAREN);
            Ret ret = expr(s, next);
            next = consume_token(s, ret.next_idx, RPAREN);

            expr_ret = {next, ret.result};
        }else if(t == PLUS){
            // Expr -> + Expr
            int next = consume_token(s, start, PLUS);
            Ret ret = expr(s, next);

            expr_ret = {ret.next_idx, +ret.result};
        }else if(t == MINUS){
            // Expr -> - Expr
            int next = consume_token(s, start, MINUS);
            Ret ret = expr(s, next);

            expr_ret = {ret.next_idx, -ret.result};
        }else if(t == INTLITERAL){
            // Expr -> INTLITERAL
            int next = consume_token(s, start, INTLITERAL);
            assert(start < next); // at least one digit
            int literal = stoi(s.substr(start, next-start));
            expr_ret = {next, literal};
        }else assert(false);
        // Expr -> Expr + Expr
        // Expr -> Expr - Expr
        for(t = determine_token(s, expr_ret.next_idx); t == PLUS or t == MINUS;
             t = determine_token(s, expr_ret.next_idx)){
            int next = consume_token(s, expr_ret.next_idx, t);
            Ret ret = expr(s, next);

            expr_ret.next_idx = ret.next_idx; // move on
            if(t == PLUS) expr_ret.result += ret.result;
            else expr_ret.result -= ret.result;
        }
        return expr_ret;
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
