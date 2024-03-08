class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> u_map;
        int max_freq = 0;
        for(auto& x: nums) {
            u_map[x]++;
            max_freq = max(max_freq, u_map[x]);
        }
        int count = 0;
        for(auto& p: u_map) {
            if(p.second == max_freq)
                count += max_freq;
        }
        return count;
    }
};