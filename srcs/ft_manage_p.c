/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2020/03/01 18:47:02 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	get_p(va_list valist, t_pholder *pph, t_wpieces *wp)
{
	wp->prev = ft_strdup("0x");
	wp->prev_len = ft_strlen(wp->prev);
	wp->str = ft_itoabase(va_arg(valist, unsigned long), 16);
	wp->str_len = ft_strlen(wp->str);
	check_precision(pph, wp);
}
