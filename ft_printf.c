/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:50:18 by mdella-r          #+#    #+#             */
/*   Updated: 2023/11/13 14:23:01 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_next(const char str, va_list arg)
{
	int	j;

	j = 0;
	if (str == 'd' || str == 'i')
		j = ft_itoa(va_arg(arg, int));
	if (str == 's')
		j = ft_putstr(va_arg(arg, char *));
	if (str == 'p')
		j = ft_adr_base(va_arg(arg, unsigned long));
	if (str == 'c')
		j = ft_putchar((char)va_arg(arg, int));
	if (str == 'x')
		j = ft_convert_base_low(va_arg(arg, unsigned int));
	if (str == 'X')
		j = ft_convert_base_up(va_arg(arg, unsigned int));
	if (str == 'u')
		j = ft_itoa_un(va_arg(arg, unsigned int));
	if (str == '%')
	{
		write (1, "%", 1);
		j = 1;
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start (arg, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			j++;
		}
		else if (str[i] == '%')
		{
			i++;
			j = j + check_next(str[i], arg);
		}
		i++;
	}
	va_end (arg);
	return (j);
}
int main()
{
	int x = 3456;
	ft_printf("dio cane : %d", x);
}