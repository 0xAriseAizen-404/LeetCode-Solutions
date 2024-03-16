class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> umap{{0, -1}}; // Initialize with {0, -1}
        int maxLen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i] ? 1 : -1; // Update count based on the current element
            if (umap.count(count)) { // If count is in umap
                maxLen = max(maxLen, i - umap[count]); // Update maxLen
            } else {
                umap[count] = i; // Insert count with its index
            }
        }
        return maxLen;
    }
};

// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         unordered_map<pair<int, int>, int> umap;
//         umap[new pair(0, 0)] = -1;
//         int count0 = 0;
//         int count1 = 0;
//         int n = nums.size();
//         int max_length = 0;
//         for(int i=0; i<n; ++i) {
//             if(count == 0) count0++;
//             else count1++;
//             if(count0 == count1) {
//                 max_length = max(max_length, i+1);
//             }
//             int diff = abs(count0, count1);
//             pair p1 = new pair(count0-diff, count1-diff);
//             if(umap.find(p1) != NULL) {
//                 max_length = max(max_length, i-umap[p1]);
//             }
//             pair p = new pair(count0, count1);
//             umap[p] = i;
//         }
//         return max_length;
//     }
// };