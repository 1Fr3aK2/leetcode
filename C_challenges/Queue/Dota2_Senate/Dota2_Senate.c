#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 30000

//define 2 arrays to store the locations
int Radiant[SIZE];
int Dire[SIZE];

char* predictPartyVictory(char* senate)
{
    //initialize the arrays with '0s'
    memset(Radiant, 0, sizeof(Radiant));
    memset(Dire, 0, sizeof(Dire));
    int len = strlen(senate); //define the length of senate
    //iterators to iterate over the arrays
    int R = 0;
    int D = 0;
    for (int i = 0; i < len; i++)
    {
        if (senate[i] == 'R')
            Radiant[R++] = i;
        else
            Dire[D++] = i;
    }
    //iterator at the beggining and at the end of the arrays
    int frontR, rearR, frontD, rearD;
    frontR = 0;
    frontD = 0;
    rearR = R;
    rearD = D;
    while(frontR < rearR && frontD < rearD)
    {
        //if its position is lower
        if (Radiant[frontR] < Dire[frontD])
        {
            //save the location to play again
            Radiant[rearR++] = Radiant[frontR] + len;
            //both fronts advance because 1 played and blocked the other
            frontR++;
            frontD++;
        }
        else
        {
            //same as before
            Dire[rearD++] = Dire[frontD] + len;
            frontD++;
            frontR++;
        }
    }
    if (frontD == rearD) //if both pointers are at the same position it means they reach the end (lose)
        return ("Radiant");
    else
        return ("Dire");
}