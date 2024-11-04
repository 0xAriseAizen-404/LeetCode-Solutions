using System.Text;

public class Solution {
    public string CompressedString(string word) {
        StringBuilder comp = new StringBuilder();
        int count = 1;
        
        for (int i = 1; i < word.Length; ++i) {
            if (count == 9 || word[i] != word[i - 1]) {
                comp.Append(count).Append(word[i - 1]);
                count = 1;  // Reset count to 1 for the new character sequence
            } else {
                count++;
            }
        }
        
        // Append the final group
        comp.Append(count).Append(word[^1]);
        return comp.ToString();
    }
}
