#include "libft.h"

void	ft_ulstr(char c)
{
	char	temp;

	if (c >= 'a' && c <= 'z')
		temp = c - 32;
	else if (c >= 'A' && c <= 'Z')
		temp = c + 32;
	else
		temp = c;
	write(1, &temp, 1);
}