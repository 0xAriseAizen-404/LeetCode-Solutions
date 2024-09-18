public class Solution {
    public int RomanToInt(string s) {
        var romans = new Dictionary<char, int> {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int integerValue = 0;
        int ind = 0;
        while (ind < s.Length) {
            if (ind < s.Length - 1 && romans[s[ind]] < romans[s[ind + 1]]) {
                integerValue += romans[s[ind + 1]] - romans[s[ind]];
                ind += 2;
            } else {
                integerValue += romans[s[ind]];
                ind += 1;
            }
        }
        return integerValue;
    }
}
