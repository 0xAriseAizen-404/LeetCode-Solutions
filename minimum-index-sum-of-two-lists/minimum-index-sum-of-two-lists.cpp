class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> umap;
        unordered_map<string, int> myMap;
        for (int i=0; i<list1.size(); ++i)
            umap[list1[i]] = i;
        int minIndSum = INT_MAX;
        for (int i=0; i<list2.size(); ++i) {
            if (umap.count(list2[i]) > 0) {
                minIndSum = min(minIndSum, i + umap[list2[i]]);
                myMap[list2[i]] += umap[list2[i]] + i;
            }
        }
        vector<string> ans;
        for (auto& x: myMap)
            if (x.second == minIndSum)
                ans.emplace_back(x.first);
        return ans;
    }
};