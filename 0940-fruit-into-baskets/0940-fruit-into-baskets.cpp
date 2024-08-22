class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int, int> fruitCount;
        int left = 0;
        int right = 0;
        int res = 0;
    
        while (right < arr.size()) {
            fruitCount[arr[right]]++;
    
            // Shrink the window if we have more than 2 types of fruits
            while (fruitCount.size() > 2) {
                fruitCount[arr[left]]--;
                if (fruitCount[arr[left]] == 0) {
                    fruitCount.erase(arr[left]);
                }
                left++;
            }
    
            res = max(res, right - left + 1);
            right++;
        }
    
        return res;
    }
};