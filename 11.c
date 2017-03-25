// Container With Most Water

class Solution {
    public:
    int maxArea(vector<int>& height){
        int water = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right){
            int minH = height[left] > height[right] ? height[right] : height[left];
            if(water < minH * (right - left)) water = minH * (right - left);
            while(height[left] <= minH) left++;
            while(height[right] <= minH) right--;
        }
        return water;
    }
};
