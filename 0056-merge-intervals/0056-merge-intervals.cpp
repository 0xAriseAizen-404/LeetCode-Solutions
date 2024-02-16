class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        for(int i=0;i<arr.size();++i){
            if(res.empty() || arr[i][0] > res.back()[1])
                res.push_back(arr[i]);
            else
                res.back()[1] = max(res.back()[1],arr[i][1]);
        }
        return res;
    }
};