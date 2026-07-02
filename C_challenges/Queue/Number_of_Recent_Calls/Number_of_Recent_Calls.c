#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    int counter;

} RecentCounter;


RecentCounter* recentCounterCreate()
{
    RecentCounter *obj = (RecentCounter *)malloc(sizeof(RecentCounter));
    obj->counter = 0;
}

int recentCounterPing(RecentCounter* obj, int t)
{
    
}

void recentCounterFree(RecentCounter* obj)
{
    
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/