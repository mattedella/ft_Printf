/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:42:45 by mdella-r          #+#    #+#             */
/*   Updated: 2023/11/08 17:33:46 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

void	ft_put_ptr(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar((nb + '0'));
		else
			ft_putchar((nb - 10 + 'a'));
	}
}

int	ft_adr_base(unsigned long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		i = i + write(1, "(nil)", 5);
	else
	{
		i = i + write(1, "0x", 2);
		ft_put_ptr(ptr);
		i = i + ft_len(ptr);
	}
	return (i);
}
