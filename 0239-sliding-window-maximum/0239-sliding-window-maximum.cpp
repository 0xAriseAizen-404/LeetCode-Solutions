class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        priority_queue<pair<int , int>> pq;
        vector<int>ans;
        int i = 0 , j = 0;
        while(j < a.size()) {
            while(j - i < k) pq.push({a[j] , j++});
            while(!pq.empty() and j - pq.top().second > k) pq.pop();
            ans.emplace_back(pq.top().first);
            i++;
        }
        return ans;
    }
}; 