#include <bits/stdc++.h>
#define MAXN 1000000
#define MAXK 5000
#define MAXPRIME 669
using namespace std;
using LL = long long int;
int n;
int k_count[MAXK+1] = {0}; // k_count[k] == the number of k from the inputs
int prime_factorized_count[MAXK+1][MAXPRIME] = {{0}}; // prime_factorized_count[k] == the prime decomposition
int omega[MAXK+1] = {0}; // Big prime omega function: omega[i] = the number of prime divisors of i!

// You can also compute these by https://www.geeksforgeeks.org/sieve-of-eratosthenes/
int primes[MAXPRIME] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079,3083,3089,3109,3119,3121,3137,3163,3167,3169,3181,3187,3191,3203,3209,3217,3221,3229,3251,3253,3257,3259,3271,3299,3301,3307,3313,3319,3323,3329,3331,3343,3347,3359,3361,3371,3373,3389,3391,3407,3413,3433,3449,3457,3461,3463,3467,3469,3491,3499,3511,3517,3527,3529,3533,3539,3541,3547,3557,3559,3571,3581,3583,3593,3607,3613,3617,3623,3631,3637,3643,3659,3671,3673,3677,3691,3697,3701,3709,3719,3727,3733,3739,3761,3767,3769,3779,3793,3797,3803,3821,3823,3833,3847,3851,3853,3863,3877,3881,3889,3907,3911,3917,3919,3923,3929,3931,3943,3947,3967,3989,4001,4003,4007,4013,4019,4021,4027,4049,4051,4057,4073,4079,4091,4093,4099,4111,4127,4129,4133,4139,4153,4157,4159,4177,4201,4211,4217,4219,4229,4231,4241,4243,4253,4259,4261,4271,4273,4283,4289,4297,4327,4337,4339,4349,4357,4363,4373,4391,4397,4409,4421,4423,4441,4447,4451,4457,4463,4481,4483,4493,4507,4513,4517,4519,4523,4547,4549,4561,4567,4583,4591,4597,4603,4621,4637,4639,4643,4649,4651,4657,4663,4673,4679,4691,4703,4721,4723,4729,4733,4751,4759,4783,4787,4789,4793,4799,4801,4813,4817,4831,4861,4871,4877,4889,4903,4909,4919,4931,4933,4937,4943,4951,4957,4967,4969,4973,4987,4993,4999};

void debug(){
    for(int i = 0; i <= 100; i++){
        printf("%d! == ", i);
        for(int j = 0; j < MAXPRIME; j++){
            if(prime_factorized_count[i][j] != 0) printf("%d^%d*", primes[j], prime_factorized_count[i][j]);
        }
        printf(", omega == %d\n", omega[i]);
    }
    printf("omega[5000] == %d\n", omega[MAXK]);
}

// prepare 0!, 1!, ..., 5000!'s prime factorization table
// complexity: O(MAXK) * O(MAXK lnln (MAXK))
void dp_factorization(){
    // no need to compute i == 0, 1
    // compute [2, MAXK]
    for(int i = 2; i <= MAXK; i++){
        // back-up dp fashion: copy up to [0, i) (O(MAXK))
        copy(prime_factorized_count[i-1], prime_factorized_count[i-1]+MAXPRIME, prime_factorized_count[i]);
        omega[i] = omega[i-1];
        // factor i
        int current_number = i;
        // this will be bounded by O(MAXK ln ln (MAXK)): see the bottom of http://mathworld.wolfram.com/PrimeFactor.html
        for(int j = 0, prime; j < MAXPRIME && current_number != 1; j++){
            prime = primes[j];
            while(current_number % prime == 0){
                current_number /= prime;
                prime_factorized_count[i][j] += 1; // increment prime count
                omega[i] += 1; // increment the number of prime divisors
            }
        }
    }
}

