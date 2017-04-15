//Longest Common Prefix
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int len = 0;
        while(1){
            char ch;
            if(strs[0].size() > len){ch = strs[0][len];}
            else break;
            for(int i = 1; i < strs.size(); ++i){
                if(strs[i].size() <= len || strs[i][len] != ch) return strs[0].substr(0,len);
            }
            len++;
        }
        return strs[0].substr(0, len);
    }
};
