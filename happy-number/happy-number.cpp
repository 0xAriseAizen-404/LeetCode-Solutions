class Solution {
    public boolean isHappy(int n) {
        Map<Integer, Integer> myMap = new HashMap<>();
        int num = n;
        while(num > 1) {
            myMap.put(num, myMap.getOrDefault(num, 0) + 1);
            if(myMap.get(num) > 1)
                return false;
            int summ = 0;
            int rem = 0;
            while(num > 0) {
                summ += Math.pow(num%10, 2);
                num /= 10;
            }
            num = summ;
        }
        return num==1;
    }
}