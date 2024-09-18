class Solution {
    public String intToRoman(int num) {
        StringBuilder ret = new StringBuilder("");
        String[] thousands = {"","M","MM","MMM"};
        String[] hundreds = {"","C","CC","CCC", "CD","D","DC","DCC","DCCC","CM"};
        String[] tens = {"","X","XX","XXX", "XL","L","LX", "LXX","LXXX", "XC"};
        String[] single = {"","I","II","III","IV","V","VI", "VII", "VIII", "IX"};

        ret.append(thousands[num/1000]);
        ret.append(hundreds[(num % 1000) / 100]);
        ret.append(tens[(num % 100) / 10]);
        ret.append(single[num % 10]);
        return ret.toString();
    }
}