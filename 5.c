// Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int start, left, right = 0;
        if(len <= 1) return s;
        int max_len = 1;
        int max_start = 0;
        for(int i = 0; i < len; i = start){
            if(len - i <= max_len / 2) break;
            int j = i;
            while(j + 1 < len && s[j] == s[j+1]){
                j++;
            }
            start = j + 1;
            left = i;
            right = j;
            int k = 0;
            while(left - k >= 0 && right + k < len && s[left-k] == s[right+k]){
                k++;
            }
            int new_len = right + k - 1 - (left - k + 1) + 1;
            if(new_len > max_len){
                max_start = left - k + 1;
                max_len = new_len;
            }
        }
        return s.substr(max_start, max_len);
    }
};
