// Integer to Roman
class Solution {
public:
    string intToRoman(int num) {
        string roman[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"},
        };
        string result;
        result.append(roman[3][num / 1000 % 10]);
        result.append(roman[2][num / 100 % 10]);
        result.append(roman[1][num / 10 % 10]);
        result.append(roman[0][num % 10]);
        return result;
    }
};
