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

int *insert_spiral(int **arr, int row, int col, int x, int y, int *result, int count, int ind){
	if (count>=ind)return result;
	int rindex, cindex;
	for (cindex = y; cindex<col; cindex++, count++)
		result[count] = arr[x][cindex];
	for (rindex = x + 1; rindex<row; rindex++, count++){
		result[count] = arr[rindex][cindex - 1];
	}
	for (cindex = cindex - 2; cindex >= y; cindex--){
		result[count] = arr[rindex - 1][cindex];
		count++;
	}
	for (rindex = rindex - 2; rindex>x; rindex--){
		result[count] = arr[rindex][cindex + 1];
		count++;
	}
	insert_spiral(arr, row - 1, col - 1, x + 1, y + 1, result, count, ind);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;
	int *result = (int *)malloc(sizeof(int)*rows*columns);
	insert_spiral(input_array, rows, columns, 0, 0, result, 0, rows*columns);
	return result;
}