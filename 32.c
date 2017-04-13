// Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        for(int i = 0; i + 1 < s.size(); ++i){
            int cnt = 0;
            if(i + maxLen > s.size())break;
            for(int j = i; j < s.size(); ++j){
                if(s[j] == '(') cnt++;
                if(s[j] == ')') cnt--;
                if(cnt < 0 || cnt + j + 1 > s.size())break;
                if(cnt == 0){
                    if(maxLen < j - i + 1){
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return maxLen;
    }
};
