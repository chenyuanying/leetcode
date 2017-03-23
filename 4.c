// Median of Two Sorted Arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i;
    int index1 = 0;
    int index2 = 0;
    int numsSize = nums1Size + nums2Size;
    if(numsSize%2 == 0){
        int medianLoc = numsSize / 2;
        int med1 = 0;
        int med2 = 0;
        int currValue = 0;
        for(i=0; i<=medianLoc; ++i){
            if(index1<nums1Size && index2<nums2Size){
                if(nums1[index1]<nums2[index2]){
                    currValue = nums1[index1++];
                }else{
                    currValue = nums2[index2++];
                }
            }else if(index1 < nums1Size){
                currValue = nums1[index1++];
            }else{
                currValue = nums2[index2++];
            }
            if(i == medianLoc-1){
                med1 = currValue;
            }
            if(i == medianLoc){
                med2 = currValue;
            }
        }
        return (med1+med2) / 2.0;
    }else{
        int currValue = 0;
        int medianLoc = numsSize / 2;
        int med = 0;
        for(i=0; i<=medianLoc; ++i){
            if(index1<nums1Size && index2<nums2Size){
                if(nums1[index1]<nums2[index2]){
                    currValue = nums1[index1++];
                }else{
                    currValue = nums2[index2++];
                }
            }else if(index1 < nums1Size){
                currValue = nums1[index1++];
            }else{
                currValue = nums2[index2++];
            }
            if(i == medianLoc){
                med = currValue;
            }
        }
        return med;
    }
}
