// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for (int num : nums) freq[num]++;
//         for (auto &entry : freq) {
//             if (entry.second & 1) return false;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501] = {0};
        for (int num : nums) {
            freq[num] ^= 1; // Toggle between 0 and 1
        }
        for (int i = 1; i <= 500; i++) {
            if (freq[i] == 1) return false; // If any bit is set, we have an odd occurrence
        }
        
        return true;
    }
};
