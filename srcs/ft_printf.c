/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:12:04 by karisti-          #+#    #+#             */
/*   Updated: 2020/03/03 16:08:55 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int		ft_printf(const char *str, ...)
{
	va_list		valist;
	char		*p_hold;
	int			ret;
	t_pholder	*pph;

	ret = 0;
	va_start(valist, str);
	while (*str)
	{
		if (!(p_hold = is_placeholder((char *)str)))
		{
			ft_putchar_fd(*str++, 1);
			ret++;
		}
		else
		{
			pph = get_flags(p_hold);
			ret += print_argument(valist, pph);
			free(pph);
			str += ft_strlen(p_hold) + 1;
		}
		free(p_hold);
	}
	va_end(valist);
	return (ret);
}
