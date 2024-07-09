class Solution {
    public List<List<Integer>> combinationSum2(int[] arr, int target) {
        Arrays.sort(arr);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        combi(0,arr,target,ans,ds);
        return ans;
    }
    public void combi(int id,int arr[],int target,List<List<Integer>> ans,List<Integer> ds)
    {
        if(target==0)
        {
            ans.add(new ArrayList<>(ds));
        }
        for(int i=id;i<arr.length;i++)
        {
            if(i>id && arr[i]==arr[i-1])
            {
                continue;
            }
            if(arr[i] > target)
            {
                break;
            }
            ds.add(arr[i]);
            combi(i+1,arr,target-arr[i],ans,ds);
            ds.remove(ds.size()-1);
        }
        
    }
}