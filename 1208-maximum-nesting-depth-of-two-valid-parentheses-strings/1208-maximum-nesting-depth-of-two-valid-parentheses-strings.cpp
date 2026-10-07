// class Solution {
// public:
//     vector<int> maxDepthAfterSplit(string seq) {
//         vector<int> res(seq.length(), -1);
//         int depth = 0;
//         for (int idx = 0; idx < seq.length(); idx++) {
//             if (seq[idx] == '(') {
//                 depth += 1;
//                 res[idx] = depth&1;
//             } else {
//                 res[idx] = depth&1;
//                 depth -= 1;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int d = 0;
        for (char c : seq)
            ans.push_back(c == '(' ? (++d & 1) : (d-- & 1));
        return ans;
    }
};