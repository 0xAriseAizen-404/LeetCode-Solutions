using System;
using System.Collections.Generic;

public class Solution {
    public bool IsAnagram(string s, string t) {
        if (s.Length != t.Length) return false;
        int[] mapp = new int[26];
        for (int i=0; i<s.Length; ++i) {
            mapp[s[i] - 'a']++;
            mapp[t[i] - 'a']--;
        }
        for (int i=0; i<26; ++i) {
            if (mapp[i] != 0) return false;
        }
        return true;
    }
}
