class Solution {
public:
vector<vector<int>> generate(int n) 
{
  // Write your code here.
  vector<vector<int>> V;
  for(int x=0;x<n;++x){
    vector<int>v;
    for (int i = 0; i <= x; ++i) {
      if(i==0||i==x) v.push_back(1);
      else v.push_back(V[x-1][i-1]+V[x-1][i]);
    }
    V.push_back(v);
  }
  return V;
}
};