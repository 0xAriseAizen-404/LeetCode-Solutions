public class Solution {
    private static void myHelper(IList<string> res, string str, int opens, int closes) {
        if (opens == 0 && closes == 0) {
            res.Add(str);
            return;
        }
        if (opens > 0)
            myHelper(res, str + "(", opens - 1, closes);
        if (opens < closes)
            myHelper(res, str + ")", opens, closes - 1);
    }
    
    public IList<string> GenerateParenthesis(int n) {
        IList<string> res = new List<string>();
        myHelper(res, "", n, n);
        return res;
    }
}
