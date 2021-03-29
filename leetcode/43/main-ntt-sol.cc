// NOTICE: P + P will not exceed int's maximum
#define P 1004535809LL
#define G 3
#define R 479
#define K 21

using namespace std;
using Poly = vector<int>;
using LL = long long int;

int wn[K+1];

int modpow(int base, int exp, int mod){
    int res = 1;
    base = base % mod;
    while(exp > 0){
        if(exp % 2 == 1) res = ((LL)res * (LL)base) % (LL)mod;
        base = ((LL)base * (LL)base) % (LL)mod;
        exp >>= 1; // exp / 2
    }
    return res;
}

void init_wn(){
    int k = P-1;
    for(int i = 0; i < K+1; i++){
        // data length == 2^i
        // wn = g^k mod p
        wn[i] = modpow(G, k, P);
        k >>= 1; // k /= 2
    }
}

// pad this polynomial to a desired size
void pad(Poly &a, int n){
    for(int i = a.size(); i < n; i++){
        a.push_back(0);
    }
}

// intlog2_ceil(num) == ceil(log2(num))
int intlog2_ceil(int num){
    assert(num >= 1);
    int power = 0;
    int tmp = num;
    // O((log n)^2)
    while((tmp >>= 1) > 0){
        power++;
    }
    if((1 << power) < num){
        power++;
    }
    return power;
}


int reverse_add(int j, int len){
    // if there is only one element, do not need to compute
    if(len == 0) return j;
    // Ex. if len == 3, it means there are 2^3 elements
    int bit = 1 << (len-1);
    for(; (j ^= bit) < bit; bit >>= 1){
    }
    return j;
}


void prepare(Poly &a){
    int n = a.size();
    int bit_len = intlog2_ceil(n);
    for(int i = 0, j = 0; i < n; i++){
        if(i > j) swap(a[i], a[j]);
        j = reverse_add(j, bit_len);
    }
}


void ntt(Poly &a, bool is_inverse){
    prepare(a);
    int n = a.size();
    for(int stride = 2, exp = 1; stride <= n; stride *= 2, exp++){
        // working on each parition [start, start+stride)
        for(int start = 0; start < n; start += stride){
            int half_stride = stride / 2;
            int half_end = start + half_stride;
            int w = 1;
            int w_n = wn[exp]; // stride == 2^exp
            // Because wn^(n/2) == -1,
            // we can only loop over half of the stride
            for(int i = start; i < half_end; i++){
                int even = a[i] % P; // even is on the left side
                int odd = a[i+half_stride] % P; // right is on the right side

                // NOTICE: it is safe to add them
                a[i] = even + (int)(((LL)w * (LL)odd) % (LL)P);
                a[i+half_stride] = even - (int)(((LL)w * (LL)odd) % (LL)P);
                if(a[i] >= P) a[i] -= P;
                if(a[i+half_stride] < 0) a[i+half_stride] += P;

                w = ((LL)w * (LL)w_n) % (LL)P;
            }
        }
    }
    if(is_inverse){
        for(int i = 1; i < (n / 2); i++){
            swap(a[i], a[n-i]);
        }
        // because:
        //     n^(p-1) == 1 mod p
        // ==> n^(-1) == n^(p-2) mod p (multiply n^(-1) on both sides)
        int inverse_n = modpow(n, P-2, P);
        for(int i = 0; i < n; i++){
            a[i] = ((LL)a[i] * (LL)inverse_n) % (LL)P;
        }
    }
}

void fast_poly_mul(Poly &a, Poly &b, Poly &out){
    // pad a, b, out to the size of power of 2
    int m = a.size();
    int n = b.size();
    int out_size = m+n-1;
    int new_out_size = 1 << intlog2_ceil(out_size);
    // make their sizes of power of 2
    pad(a, new_out_size);
    pad(b, new_out_size);
    pad(out, new_out_size);

    ntt(a, false);
    ntt(b, false);

    for(int i = 0; i < new_out_size; i++){
        out[i] = ((LL)a[i] * (LL)b[i]) % (LL)P;
    }

    ntt(out, true);
}

void str2poly(string &s, Poly &poly){
    int n = s.size();
    for(int i = n-1; i >= 0; i--){
        poly.push_back(s[i]-'0');
    }
}

void poly2str(Poly &poly, string &s){
    int n = poly.size();
    int new_n = 1;
    // Compute carry digits
    int carry = 0;
    for(int i = 0; i < n; i++){
        poly[i] += carry;
        carry = poly[i] / 10;
        poly[i] = poly[i] % 10;
        // record the size
        if(poly[i] > 0) new_n = i+1;
    }
    // Ex. m == 5, n == 4 ==> m+n-1 == 8
    //     However, 99999 * 9999 == 9 digits
    for(; carry > 0;){
        poly.push_back(carry % 10);
        carry = carry / 10;
        // record the size
        new_n = poly.size();
    }

    for(int i = new_n-1; i >= 0; i--){
        s.push_back(poly[i]+'0');
    }
}


class Solution {
public:
    string multiply(string num1, string num2) {
        init_wn();
        Poly poly1, poly2, out;
        string ans;

        str2poly(num1, poly1);
        str2poly(num2, poly2);
        fast_poly_mul(poly1, poly2, out);
        poly2str(out, ans);
        return ans;
    }
};
