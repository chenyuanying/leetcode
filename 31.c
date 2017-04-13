// Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)return;
        int pos = -1;
        for(int i = nums.size() - 2; i >= 0; --i){
            if(nums[i] < nums[i+1]){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size() - 1; i >= pos + 1; --i){
            if(nums[i] > nums[pos]){
                int tmp = nums[i];
                nums[i] = nums[pos];
                nums[pos] = tmp;
                break;
            }
        }
        reverse(nums.begin() + pos + 1, nums.end());
    }
};
