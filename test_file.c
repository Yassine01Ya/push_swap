#include "push_swap.h"

int main (int c, char **v)
{
	if (c > 1)
	{
	int i =1;
	while(i < c)
	{
		check_args_is_valid(&v[i]);
		i++;
	}
	}
	return 0;
}