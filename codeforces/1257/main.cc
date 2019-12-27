#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <assert.h>
using namespace std;
#define MAX(x, y) (((x)>(y))? (x):(y))
#define MAXN 200001
#define MAXN2POW 262144
#define MAXDEPTH 18
#define P 998244353LL
#define G 3
#define K 23

typedef long long int LL;

int n;
int p[MAXN];
int p_prefix_sum[MAXN] = {0};
int p_top = 0;
unordered_map<int, int> p_cnt;

// wn[i] is the primitive root of data length 2^i
LL wn[K];

// initialize left and right polynomial for all depths
LL left_polynomial[MAXDEPTH][MAXN2POW];
LL right_polynomial[MAXDEPTH][MAXN2POW];
LL result_polynomial[MAXN2POW];

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
int intlog2(int n){
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

int make_it_a_power_of_2(int x){
    int bit_length = intlog2(x);
    int result = (1 << bit_length);
    if(result < x) result <<= 1; // make it bigger
    return result;
}
// DnC
void find_maximum_good_set_size(int startIdx, int endIdx, LL polynomial[], int depth=0){
    // Base case
    if(endIdx - startIdx == 1){
        // the count of this p
        int poly_size = p_cnt[p[startIdx]] + 1; // 1 + x + x^2 + ... + x^cnt
        for(int i = 0; i < poly_size; i++){
            polynomial[i] = 1LL; // initialize this polynomial's coefficient
        }
        return;
    }
    // Divide and Conquer
    int mid = (startIdx + endIdx) / 2;
    assert(mid > 0);
    // The left polynomial's size is the sum of prime counts plus 1 (because 1 + x + x^2 + ... x^(sum of count))
    int left_poly_size = p_prefix_sum[mid-1] - ((startIdx >= 1)?(p_prefix_sum[startIdx-1]):(0)) + 1;
    int right_poly_size = p_prefix_sum[endIdx-1] - p_prefix_sum[mid-1] + 1;

    // =================================================
    find_maximum_good_set_size(startIdx, mid, left_polynomial[depth], depth+1);
    find_maximum_good_set_size(mid, endIdx, right_polynomial[depth], depth+1);
    // =================================================
 
    int result_size = left_poly_size + right_poly_size - 1;
    int result_size_of_power_2 = make_it_a_power_of_2(result_size);

    // padding
    for(int i = left_poly_size; i < result_size_of_power_2; i++){
        left_polynomial[depth][i] = 0LL;
    }
    for(int i = right_poly_size; i < result_size_of_power_2; i++){
        right_polynomial[depth][i] = 0LL;
    }
    // Combine: multiply these two polynomial
    fast_poly_mult(left_polynomial[depth], right_polynomial[depth], polynomial, result_size_of_power_2);
    return;
}


int main(){
    // initialize the primitive root for different transformed size
    initialize_w();

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int p_tmp;
        scanf("%d", &p_tmp);
        p_cnt[p_tmp] += 1;
        // if this prime is new
        if(p_cnt[p_tmp] == 1) p[p_top++] = p_tmp;
    }
    assert(p_top <= n);
    // prefix sum
    for(int i = 0; i < p_top; i++){
        if(i > 0) p_prefix_sum[i] = p_prefix_sum[i-1] + p_cnt[p[i]];
        else p_prefix_sum[i] = p_cnt[p[i]];
    }
    // Get coefficient of x^(n/2)
    find_maximum_good_set_size(0, p_top, result_polynomial);
    int mid = n / 2;
    printf("%lld\n", result_polynomial[mid]);
}
