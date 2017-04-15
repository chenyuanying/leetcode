// 3 Sum closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2];
        int minDistance = abs(target - nums[0] - nums[1] - nums[2]);
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i){
            int left = i + 1;
            int right = nums.size() - 1;
            int targetSum = target - nums[i]; 
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum < targetSum){
                    if(abs(sum - targetSum) < minDistance){
                        result = nums[i] + nums[left] + nums[right];
                        minDistance = abs(sum - targetSum);
                    }
                    left++;
                }else if(sum > targetSum){
                    if(abs(sum - targetSum) < minDistance){
                        result = nums[i] + nums[left] + nums[right];
                        minDistance = abs(sum - targetSum);
                    }
                    right--;
                }
                else{
                    return target;
                }
            }
            
        }
        return result;
        
        
    }
};
