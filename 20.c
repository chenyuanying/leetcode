// Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        map<char, char> m = { {')', '('}, {']', '['}, {'}', '{'}};
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                paren.push(s[i]);
            }else{
                if(paren.empty() || paren.top() != m[s[i]]) return false; else paren.pop();
            }
        }
       return paren.empty();
    }

};

