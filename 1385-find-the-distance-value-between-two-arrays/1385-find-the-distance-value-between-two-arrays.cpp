class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int ans = 0, j = 0;
        // |x - y|<= d, No landing region
        // x - y <= (+-d)
        // x - d <= y <= x + d (No landing region)
        // y should be outside this region
        for (int x: arr1) {
            while (j < arr2.size() && arr2[j] < x - d) j++;
            if (j == arr2.size() || arr2[j] > x + d) ans += 1;
        }
        return ans;
    }
};