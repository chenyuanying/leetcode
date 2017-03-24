// ZigZag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
         if(numRows == 1)return s;
        int kind = 2 * numRows - 2;
        string a[kind];
        string result;
        for(int i = 0; i < s.size(); ++i){
            a[i%kind].push_back(s[i]);
        }
        result += a[0];
        for(int i = 1; i <= numRows - 2; ++i){
            for(int j = 0; j < a[i].size(); ++j){
                result.push_back(a[i][j]);
                if(j < a[kind - i].size()){
                    result.push_back(a[kind-i][j]);
                }
            }
        }
        result += a[numRows-1];
        return result;
    }
};
