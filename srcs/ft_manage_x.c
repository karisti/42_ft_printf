/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2020/03/01 18:46:57 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	get_x(va_list valist, t_pholder *pph, t_wpieces *wp)
{
	wp->str = ft_itoabase(va_arg(valist, unsigned int), 16);
	if (pph->specifier == 'X')
		wp->str = ft_strtoupper(wp->str);
	wp->str_len = ft_strlen(wp->str);
	check_precision(pph, wp);
}
