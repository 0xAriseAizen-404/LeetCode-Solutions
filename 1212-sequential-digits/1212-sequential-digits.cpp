class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int digit = 1; digit <= 9; ++digit) {
            int num = digit;
            int nextDigit = digit + 1;
            while (num <= high && nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (low <= num && num <= high) res.push_back(num);
                ++nextDigit;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// For each starting digit:

// digit = 1 → nextDigit goes 2...9 → 8 iterations
// digit = 2 → 3...9 → 7 iterations
// digit = 3 → 4...9 → 6 iterations
// ...
// digit = 8 → 9 → 1 iteration
// digit = 9 → no iteration → 0 iterations

// So the total is:

// 8+7+6+5+4+3+2+1+0=36
// Time complexity: O(36 log 36) ≈ constant.
// Space complexity: O(36).