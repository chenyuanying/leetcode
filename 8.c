// atoi
class Solution {
public:
    int myAtoi(string str) {
        long integral = 0;
        int signFlag = 0;
        int numFlag = 0;
        int sign = 1;
        for(int i = 0; i< str.size(); ++i){
            if(str[i] == ' ' && signFlag == 0 && numFlag == 0)continue;
            if(signFlag == 0 && numFlag == 0 && (str[i] == '+' || str[i] == '-')){
                signFlag = 1;
                sign = str[i] == '+' ? 1 : -1;
            }else if(str[i] >= '0' && str[i] <= '9'){
                numFlag = 1;
                integral = integral * 10 + str[i] - '0';
                if(integral * sign > INT_MAX) return INT_MAX;
                if(integral * sign < INT_MIN) return INT_MIN;
            }else if(numFlag == 1){
                break;
            }else{
                return 0;
            }
        }
        return integral * sign;
    }
};
