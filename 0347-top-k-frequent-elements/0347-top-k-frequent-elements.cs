public class Solution 
{
    public int[] TopKFrequent(int[] nums, int k) 
    {
        return nums.GroupBy(num => num)
        .OrderByDescending(num => num.Count())
        .Take(k)
        .Select(c => c.Key)
        .ToArray();
    }
}