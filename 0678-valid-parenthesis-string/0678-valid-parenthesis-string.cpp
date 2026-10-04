class Solution {
public:
    bool checkValidString(string s) {
        int open_tracks = 0;
        int close_tracks = 0;
        for (const auto &x: s) {
            if (x == '(') open_tracks++, close_tracks++;
            else if (x == ')') open_tracks--, close_tracks--;
            else open_tracks++, close_tracks--;
            if (open_tracks < 0) return false;
            close_tracks = max(close_tracks, 0);
        }
        return close_tracks == 0;
    }
};