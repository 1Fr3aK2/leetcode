#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compress(char* chars, int charsSize)
{
    int read = 0;
    int start = 0;
    int write = 0;
    while (read < charsSize)
    {
        start = read;
        while (read < charsSize && chars[start] == chars[read])
            read++;
        int count = read - start;
        chars[write++] = chars[start];
        if (count > 1)
        {
            char buffer[10];
            int len = sprintf(buffer, "%d", count);
            for (int i = 0; i < len; i++)
                chars[write++] = buffer[i];
        }
    }
    return write;
}