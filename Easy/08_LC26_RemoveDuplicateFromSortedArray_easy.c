int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int insertIndex = 1; 
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }    
    return insertIndex;
}
