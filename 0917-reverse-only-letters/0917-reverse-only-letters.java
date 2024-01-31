class Solution {
    public String reverseOnlyLetters(String s) 
    {
        int left=0;
        int right = s.length()-1;
        int n = s.length();
        char ch[]= s.toCharArray();
        while(left<right)
        {
            if(!isletter(ch[left]) && !islettercap(ch[left]))
            {
                left++;
            }
            if(!isletter(ch[right]) && !islettercap(ch[right]))
            {
                right--;
            }
            if((isletter(ch[left])==true || islettercap(ch[left])==true) && (isletter(ch[right])==true || islettercap(ch[right])==true))
            {
                char temp = ch[left];
                ch[left]=ch[right];
                ch[right]=temp;
                left++;
                right--;
            }
        }
        return new String(ch);
    }
    public boolean isletter(char ch)
    {
        for(char j = 'a' ; j<='z';j++)
        {
            if(ch==j)
            {
                return true;
            }
        }
        return false;
    }
    public boolean islettercap(char ch)
    {
        for(char j = 'A' ; j<='Z';j++)
        {
            if(ch==j)
            {
                return true;
            }
        }
        return false;
    }
}