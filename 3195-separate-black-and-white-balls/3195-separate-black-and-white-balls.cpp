class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int black = 0; 
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') 
                swap += (long long) black; 
            else
                black++; 
        }
        return swap;
    }
};



// class Solution {
// public:
//     long long minimumSteps(string nums) {
//         int n = nums.size();

//         auto firstOne = [&] () {
//             for (int i=0; i<n; ++i) {
//                 if (nums[i] == '1') return i;
//             }
//             return -1;
//         };

//         int oneInd = firstOne();
//         if (oneInd == -1) return 0;

//         long long cnt = 0;
//         int zeroInd = oneInd + 1;
//         while (zeroInd < n) {
//             if (nums[zeroInd] == '0') {
//                 cnt++;
//                 nums[zeroInd] = '1';
//                 nums[oneInd] = '0';
//                 oneInd++;
//             }
//             zeroInd++;
//         }
//         return cnt;
//     }
// };