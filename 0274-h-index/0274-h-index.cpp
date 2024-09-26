class Solution {
private:
    bool isValid(vector<int> &citations, int V) {
        return (citations.size() - V) <= citations[V];
    }
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int low = 0, high = citations.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(citations, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return citations.size() - low;
    }
};
