void search(int num_remain, int last, int hours, int minutes,
    vector<string> &results){
    // Base case
    if(num_remain == 0){
        if(hours <= 11 && minutes <= 59){
            char buf[100];
            snprintf(buf, sizeof(buf), "%d:%02d", hours, minutes);
            results.push_back(string(buf));
        }
        return;
    }

    // Brute force search
    for(int i = last+1; i < 10; i++){
        // 0~5 bit is for minutes
        if(i < 6){
            // Turn on one bit in minutes integer
            search(num_remain-1, i, hours, minutes | (1 << i),
                results);
        }
        // 6~9 bit is for hours
        else{
            // Turn on one bit in hours integer
            search(num_remain-1, i, hours | (1 << (i-6)), minutes,
                results);
        }
    }
    return;
}

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> results;
        search(num, -1, 0, 0, results);
        return results;
    }
};
