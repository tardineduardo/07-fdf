#include "../libft.h"

/* converts ascii representation of hex into long long, trimms "0x" if needed. */
long long ft_atohx(char *s)
{
    size_t	len;
    llong	nb;
    char	*trimm;
    char	*upper;
    char	*lower;
    char	c;
    int		value;
    int		j;

    nb = 0;
    trimm = s;
    upper = "0123456789ABCDEF";
    lower = "0123456789abcdef";

    if (ft_strnstr(s, "0x", 2) || ft_strnstr(s, "0X", 2))
        trimm = s + 2;

    len = ft_strlen(trimm);

    while (len > 0 && *trimm)
    {
        c = *trimm;
        value = -1;

        j = 0;
        while (j < 16)
        {
            if (c == upper[j] || c == lower[j])
            {
                value = j;
                break;
            }
            j++;
        }
        if (value == -1)
            return -1;
        nb = nb * 16 + value;
        trimm++;
        len--;
    }
    return nb;
}
