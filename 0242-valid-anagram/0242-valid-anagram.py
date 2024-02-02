class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        char_frequency = {}

        # Build character frequency map for string s
        for char in s:
            char_frequency[char] = char_frequency.get(char, 0) + 1

        # Compare with string t
        for char in t:
            if char not in char_frequency or char_frequency[char] == 0:
                return False
            char_frequency[char] -= 1

        return True