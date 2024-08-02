import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        int integerVal = 0;
        int ind = 0;

        while (ind < s.length()) {
            if (ind < s.length() - 1 && map.get(s.charAt(ind)) < map.get(s.charAt(ind + 1))) {
                integerVal += map.get(s.charAt(ind + 1)) - map.get(s.charAt(ind));
                ind += 2; 
            } else {
                integerVal += map.get(s.charAt(ind));
                ind++; 
            }
        }
        return integerVal;
    }
}
