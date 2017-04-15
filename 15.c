// 3 sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i){
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            
            while(right > left){
                
                int sum = nums[left] + nums[right];
                
                if(sum == target){
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    result.push_back(triplet);
                    while(left < right && nums[left] == triplet[1]) left++;
                    while(left < right && nums[right] == triplet[2]) right--;
                }
                else if(sum < target) left++;
                else right--;
                
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
            
        }
        return result;
    }
};
