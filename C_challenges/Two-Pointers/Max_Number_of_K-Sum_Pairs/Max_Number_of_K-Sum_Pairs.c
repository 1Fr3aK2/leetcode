int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maxOperations(int* nums, int numsSize, int k){
    int start = 0;
    int count = 0;
    int end = numsSize - 1;
    qsort(nums, numsSize, sizeof(int), compare);
    while(start < end)
    {
        if (nums[start] + nums[end] == k)
        {
            count++;
            start++;
            end--;
        }
        else if (nums[start] + nums[end] < k)
            start++;
        else
            end--;
    }
    return count; 
}
