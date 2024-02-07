class Solution {
public:
    // time/space: O(n)/O(1)
    string frequencySort(string s) {
        // count the frequency for each character
        unordered_map<char, int> char2freq;
        for (auto& c : s) char2freq[c]++;
        // sort the frequency in the non-decreasing order
        map<int, vector<char>, greater<int>> freq2chars;
        for (auto& [c, f] : char2freq) freq2chars[f].push_back(c);
        // generate the sorted string
        string result = "";
        for (auto& [f, chars] : freq2chars) {
            for (auto& c : chars) result.append(f, c);
        }
        return result;
    }
};