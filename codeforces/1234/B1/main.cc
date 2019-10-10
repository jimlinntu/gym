#include <stdio.h>
#include <unordered_map>
#include <assert.h>
#define MAXNK 200001
#define MIN(x,y) (((x) < (y))? (x):(y))
using namespace std;

int n, k;
// the first message's index we are going to insert (so you will need to subtract 1 to get the current first message's index
int topIdx; 
int m;
int id[MAXNK]; // incoming messages
int ids[MAXNK]; // id on screen
unordered_map<int, bool> inScreen;

void removeTop(){
    assert(m == k);
    int lastIdx = topIdx;
    // this lastIdx's id will not be in the screen
    inScreen[ids[lastIdx]] = false;
}

void shiftAndPush(int id_i){
    // Insert the new index
    ids[topIdx] = id_i;
    // Revise the new top index
    topIdx = (topIdx + 1) % k;
    // Record id_i to be true
    inScreen[id_i] = true;
    // increment m
    m = MIN(k, m+1);
}

void find_(){
    // 
    inScreen.reserve(1000000);
    // Initialize current topIdx and current number of messages in the screen
    topIdx = 0, m = 0;

    // Intitialize ids to null
    for(int i = 0; i < MAXNK; i++){
        ids[i] = -1;
    }
    // Simulate coming messages
    for(int i = 0; i < n; i++){
        // if this is not in screen
        if(!inScreen[id[i]]){
            // if the screen is full
            assert(m <= k);
            if(m == k){
                removeTop();
            }
            // shift and push the new message
            shiftAndPush(id[i]);
        }
    }
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &id[i]);
    }
    find_();
    printf("%d\n", m); 
    for(int i = 0; i < k; i++){
        int index = (topIdx + k - 1) % k;
        // if there is a nil
        if(ids[index] == -1) break;
        if (i != 0) printf(" %d", ids[index]);
        else printf("%d", ids[index]);

        topIdx = index; // move to the next one
    }
    printf("\n");
    return 0;
}
