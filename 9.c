// Palindrome Number
// This Question is not so good in my opinion.
// Requirement of "Can not use extra space" is confusing
// However, this solution presented by gaurav5 is inspiring
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x != 0 && x % 10 == 0) return false;
        int reverse = 0;
        while(x > sum){
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }
        return (x == reverse) || (x == reverse / 10);
    }
};
