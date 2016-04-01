/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *spiral_wrapper(int **input_array, int *result, int rows, int columns, int startingx, int endingx, int startingy, int endingy, int index)
{
	int temp;
	if (index > rows*columns - 1)
	{
		return result;
	}
	else
	{
		for (temp = startingy; temp <= endingy; temp = temp + 1)
		{
			result[index] = input_array[startingx][temp];
			index++;
		}
		startingx++;
		for (temp = startingx; temp <= endingx; temp = temp + 1)
		{
			result[index] = input_array[temp][endingy];
			index++;
		}
		endingy--;
		if (startingx < endingx)
		{
			for (temp = endingy; temp >= startingy; temp -= 1)
			{
				result[index] = input_array[endingx][temp];
				index++;
			}
			endingx--;
		}
		if (startingy < endingy)
		{
			for (temp = endingx; temp >= startingx; temp -= 1)
			{
				result[index] = input_array[temp][startingy];
				index++;
			}
			startingy++;
		}
		if (index == rows*columns - 1)
		{
			if (startingx == startingy && endingx == endingy)
				result[index] = input_array[startingx][endingy];
			return result;
		}
	}
	return spiral_wrapper(input_array, result, rows, columns, startingx, endingx, startingy, endingy, index);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL)
		return NULL;
	if (rows <= 0 || columns <= 0)
		return NULL;
	int *result = (int *)malloc(sizeof(int)*(rows*columns));
	int index = 0, startingx = 0, endingx = rows - 1, startingy = 0, endingy = columns - 1;
	result = spiral_wrapper(input_array, result, rows, columns, startingx, endingx, startingy, endingy, index);
	return result;
}
