class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        deque<int> monoq; // holding increasing indices (prefix[i])
        int n = A.size();
        vector<int> prefix(n+1); // prefix sum
        int answer = n+1;
        for(int i = 0; i < n; i++){
            prefix[i+1] = A[i] + prefix[i];
        }
        // p_0, p_1, ... p_n
        for(int i = 0; i < (n+1); i++){
            // remove elements greater or equal(>=) than current value
            // in order to:
            // 1. maintain a monotonic sequence 
            // 2. because we want to find i such that
            //    p_i >= p_j + K  ---> p_i > p_j, 
            //    we do not need to consider elements greater than current)
            //    Note: we don't need to consider p_i = p_j either.
            while(!monoq.empty() && prefix[monoq.back()] >= prefix[i]){
                monoq.pop_back();
            }
            
            // check the front of deque
            // if(not satisfy p_i >= p_{monoq.front()} + K): 
            //    do not need to check the following element
            //    because p_{monoq.front()} is already the smallest!
            //    (Note: the front can be safely thrown away
            //     because even the largest index i satisfy the equation,
            //     it will not be better!)
            // else: pop the front and keep check the front of the deque!
            while(!monoq.empty() && prefix[monoq.front()] + K <= prefix[i]){
                // the subarray length is i - j
                answer = min(answer, i - monoq.front());
                monoq.pop_front();
            }
            
            monoq.push_back(i);
        }
        return (answer == (n+1))? (-1):answer;
    }
};
