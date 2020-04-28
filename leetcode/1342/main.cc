class Solution {
public:
    int numberOfSteps (int num) {
        int counter = 0;
        // O(log n)
        while(true){
            if(num & 1) counter++; // increment
            num >>= 1; // right shift by 1
            if(num == 0){
                break;
            }
            counter++;
        }
        return counter;
    }
};
