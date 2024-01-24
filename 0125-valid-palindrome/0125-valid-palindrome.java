class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        StringBuilder b = new StringBuilder(); 
        
        for(int x =0; x <s.length(); x++){
            if(Character.isLetterOrDigit(s.charAt(x))){
                b.append(s.charAt(x));
            }
        }
        return recursively(b,0,b.length());        
    }    
    public boolean recursively(StringBuilder b,int i,int n){      
      if(i>= n/2) return true;          
          if(b.charAt(i) != b.charAt(n-i-1)){
              return false;
          }
          return recursively(b,i+1,n);
    }
}