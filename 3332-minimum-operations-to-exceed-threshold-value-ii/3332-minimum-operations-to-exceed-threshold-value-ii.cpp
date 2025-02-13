class Solution {
public:
    static int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int ans=0;
        while(pq.top()<k){
            long long x=pq.top(); pq.pop();
            long long y=pq.top(); pq.pop();
            pq.push(2*x+y);
            ans++;
        }
        return ans;  
    }
};


auto static init = []() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;
}();


// #include <algorithm>
// #include <vector>
// #include <limits>

// using namespace std;

// class Solution {
// private:
//     pair<int, int> getSmallests(vector<int>& nums) {
//         int firstOne = numeric_limits<int>::max();
//         int secondOne = numeric_limits<int>::max();
//         for (int x : nums) {
//             if (x < firstOne) {
//                 secondOne = firstOne;
//                 firstOne = x;
//             } else if (x < secondOne) {
//                 secondOne = x;
//             }
//         }
//         return {firstOne, secondOne};
//     }

// public:
//     int minOperations(vector<int>& nums, int k) {
//         int count = 0;
//         while (any_of(nums.begin(), nums.end(), [k](int x) { return x < k; })) {
//             pair<int, int> p = getSmallests(nums);
//             nums.erase(remove(nums.begin(), nums.end(), p.first), nums.end());
//             nums.erase(remove(nums.begin(), nums.end(), p.second), nums.end());
//             nums.push_back(p.first * 2 + p.second);
//             count++;
//         }
//         return count;
//     }
// };
