public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        Dictionary<int, bool> contains = new Dictionary<int, bool>();
        foreach (int x in nums) {
            if (contains.ContainsKey(x)) return true;
            contains[x] = true;
        }
        return false;
    }
}