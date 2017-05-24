// Search Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0 || (nums.size() > 0 && nums[0] >= target)) return 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i + 1 < nums.size()){
                if(nums[i] == target) return i;
                if(nums[i] < target && nums[i+1] > target) return i + 1;
            }else return nums[i] >= target ? i : i + 1;
        }
    }
};
