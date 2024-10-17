class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        // Store the last occurrence of each digit (0-9)
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};


// class Solution {
// public:
//     int maximumSwap(int num) {
//         string str = to_string(num);
//         int maxInd = 0;
//         bool flag = false;
//         for (int i=1; i<str.size(); ++i) {
//             if (!flag && str[i-1] < str[i]) {
//                 flag = true;
//             }
//             if (str[i] > str[maxInd]) maxInd = i;
//         }
//         swap(str[maxInd], str[0]);
//         return stoi(str);
//     }
// };