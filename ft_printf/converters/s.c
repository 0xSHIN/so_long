/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 05:41:23 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/08 07:42:06 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_s(va_list arguments)
{
	char	*str;

	str = (char *)va_arg(arguments, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		ft_putstr(str);
	return (ft_strlen(str));
}
