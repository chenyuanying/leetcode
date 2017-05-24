// Search for a range
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        int start = 0;
        int end = 0;
        if(0 == nums.size()) return result;
        if(1 == nums.size() && nums[0] == target){ result[0] = 0; result[1] = 0; return result; }
        if(1 == nums.size() && nums[1] != target){ return result; }
        int left = 0;
        int right = nums.size() - 1;
        int pos = 0;
        // search for the starting position
        while(left < right){
            pos = (left + right) / 2;
            if(nums[pos] < target) left = pos + 1;
            if(nums[pos] > target) right = pos - 1;
            if(nums[pos] == target) right = pos;
        }
        start = right;
        if(nums[start] != target) return result;
        left = 0;
        right = nums.size() - 1;
        while(left < right){
            // converge in 2 nums case
            pos = (left + right + 1) / 2;
            if(nums[pos] < target) left = pos + 1;
            if(nums[pos] > target) right = pos - 1;
            if(nums[pos] == target) left = pos;
        }
        end = left;
        result[0] = start;
        result[1] = end;
        return result;
    }
};
