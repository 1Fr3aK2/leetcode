#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 30000

typedef struct
{
    int arr[SIZE];
    int rear;
    int front;
    int counter;

} RecentCounter;


RecentCounter* recentCounterCreate()
{
    RecentCounter *obj = (RecentCounter *)malloc(sizeof(RecentCounter));
    obj->counter = 0;
    obj->front = 0;
    obj->rear = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t)
{
    obj->arr[obj->rear++] = t; //last index = t;
    //while the value at front index < t - 3000, advance front
    while(obj->arr[obj->front] < t - 3000)
        obj->front++;
    return obj->rear - obj->front;
}

void recentCounterFree(RecentCounter* obj)
{
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/