#include "libft.h"

int	ft_pgcd(int a, int b)
{
	int	dv;
	int	ans;

	dv = a <= b ? a : b;
	ans = 0;
	while (dv > 0)
	{
		if (a % dv == 0 && b % dv == 0)
		{
			ans = dv;
			break ;
		}
		dv--;
	}
	return (ans);
}
