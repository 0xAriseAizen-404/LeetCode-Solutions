class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, -1);
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (freq[s[right]] >= left) left = freq[s[right]] + 1;
            // checking if I have seen it or not, if I have not seen it then it will be like -1 >= leftInd (wrong).
            // If I seen it, then previousIndOfRight >= leftInd (right), then leftInd = previousIndOfRight + 1;

            freq[s[right]] = right; // saving the index where I seen it
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         set<char> ss;
//         int left = 0;
//         int max_len = 0;
//         for (int right = 0; right < s.length(); ++right) {
//             if (!ss.insert(s[right]).second) {
//                 while (s[left] != s[right]) ss.erase(s[left++]);
//                 ss.erase(s[left++]);
//                 ss.insert(s[right]);
//             }
//             max_len = max(max_len, (int)ss.size());
//         }
//         return max_len;
//     }
// };