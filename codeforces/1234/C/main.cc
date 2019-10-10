#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXN 200003
int q, n;
enum Type {straight, curved};
Type pipe[2][MAXN];
// 1-indexed
typedef struct Coord_{
    int x, y;
} Coord;
bool search(){
    Coord prev = {.x = 1, .y = 0};
    Coord current = {.x = 1, .y = 1};
    Coord dest = {.x = 2, .y = n+1};

    bool feasible = true;
    // searching
    while(true){
        if(pipe[current.x-1][current.y-1] == straight){
            // from left case
            if(prev.y < current.y){
                assert(prev.x == current.x);
                // flow from left to right
                prev = current;
                current.y += 1;
            }
            // from up case
            else if(prev.x < current.x){
                assert(prev.y == current.y);
                // flow from up to down (impossible to reach the answer, early break)
                feasible = false;
                break;
            }
            // from down case
            else if(prev.x > current.x){
                assert(prev.y == current.y);
                // flow from down to up (impossible to reach the answer, early break)
                feasible = false;
                break;
            }
        }else if(pipe[current.x-1][current.y-1] == curved){
            // from left case
            if(prev.y < current.y){
                assert(prev.x == current.x);
                // flow to down
                if(current.x == 1){
                    prev = current;
                    current.x++;
                }
                // flow to up
                else if(current.x == 2){
                    prev = current;
                    current.x--;
                }else assert(false);
            }
            // from up case
            else if(prev.x < current.x){
                assert(prev.y == current.y);
                // flow to right
                prev = current;
                current.y++;
                
            }
            // from down case
            else if(prev.x > current.x){
                assert(prev.y == current.y);
                prev = current;
                current.y++;
            }
        }else assert(false);

        // check if we reach the destination
        if(current.x == dest.x and current.y == dest.y){
            feasible = true;
            break;
        }
        // check if this point is not out of range
        if(not (1 <= current.x and current.x <= 2 and 1 <= current.y and current.y <= n)){
            feasible = false;
            break;
        }
    }
    return feasible;
}


int main(){
    char buf[MAXN+10];
    fgets(buf, MAXN, stdin);
    q = atoi(buf);
    for(int i = 0; i < q; i++){
        fgets(buf, MAXN, stdin);
        n = atoi(buf);
        for(int j = 0; j < 2; j++){
            fgets(buf, MAXN, stdin);
            for(int k = 0; k < n; k++){
                char c = buf[k];
                int integer = c - '0';
                assert(1 <= integer and integer <= 6);
                if(integer == 1 or integer == 2) pipe[j][k] = straight;
                else pipe[j][k] = curved;
            }
        }

        if(search()){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
