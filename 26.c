// Remove Duplicates from sorted array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        int prev = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i == 0 || nums[i] != prev){
                nums[len] = nums[i];
                len++;
                prev = nums[i];
            }
        }
        return len;
    }
};
