#include <stdio.h>
typedef unsigned long long ULL;

int main(){
    int n, m, a;
    scanf("%d %d %d", &n, &m, &a);
    ULL total;
    total = (ULL)(n / a) * (ULL)(m / a);
    
    if(n % a != 0){
        total += (ULL)(m / a);
    }

    if(m % a != 0){
        total += (ULL)(n / a);
    }

    if(n % a != 0 and m % a != 0){
        total += 1ull;
    }

    printf("%llu", total);
    
    return 0;
}
