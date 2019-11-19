#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <assert.h>
#define MAXN 200003
#define MIN(x,y) ((x) < (y)? (x):(y))

typedef struct Pair_{
    int index;
    int value;
} Pair;

int n;
Pair a[MAXN];
int team[MAXN];

/*
 * First, it is not hard to prove that:
 *   WLOG, we can sort all teams' members and concatenate them to form a sorted sequence.
 *   You can easily find out that if you swap any pair of members from different teams, it will result in a higher diversity!
 *
 * Let: 
 * s = sorted(a) (O(n log n)
 *   = [s_1, s_2, s_3, ..., s_n]
 * 
 * Define:
 *   f(s_1:n) = the minimum value of s_1 to s_n
 *
 * It is not difficult to show that:
 *   f(s_1:n) = min{ f(s_1:n-3) + (s_n - s_n-2), f(s_1:n-4) + (s_n - s_n-3), ...}
 *            = min{ f(s_1:n-3) - s_n-2, f(s_1:n-4) - s_n-3, ... } + s_n
 *
 *   base case: f(s_1:3) = s_3 - s_1
 *
 * Define:
 *   mindiff(s_1:i) = min{ f(s_1:i) - s_i+1, f(s_1:i-1) - s_i, f(s_1:i-2) - s_i-1, ... } (the minimum value over the previous ones)
 *                  = min{ f(s_1:i) - s_i+1, mindiff(s_1:i-1) }
 *
 *   base case: mindiff(s_1:3) = f(s_1:3) - s_4
 *
 *   NOTE:
 *      we will use min_diff_prve_index_pointer[i] to save mindiff[i]'s corresponding minimum index
 *
 * Then:
 *    f(s_1:n) = mindiff(s_1:n-3) + s_n
 * , which can be compute in O(1) time
 *
 * Thefore,
 *    The total algorithm after sorting is O(n) time.
 *
 */

int f[MAXN];
int mindiff[MAXN];
int mindiff_prev_index_pointer[MAXN];

bool compare(Pair &left, Pair &right){
    return (left.value < right.value);
}

int find_min(int *total_team){
    // a is 1-index
    std::sort(a+1, a+n+1, compare);
    assert(n >= 3);
    if(n <= 5){
        for(int i = 1; i <= n; i++){
            team[i] = 1;
        }

        *total_team = 1;

        return a[n].value - a[1].value;
    }
    assert(n >= 6);
    // Base case (n <= 5, there is only one team)
    for(int i = 1; i <= 5; i++){
        // s_1:i forms a team, so the diversity is s_i - s_1
        f[i] = a[i].value - a[1].value;
        if(i >= 3){
            mindiff[i] = MIN(f[i] - a[i+1].value, mindiff[i-1]);
            if(mindiff[i] == mindiff[i-1]){
                // use the previous pointer
                mindiff_prev_index_pointer[i] = mindiff_prev_index_pointer[i-1];
            }else{
                // use the current index as the pointer (i.e. this index is the last member of the last team in s_1:i)
                mindiff_prev_index_pointer[i] = i;
            }
        }else{
            // i <= 2 can not form a team
            mindiff[i] = INT_MAX;
            mindiff_prev_index_pointer[i] = 0; // point to null
        }
    }

    // dynamic programming
    for(int i = 6; i <= n; i++){
        // compute f
        f[i] = mindiff[i-3] + a[i].value;
        // update mindiff (we don't need to update the last mindiff)
        if(i < n){
            mindiff[i] = MIN(f[i] - a[i+1].value, mindiff[i-1]);
            if(mindiff[i] == mindiff[i-1]){
                // set pointer to the previous index
                mindiff_prev_index_pointer[i] = mindiff_prev_index_pointer[i-1];
            }else{
                // use the current index as the backtrack pointer
                mindiff_prev_index_pointer[i] = i;
            }
        }
    }

    // backtrack by pointers and set teams
    int idx = n;
    int prev;
    int team_idx = 1;
    while(idx != 0){
        prev = mindiff_prev_index_pointer[idx-3];
        // set their team
        for(int i = idx; i > prev; i--){
            int original_index = a[i].index;
            team[original_index] = team_idx;
        }
        // move to prev
        idx = prev;
        // update team idx
        team_idx++;
    }

    *total_team = team_idx-1;
    
    return f[n];
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &(a[i].value));
        a[i].index = i;
    }

    int k;
    int diversity = find_min(&k);

    printf("%d %d\n", diversity, k);

    for(int i = 1; i <= n; i++){
        if(i != n){
            printf("%d ", team[i]);
        }else{
            printf("%d\n", team[i]);
        }
    }
    return 0;
}
