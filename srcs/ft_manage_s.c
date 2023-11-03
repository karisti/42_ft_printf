/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2020/02/29 14:29:17 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	get_s(va_list valist, t_pholder *pph, t_wpieces *wp)
{
	char *s;

	if (!(s = va_arg(valist, char *)))
		wp->str = ft_strdup("(null)");
	else
		wp->str = ft_strdup(s);
	wp->str_len = ft_strlen(wp->str);
	if (pph->precision < wp->str_len && pph->precision > -2)
		wp->str_len = pph->precision;
}
