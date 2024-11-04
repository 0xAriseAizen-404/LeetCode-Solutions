using System;
using System.Collections.Generic;

public class Solution {
    public bool IsAnagram(string s, string t) {
        var freq = new Dictionary<char, int>();
        foreach (char x in s) {
            if (freq.ContainsKey(x)) freq[x]++;
            else freq[x] = 1;
        }
        foreach (char x in t) {
            if (!freq.ContainsKey(x)) return false;
            if (--freq[x] == 0) freq.Remove(x);
        }
        return freq.Count == 0;
    }
}
