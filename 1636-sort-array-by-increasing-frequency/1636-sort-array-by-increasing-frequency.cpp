class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> hMap;
        
        for (int x : nums) {
            hMap[x]++;
        }
        
        vector<int> ans;
        for (auto& pair : hMap) {
            ans.push_back(pair.first);
        }
        
        sort(ans.begin(), ans.end(), [&](int x, int y) {
            if (hMap[x] != hMap[y]) {
                return hMap[x] < hMap[y];
            } else {
                return x > y;
            }
        });

        vector<int> res;
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < hMap[ans[i]]; ++j) {
                res.push_back(ans[i]);
            }
        }
        
        return res;
    }
};
