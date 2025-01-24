#include "push_swap.h"

int	calculate_bit_size(int numcount)
{
	int bit_count;

	bit_count = 0;
	
	while (numcount > 0)
	{
		bit_count++;
		numcount >>= 1;
	}
	if (bit_count == 0)
		bit_count = 1;
	return (bit_count);
}

