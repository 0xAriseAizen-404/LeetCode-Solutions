class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(char &c:num) {
            while(ans.size() && ans.back()>c && k) {
                ans.pop_back();
                k--;
            }
            if(ans.size() || c!='0') ans.push_back(c);
        }
        while(ans.size() && k--) {
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
    }
};

// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         string res = "";
//         stack<int> st;
//         for (int i = 0; i < num.size(); ++i) {
//             while (!st.empty() && k > 0 && num[i] < num[st.top()]) {
//                 k--;
//                 st.pop();
//             }
//             st.push(i);
//         }
//         while (k > 0 && !st.empty()) {
//             st.pop();
//             k--;
//         }
//         if (st.empty()) return "0";
//         while (!st.empty()) {
//             res += num[st.top()];
//             st.pop();
//         }
//         reverse(res.begin(), res.end());
//         while (!res.empty() && res[0] == '0') res.erase(res.begin());
//         if (res.empty()) return "0";
//         return res;
//     }
// };
