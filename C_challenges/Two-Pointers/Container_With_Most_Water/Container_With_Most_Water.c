int findMin(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int findMax(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int maxArea(int* height, int heightSize) {
    int max = 0;
    int start = 0;
    int end = heightSize - 1;
    while (start <= end)
    {
        int width = end - start;
        int minHeight = findMin(height[start], height[end]);
        int area = minHeight * width;
        max = findMax(max, area);
        if (height[start] < height[end])
            start++;
        else
            end--;
    }
    return max;
}
