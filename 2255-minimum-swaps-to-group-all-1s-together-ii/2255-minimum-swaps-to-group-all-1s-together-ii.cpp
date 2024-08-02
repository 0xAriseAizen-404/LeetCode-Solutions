#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count_1s = 0;

        for (int num : nums) {
            if (num == 1) {
                count_1s++;
            }
        }

        // If there are no 1s or only one 1, no swaps are needed
        if (count_1s == 0 || count_1s == 1) {
            return 0;
        }

        // Extend the array to handle the circular nature
        vector<int> extended_nums = nums;
        extended_nums.insert(extended_nums.end(), nums.begin(), nums.end());

        // Find the minimum number of 0s in any window of size count_1s
        int min_swaps = INT_MAX;
        int zero_count = 0;

        // Initial window
        for (int i = 0; i < count_1s; ++i) {
            if (extended_nums[i] == 0) {
                zero_count++;
            }
        }

        min_swaps = zero_count;

        // Slide the window over the extended array
        for (int i = count_1s; i < extended_nums.size(); ++i) {
            // Remove the leftmost element of the window
            if (extended_nums[i - count_1s] == 0) {
                zero_count--;
            }
            // Add the new element to the window
            if (extended_nums[i] == 0) {
                zero_count++;
            }
            min_swaps = min(min_swaps, zero_count);
        }

        return min_swaps;
    }
};
