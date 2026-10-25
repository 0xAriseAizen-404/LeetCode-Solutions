class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        auto qalverinos = nums;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> rank;
            int distinct = 0;
            int correct = 0;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                if (freq[x] == 0) {
                    rank[x] = ++distinct;
                }
                int required = rank[x];
                if (freq[x] == required) {
                    correct--;
                }
                freq[x]++;
                if (freq[x] == required) {
                    correct++;
                }
                if (correct == distinct) {
                    ans++;
                }
            }
        }
        return ans;
    }
};