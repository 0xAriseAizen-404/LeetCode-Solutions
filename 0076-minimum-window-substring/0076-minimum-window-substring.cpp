class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int cnt = 0;
        int startInd = -1;
        int min_len = s.size() + 1;
        vector<int> hash(256, 0);
        for (char ch: t) hash[ch]++;
        for (int right = 0; right < s.length(); ++right) {
            char ch = s[right];
            if (hash[ch] > 0) cnt++; // we still need a requirement from hash_t for this char, so increment the cnt
            hash[ch]--; // If we include a char into our window, whether it is in hash_t or not, we need to decrement it
            // if we don't a char in hash_t, this will end up negative here
            // if we have extra occurances of a char which is even in hash_t, we will end up negative here
            // hash[ch] > 0, we still have a requirement of the occurances of this char from hash_t, increment the count
            // hash[ch] <= 0, we may have completed the requirement of the occruances or maybe we got extra occurances of that char into our window
            while (cnt == t.size()) {
                if ((right - left + 1) < min_len) {
                    min_len = right - left + 1;
                    startInd = left;
                }
                hash[s[left]]++; // if we are removing a char from our winodw, whether it is in hash_t o not, we need to increment it
                if (hash[s[left]] > 0) cnt--; // like I said, we might have extra occurances of a char into our window, might end up with negative, so while we are removing whether we need have shortage of that char in our window, meaning hahs[s[left]] > 0, if its positive then we are shortage of that occurances from hash_t. !!!Important point here
                left++;
            }
        }
        return startInd == -1 ? "" : s.substr(startInd, min_len);
        // Ex. Traverse this example to understand more
        // s = "AAAAB" and t = "AAB" 
    }
};
// TC: O(N)
// SC: O(1)