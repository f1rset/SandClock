//
// Created by f1rset on 11/12/24.
//
#include "SandClockF1rset.h"

void drop_sand(int arr[48][48], int reverse)
{
    int x = 47;
    int y = 47;
    for (int i = 0; i < 48; i++)
    {
        for (int j = 0; j < 48; j++)
        {
        		if (arr[i][j] == 1 && x+y>i+j)
        		{
        			x = i; y = j;
        		}
        }
    }
    arr[x][y] = 0;
}
void build_sand(int arr[48][48], int reverse)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < 48; i++)
    {
        for (int j = 0; j < 48; j++)
        {
        		if (arr[i][j] == 0 && x+y<i+j)
        		{
        			x = i; y = j;
        		}
        }
    }
    arr[x][y] = 1;
}
