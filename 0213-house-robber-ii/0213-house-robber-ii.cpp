class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        auto robLinear = [&](int start, int end) {
            int robbedHouse0 = 0;
            int robbedHouse1 = 0;
            for (int i = start; i <= end; ++i) {
                int newRob = max(robbedHouse1, robbedHouse0 + nums[i]);
                robbedHouse0 = robbedHouse1;
                robbedHouse1 = newRob;
            }
            return robbedHouse1;
        };

        int case1 = robLinear(0, n - 2);
        int case2 = robLinear(1, n - 1);
        
        return max(case1, case2);
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];
        
//         int robbedHouse0 = 0;
//         int robbedHouse1 = 0;
//         int maxRobbedHouse_firstIter = 0;
//         for (int i = 0; i < n - 1; ++i) {
//             maxRobbedHouse_firstIter = max(robbedHouse0 + nums[i], robbedHouse1);
//             robbedHouse0 = robbedHouse1;
//             robbedHouse1 = maxRobbedHouse_firstIter;
//         }
        
//         robbedHouse0 = 0;
//         robbedHouse1 = 0;
//         int maxRobbedHouse_secondIter = 0;
//         for (int i = 1; i < n; ++i) {
//             maxRobbedHouse_secondIter = max(robbedHouse0 + nums[i], robbedHouse1);
//             robbedHouse0 = robbedHouse1;
//             robbedHouse1 = maxRobbedHouse_secondIter;
//         }
        
//         return max(maxRobbedHouse_firstIter, maxRobbedHouse_secondIter);
//     }
// };
