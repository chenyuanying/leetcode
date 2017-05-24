// Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(0 == nums.size()) return -1;
        int pivot = nums[0];
        int left = 1;
        int right = nums.size() - 1;
        int pos = 1;
        while(left < right){
            pos = (left + right) / 2;
            if(nums[pos] > pivot) left = pos + 1;
            if(nums[pos] < pivot) right = pos;
        }
        if(nums[right] > pivot) right++;
        if(target == pivot) return 0;
        if(target > pivot){
            if(binary_search(nums.begin(), nums.begin() + right, target)){
                return lower_bound(nums.begin(), nums.begin() + right, target) - nums.begin();
            }else{
                return -1;
            }
        }else{
            if(binary_search(nums.begin() + right , nums.end(), target)){
                return lower_bound(nums.begin() + right, nums.end(), target) - nums.begin();
            }else{
                return -1;
            }
        }
    }
};
