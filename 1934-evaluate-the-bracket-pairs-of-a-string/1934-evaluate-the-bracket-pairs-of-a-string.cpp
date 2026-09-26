// My Solution
// class Solution {
// public:
//     string evaluate(string str, vector<vector<string>>& knowledge) {
//         unordered_map<string, string> k_map;
//         for (auto vec: knowledge) k_map[vec[0]] = vec[1];
//         int b_start = -1;
//         int ind = 0;
//         string res = "";
//         while (ind < str.length()) {
//             if (str[ind] == '(') b_start = ind;
//             if (b_start == -1) res = res + str[ind]; 
//             if (str[ind] == ')') {
//                 string key = str.substr(b_start + 1, ind - b_start - 1);
//                 if (k_map.find(key) != k_map.end()) res += k_map[key];
//                 else res += "?";
//                 b_start = -1;
//             }
//             ind += 1;
//         }
//         return res;
//     }
// };

// ChatGPT Improvised Solution
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> k_map;
        for (const auto& vec : knowledge) k_map[vec[0]] = vec[1];
        string ans;
        for (int ind = 0; ind < s.size(); ) {
            if (s[ind] != '(') {
                ans += s[ind++];
                continue;
            }
            int j = ind + 1;
            while (s[j] != ')') ++j;
            string key = s.substr(ind + 1, j - ind - 1);
            auto it = k_map.find(key);
            ans += (it != k_map.end() ? it->second : "?");
            ind = j + 1;
        }
        return ans;
    }
};