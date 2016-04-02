/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int A[6] = { 0 };
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL || len <= 0)
		return NULL;
	int i, j, k, flag1 = 0, flag2 = 0;
	float temp1, temp2,temp3;
	for (i = 0, j = 1, k = 2; k < len&&j < len - 1 && i < len - 2; i++, j++, k++)
	{
		temp1 = arr[i];
		temp2 = arr[j];
		temp3 = arr[k];
		if ((2 * temp2) == (temp1 + temp3))
		{
			if (flag1 == 0)
			{
				A[0] = i;
				flag1 = 1;
			}
			if (i<A[1] || A[1] == 0)
				A[1] = k;
			if (i >= A[1])
			{
				if (A[2] == 0)
					A[2] = i;
				A[3] = k;
			}

		}
		else
		{

			temp1 = arr[i];
			temp2 = arr[j];
			int temp3 = arr[k];
			if ((temp2*temp2) == (temp1*temp3))
			{
				if (flag2 == 0)
				{
					A[4] = i;
					flag2 = 1;
				}
				A[5] = k;
			}

		}
	}
	return(A);
}