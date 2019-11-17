#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 200003
#define char2int(x) ((x) - 'a')
int q;
// len(s)
int n;
char s[MAXLEN], t[MAXLEN];
// char2pos[a] -> t's char index
int t_char2pos[26];
int s_counter[26], t_counter[26];



bool find(){
    // init
    memset(s_counter, 0, sizeof(int) * 26);
    memset(t_counter, 0, sizeof(int) * 26);
    memset(t_char2pos, 0, sizeof(int) * 26);
    //
    bool unique = true;
    for(int i = 0; i < n; i++){
        s_counter[char2int(s[i])] += 1;
        t_counter[char2int(t[i])] += 1;
        
        if(t_counter[char2int(t[i])] >= 2) unique = false;
        // save the char -> index mapping
        t_char2pos[char2int(t[i])] = i;
    }
    // check whether they have same counters
    for(int i = 0; i < 26; i++){
        if(s_counter[i] != t_counter[i]){
            // if they have different counters, there must be no way to make two strings equal
            return false;
        }
    }
    // if they have same counters and (n >= 27 or unique == false), you can trivially put the duplicated characters to the end of string.
    // And then perform bubble sort on the left-hand part
    // ex.
    //    s == bcdefga kk
    //         ******* %%  (perform bubble sort)
    //    t == acdebfg kk
    //         ******* %%  (perform bubble sort)
    if(n >= 27 || unique == false){
        return true;
    }

    // Perform greedy search
    // Proof:
    //  Lets assume my greedy search will not work, that is:
    //      There exist a (s, t) pair such that
    //      (s, t) ----> (my greedy search swapping operation) ----> ( s_1 s_2 s_3 ... s_(n-1) s_(n-2), s_1 s_2 s_3 ... s_(n-2) s_(n-1))
    //        |
    //        |
    //        | (there exist anothoer another path)
    //        |
    //        |
    //        v
    //      ( s_1, s_2, s_3, ... s_(n-1) s_(n-2), s_1, s_2, s_3, ... s_(n-1) s_(n-2) )
    //
    //
    //      But because each swap operation is reversible, you can construct a path such that:
    //      ( s_1 s_2 s_3 ... s_(n-1) s_(n-2), s_1 s_2 s_3 ... s_(n-2) s_(n-1)       )
    //                                       |
    //                                       |
    //                                       |
    //                                       |
    //                                       |
    //                                       |
    //                                       |
    //                                       v
    //      ( s_1, s_2, s_3, ... s_(n-1) s_(n-2), s_1, s_2, s_3, ... s_(n-1) s_(n-2) )
    //
    //      which is impossible.
    //
    //      Therefore, if my greedy search finds that this is "NO", then there does not exist other path toward "YES".
    
    bool can = true;
    
    for(int i = 0; i < n; i++){
        // consider base case
        // ex.
        //      s == abcdefgh
        //      t == abcdefhg
        //                 ^^
        if(n - i <= 2){
            if(s[i] == t[i]) can = true;
            else can = false;
            break;
        }

        // ex.
        // s == abcdefgh (fixed)
        //            %% (swapping basis)
        // t == bdefacgh
        //      ^   *    (perform swapping)
        // we will shift *(a) toward ^(b) position by several swapping operations
        
        char s_i = s[i];
        int idx = t_char2pos[char2int(s_i)]; // the position of character s_i in the string t
        int num_swap_operations = (idx - i); // how many operations you should perform

            
        // perform swapping
        for(int j = idx; j > i; j--){
            t_char2pos[char2int(t[j-1])] += 1; // this character will be shift to the right

            // swap to left
            char tmp = t[j];
            t[j] = t[j-1];
            t[j-1] = tmp;
        }

        // change the position of character s_i in t (although we will not need to use this information)
        t_char2pos[char2int(s_i)] = i; // redundant

        if(num_swap_operations % 2 != 0){
            // swap the end of s (i.e %% region)
            char tmp = s[n-1];
            s[n-1] = s[n-2];
            s[n-2] = tmp;
        }
        
    }
    
    return can;
}

int main(){
    char buf[MAXLEN];
    fgets(buf, MAXLEN, stdin);
    q = atoi(buf);
    for(int i = 0; i < q; i++){
        fgets(buf, MAXLEN, stdin);
        n = atoi(buf);
        fgets(s, MAXLEN, stdin);
        fgets(t, MAXLEN, stdin);

        bool ret = find();
        if(ret) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
