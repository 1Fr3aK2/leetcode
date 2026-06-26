int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

double findMaxAverage(int* nums, int numsSize, int k) {
    if (numsSize == 1)
        return nums[0];
    int save = 0;    
    int best = 0;
    int start = 0;
    int end = k;
    for (int i = 0; i < end; i++)
        save += nums[i];
    best = save;
    int i = 1;
    while (end <= numsSize - 1)
    {
        save = save - nums[i - 1] + nums[end];
        best = max(save, best);
        i++;
        end++;
    }
    return (double)best / k;
}
