#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

bool isVowel(char s)
{
    char *vowels = "aeiou";
    while(*vowels)
    {
        if (s == *vowels)
            return true;
        vowels++;
    }
    return false;
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

int maxVowels(char* s, int k) {
    int count = 0;
    int best;
    int end = k;
    int len = strlen(s);
    for (size_t i = 0; i < end; i++)
    {
        if (isVowel(s[i]))
            count++;
    }
    best = count;
    for (size_t i = 1; end < len; i++, end++)
    {
        if (isVowel(s[i - 1]))
            count--;
        if (isVowel(s[end]))
            count++;
        best = max(best, count);
    }
    return (best);
}

int main()
{
    printf("%d\n", maxVowels("abciiidef", 3));
}