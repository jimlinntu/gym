class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // See the attached image within this folder to
        // get more information about how I understand this problem!
        int num_task = tasks.size();
        if(num_task == 0) return 0;
        int counts[26] = {0};
        int max_freq = 0;
        for(int i = 0; i < num_task; i++){
            max_freq = max(max_freq, (++counts[tasks[i]-'A']));
        }
        // Check how many max_freq characters are there
        int num_max_freq = 0;
        for(int i = 0; i < 26; i++){
            if(counts[i] == max_freq){
                num_max_freq++;
            }
        }
        // If the sequence it like: A XX A XX A
        // This indicates the length of X in each parition
        // the purpose of max(0, ...) is that is there are too many most frequent chars
        // like n == 2, A B C D | A B C D | A B C D, we will not have idle slots 
        int num_idle_in_each_partition = max(0, n - (num_max_freq-1));

        // the second part represents that
        // at least we need to put num_idle_in_each_parition * (max_freq - 1)
        return max_freq * num_max_freq + max(num_task - max_freq * num_max_freq,
                                             (num_idle_in_each_partition * (max_freq-1)));
    }
};
