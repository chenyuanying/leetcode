// Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(char* s) {
    int pos[256];
    int len = strlen(s);
    int maxlen = 0;
    int start = -1;
    int i;
    for(i=0; i<256; ++i){
        pos[i] = -1;
    }
    for(i=0; i <len; ++i){
        if(pos[s[i]] > start){
            start = pos[s[i]];
        }
        maxlen = i-start > maxlen ? i-start : maxlen;
        pos[s[i]] = i;
    }
    return maxlen;
}
