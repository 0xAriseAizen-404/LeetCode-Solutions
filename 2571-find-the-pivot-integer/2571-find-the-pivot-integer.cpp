// class Solution {
// public:
//     int pivotInteger(int n) {
//         int left = 1;
//         int right = n;
//         int leftSum = left;
//         int rightSum = right;
//         while (left <= right) {
//             if (leftSum == rightSum) {
//                 if (left == right) {
//                     return left;
//                 }
//                 left++;
//                 right--;
//                 leftSum += left;
//                 rightSum += right;
//             } else if (leftSum < rightSum) {
//                 left++;
//                 leftSum += left;
//             } else {
//                 right--;
//                 rightSum += right;
//             }
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = (n * (n + 1)) / 2;
        int leftSum = 0;
        
        for (int i = 1; i <= n; ++i) {
            leftSum += i;
            int rightSum = totalSum - leftSum + i;
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};
