// Letter Combinations of a phone number
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return vector<string>();
        
        vector<string> result;
        static const vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        result.push_back("");
        
        for(int i = 0; i < digits.size(); ++i){
            
            vector<string> tmp;
            for(int j = 0; j < nums[digits[i] - '0'].size(); ++j){
                for(int k = 0; k < result.size(); ++k){
                    tmp.push_back(result[k] + nums[digits[i] - '0'][j]);
                }
            }
            result.swap(tmp); // swap does not require memory copy
        }
        
        return result;

    }
};
