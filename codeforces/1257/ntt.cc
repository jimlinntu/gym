#include <stdio.h>
#include <iostream>
#include <random>
#include <bitset>
#include <assert.h>
#define MAXN 100
// P = R * 2^K + 1, G is its primitive root
#define P 1004535809LL
#define G 3
#define R 479
#define K 21

typedef long long int LL;
using namespace std;

// wn[i] is the primitive root of data length 2^i
LL wn[K];

void print_poly(LL poly[], int n){
    for(int i = 0; i < 50; i++){
        printf("=");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("a_%d: %lld, ", i, poly[i]);
    }
    printf("\n");
    for(int i = 0; i < 50; i++){
        printf("=");
    }
    printf("\n");
}

void print_w(LL w[], LL n){
    for(int i = 0; i < n; i++){
        printf("w%d: %lld,", i, w[i]);
    }
    printf("\n");
}

int reverse_add(int i, int bit_length){
    // if the bit we are xoring is 0, then (i ^ bit) > i 
    for(int bit = 1 << (bit_length-1); bit != 0; bit >>= 1){
        if((i^bit) > i){
            i ^= bit;
            break;
        }
        i ^= bit;
    }
    return i;
}
// https://stackoverflow.com/questions/994593/how-to-do-an-integer-log2-in-c
// O(log n)
int intlog2(LL n){
    int power = 0;
    while(n>>=1) power++;
    return power;
}

// O(log exp)
LL modpow(LL base, LL exp, LL modulus){
    base = base % modulus;
    LL result = 1;
    while(exp > 0){
        if(exp % 2 == 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

void ntt(LL a[], int n, bool is_inverse){
    int bit_length = intlog2(n);
    // reorder the input
    for(int i = 0, j = 0; i < n; i++){
        if(j > i) swap(a[i], a[j]);
        j = reverse_add(j, bit_length);
    }
    // Numeric Theoretical Transform
    for(int stride=2, power=1; stride <= n; stride <<= 1, power++){
        int half_stride = stride >> 1;
        for(int start=0; start < n; start += stride){
            LL w = wn[power]; // current transformed size is 2^power
            LL w_i = 1;
            for(int k=0; k < half_stride; k++){
                LL odd_part = (w_i * a[start + k + half_stride]) % P;
                a[start + k + half_stride] = a[start + k] - odd_part;
                a[start + k] += odd_part ;
                if(a[start + k + half_stride] < 0) a[start + k + half_stride] += P;
                if(a[start + k] >= P) a[start + k] -= P;
                w_i = (w * w_i) % P;
            }   
        }
    }
    // Divide each number by n (Note: n^-1  = n^{p-2} mod p under this finite field)
    if(is_inverse){
        for(int i = 1; i < (n>>1); i++){
            swap(a[i], a[n-i]);
        }
        LL inverse_n = modpow(n, P-2, P);
        for(int i = 0; i < n; i++){
            a[i] = (a[i] * inverse_n) % P;
        }
    }
    return;
}


void initialize_w(){
    LL k = (P-1);
    for(int i = 0; i < K; i++){
        wn[i] = modpow(G, k, P); // wn = g^k mod p
        k >>= 1;
    }
    return;
}

void fast_poly_mult(LL a[], LL b[], LL out[], int n){
    /*
     * n must be the power of 2
     */
    assert(a != b); // the pointer of them should not be equal
    // forward ntt
    ntt(a, n, false);
    ntt(b, n, false);
    // frequency domain multiplication
    for(int i = 0; i < n; i++){
        out[i] = (a[i] * b[i]) % P;
    }
    // inverse ntt
    ntt(out, n, true);
}

void naive_poly_mult(LL a[], LL b[], LL out[], int n){
    for(int k = 0; k < n; k++){
        out[k] = 0;
        for(int i = 0; i <= k; i++){
            out[k] += a[i] * b[k-i];
        }
    }
}

int main(){
    unsigned seed = 1;
    random_device rd;
    default_random_engine gen;
    gen.seed(seed);
    uniform_int_distribution<int> dis(-100, 100);
    LL a[8] = {0}, b[8] = {0}, out[8] = {0};

    for(int i = 0; i < 4; i++){
        a[i] = dis(gen);
        b[i] = dis(gen);
    }
    printf("[*] Using naive polynomial multiplication!\n");
    naive_poly_mult(a, b, out, 8);
    print_poly(out, 8);
    for(int i = 0; i < 4; i++){
        if(a[i] < 0) a[i] = P + a[i];
        if(b[i] < 0) b[i] = P + b[i];
    }
    initialize_w();
    printf("[*] Using numeric theoretic tranformation polynomial multiplication!\n");
    fast_poly_mult(a, b, out, 8);
    // Restore
    for(int i = 0; i < 8; i++){
        if(out[i] > (P-1)/2) out[i] = out[i] - P;
    }
    print_poly(out, 8);
    

    return 0;
}
