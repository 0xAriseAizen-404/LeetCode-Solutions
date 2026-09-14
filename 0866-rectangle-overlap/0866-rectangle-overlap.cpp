class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax1 = rec1[0], ay1 = rec1[1], ax2 = rec1[2], ay2 = rec1[3];
        int bx1 = rec2[0], by1 = rec2[1], bx2 = rec2[2], by2 = rec2[3];
        function<bool(int, int, int, int)> overlap = [](int s1, int e1, int s2, int e2) {
                return min(e1, e2) > max(s1, s2);
            };
        return overlap(ax1, ax2, bx1, bx2) && overlap(ay1, ay2, by1, by2);
    }
};