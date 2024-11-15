/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:56:35 by mdella-r          #+#    #+#             */
/*   Updated: 2023/11/08 18:39:47 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	intcount_un(unsigned long long n)
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

long	getm_un(unsigned int n, int m)
{
	if (n / 10 == 0)
		return (m);
	else
		return (getm_un(n / 10, m * 10));
}

int	ft_itoa_un(unsigned int n)
{
	size_t		i;
	size_t		m;
	long		nb;
	char		*st;

	i = 0;
	m = getm_un(n, 1);
	nb = (unsigned long long) n;
	st = malloc((intcount_un(nb) + 1) * sizeof(char));
	if (st == NULL)
		return (0);
	while (m > 0)
	{
		st[i] = (nb / m) % 10 + 48;
		m = m / 10;
		write (1, &st[i], 1);
		i++;
	}
	free (st);
	return (i);
}
