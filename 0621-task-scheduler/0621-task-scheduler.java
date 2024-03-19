class Solution {
    public int leastInterval(char[] tasks, int n) {
        int len = tasks.length;
        HashMap<Character, Integer> map = new HashMap<>();
        int maxFreq = 0;
        int noOfMaxFreq = 0;
        for (char c : tasks) {
            map.put(c, map.getOrDefault(c, 0) + 1);
            maxFreq = Math.max(maxFreq, map.get(c));
        }
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue() == maxFreq) {
                noOfMaxFreq++;
            }
        }
        int res = Math.max((n + 1) * (maxFreq - 1) + noOfMaxFreq, len);
        return res;
    }
}
