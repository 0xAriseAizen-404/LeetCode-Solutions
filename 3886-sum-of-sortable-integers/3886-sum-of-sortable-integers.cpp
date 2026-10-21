// Partition Window + Circular Descents Logic
// Strictly Increasing -> Drops = 1 (circular one, end - 1 > start -> true)
// Strictly Decreasing -> Drops = K - 1 (circular one, end - 1 > start -> false)
// All Equals -> Drops = 0
// Only S.I & All Equals are accepatable, Drops <= 1
// if Drops > 1 || S.D -> will be rejected
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int N = nums.size();
        // Returns: number of circular descents, minimum, maximum
        function<tuple<int, int, int>(int, int)> countDescents = [&](int start, int end) {
                int len = end - start;
                int drops = 0;
                // Count descents inside the segment
                for (int i = start + 1; i < end; i++) {
                    if (nums[i - 1] > nums[i]) drops++;
                }
                // Count the circular connection
                if (nums[end - 1] > nums[start]) drops++;
                auto [mnIt, mxIt] = minmax_element(nums.begin() + start, nums.begin() + end);
                return make_tuple(drops, *mnIt, *mxIt);
            };

        int ans_sum_k = 0;
        // Try every divisor of N
        for (int k = 1; k <= N; k++) {
            if (N % k != 0) continue;
            bool valid = true;
            int prev_max = INT_MIN;
            // Process each segment of length K
            for (int ind = 0; ind < N; ind += k) {
                auto [drops, mn, mx] = countDescents(ind, ind + k);
                // Segment must be rotatable into sorted order and must not overlap the previous segments range
                if (drops <= 1 && prev_max <= mn) {
                    prev_max = mx;
                } else {
                    valid = false;
                    break;
                }
            }
            if (valid) ans_sum_k += k;
        }
        return ans_sum_k;
    }
};

// My Attempt, but missed that Strictly descreasing won't be rotated into sorted, but I thought it would and wrote this logic.
// Partition Window + Mountain Peaks Logic
// class Solution {
// public:
//     int sortableIntegers(vector<int>& nums) {
//         // Partition Window + Mountain Peaks  Logic
//         int N = nums.size();
//         function<tuple<int, int, int>(int, int)> countPeaks = [&](int start, int end) {
//                 int len = end - start;
//                 int peaks = 0;
//                 for (int i = start + 1; i < end - 1; i++) {
//                     if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
//                         peaks++;
//                 }
//                 // Checking if the segment is Monotonic
//                 if (peaks == 0) {
//                     bool inc = true, dec = true;
//                     for (int i = start + 1; i < end; i++) {
//                         if (nums[i] <= nums[i - 1]) inc = false;
//                         if (nums[i] >= nums[i - 1]) dec = false;
//                     }
//                     if (inc || dec || len <= 2) peaks = 1;
//                 }
//                 auto [mnIt, mxIt] = minmax_element(nums.begin() + start, nums.begin() + end);
//                 return make_tuple(peaks, *mnIt, *mxIt);
//             };

//         int ans_sum_k = 0;
//         for (int k = 1; k <= N; k++) {
//             if (N % k != 0) continue;
//             bool valid = true;
//             int prev_max = INT_MIN;
//             for (int ind = 0; ind < N; ind += k) {
//                 auto [peaks, mn, mx] = countPeaks(ind, ind + k);
//                 if (peaks <= 1 && prev_max <= mn) {
//                     prev_max = mx;
//                 } else {
//                     valid = false;
//                     break;
//                 }
//             }
//             if (valid) ans_sum_k += k;
//         }
//         return ans_sum_k;
//     }
// };