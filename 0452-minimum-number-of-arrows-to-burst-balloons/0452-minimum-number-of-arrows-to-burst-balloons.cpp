class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // int n = points.size();
        // if (n <= 1) 
        //     return n;
        // sort(points.begin(), points.end())
        // int arrows = 1;
        // int end = points[0][1];
        // for (int i = 1; i < n; ++i) {
        //     if (points[i][0] > end) {
        //         arrows++;
        //         end = points[i][1];
        //     } else {
        //         end = min(end, points[i][1]);
        //     }
        // }
        // return arrows;
        int n = points.size();
        if(n <= 1) // Changed to handle case of empty or single element vector
            return n; // Return the size of input if empty or contains only one element

        sort(points.begin(), points.end());
        vector<vector<int>> res;

        for(int i = 0; i < n; ++i) {
            if(res.empty() || points[i][0] > res.back()[1]) {
                res.push_back(points[i]);
            }
            else {
                res.back()[1] = min(res.back()[1], points[i][1]);
            }
        }

        return res.size();
    }
};
