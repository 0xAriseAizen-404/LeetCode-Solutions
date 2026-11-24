// My Solution & Thought Process
// class Solution {
// public:
//     int minimizeSum(vector<int>& nums) {
//         // we need to change two elements in the array, so that we will get min(low + high) scores
//         // case 1: if we make first two smallest elements into any number in that range, then low = 0 obviously && high = (1st largest - 3rd smallest)
//         // case 2: if we make first two largest elements into any number in that range, then low = 0 obviously && high = (3rd largest - 1st smallest)
//         // case 3: if we make first smallest and first largest into any number in that range, then low = 0 obviously && high = (2nd largest - 2nd smallest)

//         sort(nums.begin(), nums.end());
//         int sz = nums.size();
//         return min({
//             nums[sz - 1] - nums[2],     // modify 2 smallest
//             nums[sz - 3] - nums[0],     // modify 2 largest
//             nums[sz - 2] - nums[1]      // modify 1 smallest & 1 largest
//         });
//     }
// };

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int mn1 = INT_MAX, mn2 = INT_MAX, mn3 = INT_MAX;
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;

        for (int x : nums) {
            if (x < mn1) {
                mn3 = mn2;
                mn2 = mn1;
                mn1 = x;
            } else if (x < mn2) {
                mn3 = mn2;
                mn2 = x;
            } else if (x < mn3) {
                mn3 = x;
            }

            if (x > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            } else if (x > mx2) {
                mx3 = mx2;
                mx2 = x;
            } else if (x > mx3) {
                mx3 = x;
            }
        }

        return min({mx1 - mn3, mx2 - mn2, mx3 - mn1});
    }
};