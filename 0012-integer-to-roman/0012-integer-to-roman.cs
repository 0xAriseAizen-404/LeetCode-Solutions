using System;
using System.Collections.Generic;

public class Solution {
    public string IntToRoman(int num) {
        var romans = new Tuple<int, string>[]
        {
            Tuple.Create(1000, "M"),
            Tuple.Create(900, "CM"),
            Tuple.Create(500, "D"),
            Tuple.Create(400, "CD"),
            Tuple.Create(100, "C"),
            Tuple.Create(90, "XC"),
            Tuple.Create(50, "L"),
            Tuple.Create(40, "XL"),
            Tuple.Create(10, "X"),
            Tuple.Create(9, "IX"),
            Tuple.Create(5, "V"),
            Tuple.Create(4, "IV"),
            Tuple.Create(1, "I")
        };

        string res = "";
        foreach (var roman in romans) {
            while (num >= roman.Item1) {
                res += roman.Item2;
                num -= roman.Item1;
            }
        }
        return res;
    }
}
