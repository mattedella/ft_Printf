/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:54:07 by mdella-r          #+#    #+#             */
/*   Updated: 2023/11/13 10:33:57 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_itoa(int n);
int	ft_itoa_un(unsigned int n);
int	ft_convert_base_up(unsigned int nb);
int	ft_convert_base_low(unsigned int nb);
int	ft_adr_base(unsigned long ptr);
int	ft_putchar(char c);
int	ft_putstr(char *str);

#endif
