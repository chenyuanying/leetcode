// 4 Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums, int target){
        vector<vector<int>> result;
        
        for(int i = 0; i < nums.size(); ++i){
            int target2Nums = target - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            
            while(right > left){
                
                int sum = nums[left] + nums[right];
                
                if(sum == target2Nums){
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    result.push_back(triplet);
                    while(left < right && nums[left] == triplet[1]) left++;
                    while(left < right && nums[right] == triplet[2]) right--;
                }
                else if(sum < target2Nums) left++;
                else right--;
                
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
            
        }
        return result;
    }
    

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i){
            int target3Nums = target - nums[i];
            if(i + 1 < nums.size() - 1){
                vector<int> numsCall(nums.begin() + i + 1, nums.end());
                vector<vector<int>> triplets = threeSum(numsCall, target3Nums);
                for(int j = 0; j < triplets.size(); ++j){
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = nums[i];
                    quadruplet[1] = triplets[j][0];
                    quadruplet[2] = triplets[j][1];
                    quadruplet[3] = triplets[j][2];
                    result.push_back(quadruplet);
                }
 
            }

            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }

};
