#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* removeStars(char* s)
{
    int len = strlen(s);   
    char *final = (char *)malloc(sizeof(char) * len + 1);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '*')
            final[j++] = s[i];
        else
        {
            final[--j] = '\0';
        }
    }
    final[j] = '\0';
    return final;
}

int main()
{
    printf("%s\n", removeStars("leet**cod*e"));
    printf("%s\n", removeStars("erase*****"));
}