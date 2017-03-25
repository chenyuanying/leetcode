// Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        int order[256] = {0};
        order['I'] = 1;
        order['V'] = 5;
        order['X'] = 10;
        order['L'] = 50;
        order['C'] = 100;
        order['D'] = 500;
        order['M'] = 1000;
        int result = 0;
        for(int i = 0; i < s.size(); ++i){
            if(i + 1 < s.size() && order[s[i + 1]] > order[s[i]]) result -= order[s[i]];
            else result += order[s[i]];
        }
        return result;
    }
};
