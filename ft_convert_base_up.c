/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:11:59 by mdella-r          #+#    #+#             */
/*   Updated: 2023/11/08 18:38:09 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	intcount_un_up(unsigned int n)
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

char	*ft_reverse_up(char *hexnb, int i)
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

int	ft_convert_base_up(unsigned int nb)
{
	char	*hexnb;
	int		i;
	int		n;

	i = 0;
	if (nb == 0)
		return (write (1, "0", 1));
	hexnb = malloc(sizeof(char) * (intcount_un_up(nb) + 1));
	if (hexnb == NULL)
		return (0);
	while (nb > 0)
	{
		n = nb % 16;
		if (n < 10)
			hexnb[i] = n + '0';
		else
			hexnb[i] = n - 10 + 'A';
		i++;
		nb = nb / 16;
	}
	hexnb = ft_reverse_up(hexnb, i);
	write (1, hexnb, i);
	free (hexnb);
	return (i);
}
