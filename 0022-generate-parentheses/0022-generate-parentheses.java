import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        helper(result, "", n, n);
        return result;
    }

    private void helper(List<String> result, String str, int opens, int closes) {
        if (opens == 0 && closes == 0) {
            result.add(str);
            return;
        }
        if (opens > 0) {
            helper(result, str + "(", opens - 1, closes);
        }
        if (closes > opens) {
            helper(result, str + ")", opens, closes - 1);
        }
    }
}
