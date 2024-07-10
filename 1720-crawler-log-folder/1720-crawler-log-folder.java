class Solution {
    public int minOperations(String[] logs) {
        int distance = 0;
        for (String x: logs) {
            if (x.equals("./")) continue;
            else if (x.equals("../")) {
                if (distance > 0) distance--;
            }
            else distance++;
        }
        return distance;
    }
}