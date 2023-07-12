/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:37:45 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 05:24:32 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	va_list			arguments;
	size_t			i;
	size_t			len;
	int				count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	len = ft_strlen(str);
	va_start(arguments, str);
	while (i < len)
	{
		if (str[i] == '%' && check(str[i + 1]) == 1)
		{
			count += ft_flags(str[i + 1], arguments);
			i += 2;
		}
		else if (str[i])
			count += write(1, &str[i++], 1);
	}
	va_end(arguments);
	return (count);
}
