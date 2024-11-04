public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var anagrams = new Dictionary<string, List<string>>();
        foreach (string str in strs) {
            char[] x = str.ToCharArray();
            Array.Sort(x);
            string key = new string(x);
            if (!anagrams.ContainsKey(key)) {
                anagrams[key] = new List<string>();
            }
            anagrams[key].Add(str);
        }
        var res = new List<IList<string>>();
        foreach (var group in anagrams.Values) {
            res.Add(group);
        }
        
        return res;
    }
}
