class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> canHave = new ArrayList<Boolean>();
        int maxx = candies[0];
        for(int x : candies) maxx = Math.max(x, maxx);
        for(int x : candies)
            if((x+extraCandies) >= maxx) canHave.add(true);
            else canHave.add(false);
        return canHave;
    }
}