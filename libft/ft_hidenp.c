#include "libft.h"

int	ft_hidenp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s2[++j])
	{
		if (s1[i] == s2[j])
			i++;
	}
	return (ft_strlen(s1) == (unsigned)i);
}
