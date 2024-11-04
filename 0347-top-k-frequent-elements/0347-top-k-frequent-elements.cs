public class Solution
{
	public int[] TopKFrequent(int[] nums, int k)
	{
		var dict = new Dictionary<int, int>();
		for (int i = 0; i < nums.Length; i++)
		{
			var num = nums[i];
			if(dict.ContainsKey(num))
			{
				dict[num]++;
			}
			else dict.Add(num, 1);
		}
		//return dict.OrderByDescending(x => x.Value).Take(k).Select(x => x.Key).ToArray(); O(n log n)
		var buckets = new List<int>[nums.Length + 1];
		foreach (var num in dict.Keys)
		{
			var freq = dict[num];
			if(buckets[freq] == null) buckets[freq] = new List<int>();
			buckets[freq].Add(num);
		}
		
		var result = new List<int>();
		for (int i = buckets.Length - 1; i >= 0 && result.Count < k; i--)
		{
			if(buckets[i] != null) result.AddRange(buckets[i]);
		}
		return result.ToArray();
	}
}