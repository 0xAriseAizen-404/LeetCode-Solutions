class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26);
        int count = 0;
        for (char &x: sentence) {
            int ind = x - 'a';
            if (arr[ind] == 0) {
                arr[ind]++;
                count++;
            }
        }
        if (count == 26)
            return true;
        return false;
    }
};