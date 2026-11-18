class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        int run = 0;
        char run_char;
        for (int ind = 0; ind < s.length(); ++ind) {
            if (run == 0) {
                run_char = s[ind];
                run = 1;
                continue;
            }
            if (run_char == s[ind]) {
                run++;
            } else {
                if (run & 1) {
                    changes++;
                    run_char = s[ind - 1];
                    run++;
                } else {
                    run_char = s[ind];
                    run = 1;
                }
            }
        }
        return changes;
    }
};