// pop the largest prime divisor and decide which branch to descend or stop
bool pop_and_descend(int current_max_prime_index_pointers[MAXK+1], 
    int weighted_prime_count[MAXPRIME], bool is_under_this_branch[MAXK+1], 
    vector<vector<int>> &prime2ks, LL &total, int &parent_prime_branch_idx){
    assert(prime2ks.size() == MAXPRIME+1); // allow -1 index
    // loop over each k to pop the largest prime divisor for each k and record each prime contains what k 's: O(MAXK)
    for(int i = 0; i <= MAXK; i++){
        if(not is_under_this_branch[i]) continue; // do not consider k that is not on this branch anymore
        if(k_count[i] == 0) continue;

        int max_prime_idx = current_max_prime_index_pointers[i];
        prime2ks[max_prime_idx+1].push_back(i); // prime -> a vector of what k is on this prime branch

        if(max_prime_idx == -1) continue; // because this number is running out of prime divisors
        assert(max_prime_idx < MAXPRIME);

        weighted_prime_count[max_prime_idx] += k_count[i]; // record how many k is under this `max_prime_idx` branch

        // O(MAXK ln ln (MAXK)): the estimated quantity of prime divisors
        prime_factorized_count[i][max_prime_idx]--; // decrement because of a pop operation
        // if it is zero, search a smaller prime divisor index for this k
        if(prime_factorized_count[i][max_prime_idx] == 0){
            current_max_prime_index_pointers[i] = -1; // default is empty
            for(int j = max_prime_idx; j >= 0; j--){
                if(prime_factorized_count[i][j] != 0){
                    current_max_prime_index_pointers[i] = j;
                    break;
                }
            }
        }
    }
    // find the best prime branch to descend
    int best_prime_branch_idx = -1;
    int best_count = -1;
    assert(parent_prime_branch_idx < MAXPRIME);
    // search from the parent_prime_branch_idx (because you cannot choose a child prime branch that is strictly greater than parent prime)
    for(int i = parent_prime_branch_idx; i >= 0; i--){
        // the weight must exceed a half of total number of k
        // and we choose the branch that can decrease the most
        if(weighted_prime_count[i] > (n / 2) && weighted_prime_count[i] > best_count){
            best_count = weighted_prime_count[i];
            best_prime_branch_idx = i;
        }
    }

    // if there is a branch to descend
    if(best_prime_branch_idx != -1){
        // branch best_prime_branch_idx will decrease by 1 but other will increase by one
        total = total - (LL)best_count + (LL)(n - best_count);
        // record current prime branch's index
        parent_prime_branch_idx = best_prime_branch_idx;
        // mark other k s as not under this branch anymore: O(MAXK) * O(MAXK)
        for(int i = -1; i < MAXPRIME; i++){
            // i == -1, denote that prime(idx) is running out of prime divisors
            if(i != best_prime_branch_idx){
                for(auto k: prime2ks[i+1]){
                    if(is_under_this_branch[k]){
                        // after moving down a prime, we should mark this k as not under this branch anymore
                        is_under_this_branch[k] = false;
                    }
                }
            }
        }
        return true;
    }
    // if there is no branch to descend
    else{
        // signal ending
        return false;
    }
}
LL initialize_total_distance(){
    LL total = 0;
    for(int i = 0; i <= MAXK; i++){
        total += (LL)k_count[i] * (LL)omega[i]; // the number of multiplicity * the number of prime divisors ( == the depth of the tree)
    }
    return total;
}

LL solve(){
    int weighted_prime_count[MAXPRIME] = {0};
    int current_max_prime_index_pointers[MAXK+1]; // current_max_prime_index_pointers[i] = the index to the maximal prime divisor
    vector<vector<int>> prime2ks(MAXPRIME+1); // f(prime) = a vector of k s
    bool is_under_this_branch[MAXK+1];
    fill(is_under_this_branch, is_under_this_branch + MAXK+1, true); // At first, all nodes are under same branch

    // initialize prime factoriazation table
    dp_factorization();
    // initialize current_max_prime_index_pointers
    for(int i = 0; i <= MAXK; i++){
        current_max_prime_index_pointers[i] = -1; // default value, denoting empty
        // search from the largest number
        for(int j = MAXPRIME-1; j >= 0; j--){
            if(prime_factorized_count[i][j] != 0){
                current_max_prime_index_pointers[i] = j;
                break;
            }
        }
    }
    // initialize the total distance
    LL total = initialize_total_distance();
    int parent_prime_branch_idx = MAXPRIME-1; // initialize to the maximum prime index
    bool ret;

    // descend until there is no improvement
    while(true){
        ret = pop_and_descend(current_max_prime_index_pointers, weighted_prime_count, 
                is_under_this_branch, prime2ks, total, parent_prime_branch_idx);
        if(!ret) break;
        fill(weighted_prime_count, weighted_prime_count + MAXPRIME, 0);
        // clear each vector
        for(auto &vec: prime2ks){
            vec.clear();
        }
    }
    return total;
}

int main(){
    cin >> n;
    int input_k;
    for(int i = 0; i < n; i++){
        cin >> input_k;
        k_count[input_k]++; // increment the count of input_k
    }

    LL answer = solve();
    printf("%lld\n", answer);
    return 0;
}
