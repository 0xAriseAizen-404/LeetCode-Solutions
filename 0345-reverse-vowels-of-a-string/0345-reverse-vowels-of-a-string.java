class Solution {
    public String reverseVowels(String s) {
        int left = 0;
        int right = s.length() - 1;
        char[] ch = s.toCharArray();
        while (left < right) {
            if (isVowel(ch[left])==true  &&  true== isVowel(ch[right])) {
                char temp = ch[left];
                ch[left] = ch[right];
                ch[right] = temp;
                left++;
                right--;
            } else {
                if (!isVowel(ch[left])) {
                    left++;
                }
                if (!isVowel(ch[right])) {
                    right--;
                }
            }
        }
        return new String(ch);
    }

    public boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
}
