class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int N = nums.size();
        vector<int> digitSum(N);
        for (int i = 0; i < N; ++i) {
            int v = nums[i], s = 0;
            while (v > 0) { s += v % 10; v /= 10; }
            digitSum[i] = s;
        }
        vector<int> indices(N);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            if (digitSum[i] != digitSum[j]) return digitSum[i] < digitSum[j];
            return nums[i] < nums[j];
        });
        vector<int> targetPos(N);
        for (int pos = 0; pos < N; ++pos) targetPos[indices[pos]] = pos;
        vector<bool> visited(N, false);
        int cycles = 0;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                cycles++;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = targetPos[j];
                }
            }
        }
        return N - cycles;
    }
};

// nums = {38, 14, 25, 12, 31, 22, 11};
// digitSum = {11, 5, 7, 3, 4, 4, 2};
// Sorted array -> {11, 12, 22, 31, 14, 25, 38}
// indices = {6, 3, 5, 4, 1, 2, 0};

// Now, trying to build connections

// for (int pos = 0; pos < N; ++pos)
    // targetPos[indices[pos]] = pos;
// targetPos = {6, 4, 5, 1, 3, 2, 0};

// Finding Cycles between the connected loops
// cycle 1 = {0 -> 6 -> 0}
// cycle 2 = {1 -> 4 -> 3 -> 1}
// cycle 3 = {2 -> 5 -> 2}

// Minimum Swaps = Total Nums - No. of Closed loops or cycles
// Minimum Swaps = 7 - 3 = 4