#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 256

int times[SIZE];
int times1[SIZE];
int freq[SIZE];
int freq1[SIZE];

int max(const void *a, const void *b)
{
   int x = *(const int *)a;
   int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

bool closeStrings(char* word1, char* word2)
{
    memset(times, 0, sizeof(times));
    memset(times1, 0, sizeof(times1));
    int len, len1;
    len = strlen(word1);
    len1 = strlen(word2);
    if (len != len1)
        return false;
    for (int i = 0; i < len; i++)
        times[word1[i]]++;
    for (int i = 0; i < len1; i++)
        times1[word2[i]]++;
    for (int i = 0; i < SIZE; i++)
    {
        if ((times[i] == 0) != (times1[i] == 0))
            return false;
    }
    int c0 = 0, c1 = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (times[i] > 0)
            freq[c0++] = times[i];
        if (times1[i] > 0)
            freq1[c1++] = times1[i];
    }
    qsort(freq, c0, sizeof(int), max);
    qsort(freq1, c1, sizeof(int), max);
    for (int i = 0; i < c0; i++)
    {
        if (freq[i] != freq1[i])
            return false;
    }
    return true;
}