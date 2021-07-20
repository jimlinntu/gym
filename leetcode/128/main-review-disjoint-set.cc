class Solution {
public:
    
    int find_leader(int num, unordered_map<int, int> &parent){
        if(parent[num] == num) return num;
        parent[num] = find_leader(parent[num], parent);
        return parent[num];
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> parent;

        for(int num: nums){
            parent[num] = num;
        }

        // Disjoint set: O(n log n)
        for(auto it = parent.begin(); it != parent.end(); it++){
            int num = it->first;
            // Set num-1, num+1's leader's parent to num's leader
            int l = find_leader(num, parent);
            // if this number exists
            if(parent.find(num-1) != parent.end()){
                int left_l = find_leader(num-1, parent);
                parent[left_l] = l; // point to this leader
            }
            if(parent.find(num+1) != parent.end()){
                int right_l = find_leader(num+1, parent);
                parent[right_l] = l;
            }
        }

        // Count which leader contains the most number of children
        int max_len = 0;
        unordered_map<int, int> count;
        for(auto &kv: parent){
            int num = kv.first;
            int l = find_leader(num, parent);
            max_len = max(max_len, ++count[l]);
        }
        return max_len;
    }
};
