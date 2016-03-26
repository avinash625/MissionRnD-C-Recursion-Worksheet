/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

void count_steps(int sum, int temp_count, int *count)
{
	if (temp_count == sum && sum != 0)
		(*count) = (*count) + 1;
	else
	{
		if (sum - temp_count > 2)
		{
			count_steps(sum, temp_count + 1, count);
			count_steps(sum, temp_count + 2, count);
		}
		else if (sum - temp_count == 1)
			(*count) = (*count) + 1;
		else if (sum - temp_count == 2)
		{
			(*count) = (*count) + 2;
		}

	}
}
int  get_steps(int s)
{
	int sum = s;
	int count = 0;
	count_steps(s, 0, &count);
	return count;
}

