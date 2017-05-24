//Count and Say
class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        string result = "1";
        for(int i = 1; i < n; ++i){
            string temp = "";
            char start = result[0];
            int count = 1;
            for(int j = 0; j < result.size(); ++j){
                 if(j + 1 < result.size()){
                     if(result[j] == result[j + 1]){
                         count++;
                     }else{
                         temp.push_back(count + '0');
                         temp.push_back(start);
                         count = 1;
                         start = result[j + 1];
                     }
                     
                 }else{
                     temp.push_back(count + '0');
                     temp.push_back(start);
                 }
            }
            result = temp;
        }
        return result;
    }
};
