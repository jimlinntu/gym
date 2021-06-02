class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            int g = 0;
            int j;
            for(j = 0; j < n && g + gas[(i+j) % n] >= cost[(i+j) % n]; j++){
                g += gas[(i+j) % n] - cost[(i+j) % n];
            }
            if(j == n) return i;
        }
        return -1;
    }
};
