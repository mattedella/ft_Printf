/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_low.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:12:21 by mdella-r          #+#    #+#             */
/*   Updated: 2023/11/08 18:38:07 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	intcount_un_low(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_reverse_low(char *hexnb, int i)
{
	int		j;
	char	t;

	j = 0;
	while (j < (i / 2))
	{
		t = hexnb[j];
		hexnb[j] = hexnb[i - j - 1];
		hexnb[i - j - 1] = t;
		j++;
	}
	return (hexnb);
}

int	ft_convert_base_low(unsigned int nb)
{
	char	*hexnb;
	int		i;
	int		n;

	i = 0;
	if (nb == 0)
		return (write (1, "0", 1));
	hexnb = malloc(sizeof(char) * (intcount_un_low(nb) + 1));
	if (hexnb == NULL)
		return (0);
	while (nb > 0)
	{
		n = nb % 16;
		if (n < 10)
			hexnb[i] = n + '0';
		else
			hexnb[i] = n - 10 + 'a';
		i++;
		nb = nb / 16;
	}
	hexnb = ft_reverse_low(hexnb, i);
	write (1, hexnb, i);
	free (hexnb);
	return (i);
}
