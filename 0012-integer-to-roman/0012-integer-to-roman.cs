public class Solution {
    public string IntToRoman(int num) {
        var ret = new StringBuilder("");
        string[] thousands = {"","M","MM","MMM"};
        string[] hundreds = {"","C","CC","CCC", "CD","D","DC","DCC","DCCC","CM"};
        string[] tens = {"","X","XX","XXX", "XL","L","LX", "LXX","LXXX", "XC"};
        string[] single = {"","I","II","III","IV","V","VI", "VII", "VIII", "IX"};

        ret.Append(thousands[num/1000]);
        ret.Append(hundreds[(num % 1000) / 100]);
        ret.Append(tens[(num % 100) / 10]);
        ret.Append(single[num % 10]);
        return ret.ToString();
    }
}