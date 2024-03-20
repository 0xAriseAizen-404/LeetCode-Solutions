class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n==0 || n==1)
            return n;
        string ans = "";
        int ind = 0;
        int count = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            if(chars[left] != chars[right]) {
                chars[ind++] = chars[left];
                if(count != 1) {
                    string x = to_string(count);
                    for(char c: x) chars[ind++] = c;
                }
                left = right;
                count = 0;
            }
            count++;
            right++;
        }
        if(count != 0) {
            chars[ind++] = chars[left];
                if(count != 1) {
                    string x = to_string(count);
                    for(char c: x) chars[ind++] = c;
                }
                left = right;
                count = 0;
        }
        return ind;
    }
};