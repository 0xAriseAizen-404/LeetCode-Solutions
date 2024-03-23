class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        HashMap<Character, Integer> hMap = new HashMap<>();
        for (int i=0; i<jewels.length(); ++i)
            hMap.put(jewels.charAt(i), hMap.getOrDefault(jewels.charAt(i), 0) + 1);
        int count = 0;
        for (int i=0; i<stones.length(); ++i)
            if (hMap.get(stones.charAt(i)) != null)
                count++;
        return count;
    }
}