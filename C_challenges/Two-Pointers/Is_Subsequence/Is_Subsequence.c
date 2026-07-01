#include <unistd.h>
#include <stdlib.h>


bool isSubsequence(char* s, char* t) 
{
    int i = 0;
    for (int j = 0; t[j] != '\0'; j++)
    {
        if (s[i] == '\0')
            return true;
        else if (s[i] == t[j])
            i++;
    }
    return s[i] == '\0';
}
