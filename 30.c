// Substring with Concatenation of All Words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.size() == 0) return result;
        int wordLen = words[0].size();
        int wordsLen = words.size();
        unordered_map<string,int> dict, oldDict;
        for(int i = 0; i < wordsLen; ++i){
            dict[words[i]]++;
        }
        oldDict = dict;
        for(int i = 0; i < s.size() - wordLen * wordsLen + 1; ++i){
            unordered_map<string,int> cnt;
            int j = 0;
            for(; j < wordsLen; j++){
                string str = s.substr(i + j * wordLen, wordLen);
                if(dict.count(str)){
                    dict[str]--;
                    if(dict[str] < 0)break;
                }else{
                    break;
                }
            }
            if(j == wordsLen)result.push_back(i);
            dict = oldDict;
        }
        return result;
    }
};
