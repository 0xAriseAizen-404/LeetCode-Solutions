#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// Instead of generating every possible subarray, we use prefix sums and maintain counts of even and odd prefix sums.
// Key observation:
// The sum of a subarray between two prefix sums is:
// SubarraySum = P[j] - P[i]
// The result is odd only when the two prefix sums have different parity:
// - Odd − Even = Odd
// - Even − Odd = Odd
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        FAST_IO;
        const int MOD = 1e9 + 7;
        long long _even_cnt = 1, _odd_cnt = 0;
        long long _pre_sum = 0, _count = 0;
        for (int num : arr) {
            _pre_sum += num;
            if (_pre_sum & 1) {
                _count += _even_cnt;
                _odd_cnt++;
            } else {
                _count += _odd_cnt;
                _even_cnt++;
            }
            _count %= MOD;
        }
        return _count;
    }
};
// TC: O(N)
// SC: O(1)

// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         FAST_IO;
//         int MOD = 1e9 + 7;
//         int _count = 0;
//         for (int i = 0; i < arr.size(); ++i) {
//             int _pre_sum = 0;
//             for (int j = i; j < arr.size(); ++j) {
//                 _pre_sum += arr[j];
//                 if ((_pre_sum & 1) == 1) _count += 1;
//             }
//         }
//         return _count % MOD;
//     }
// };
// TC: O(N ** 2)
// SC: O(1)