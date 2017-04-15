// Implement strstr()
class Solution {
public:
    int strStr(string haystack, string needle) {
        //Using Sunday algorithm
        
        int m[256];
        for(int i = 0; i < 256; ++i){
            m[i] = needle.size();
        }
        for(int i = 0; i < needle.size(); ++i){
            m[needle[i]] = needle.size() - i;
        }
        
        int len = (int)haystack.size() - (int)needle.size();
        for(int i = 0; i <= len; ){
            int j;
            for(j = 0; j < needle.size(); ++j){
                if(needle[j] != haystack[i + j]) break;
            }
            if(j == needle.size()) return i;
            if(i + 1 <= len){
                i += m[haystack[i + needle.size()]];
            }else{
                break;
            }
        }
        
        return -1;
    }
    
};
