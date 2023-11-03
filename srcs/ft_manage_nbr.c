/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2020/03/01 18:47:01 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	get_i(va_list valist, t_pholder *pph, t_wpieces *wp)
{
	int		nbr;

	nbr = va_arg(valist, int);
	wp->str = ft_itoa(nbr);
	wp->str_len = ft_strlen(wp->str);
	check_neg_nbr(pph, wp, nbr);
	check_precision(pph, wp);
}

void	get_d(va_list valist, t_pholder *pph, t_wpieces *wp)
{
	int		nbr;

	nbr = va_arg(valist, int);
	wp->str = ft_itoa(nbr);
	wp->str_len = ft_strlen(wp->str);
	check_neg_nbr(pph, wp, nbr);
	check_precision(pph, wp);
}

void	get_u(va_list valist, t_pholder *pph, t_wpieces *wp)
{
	wp->str = ft_ltoa(va_arg(valist, unsigned int));
	wp->str_len = ft_strlen(wp->str);
	wp->count = wp->str_len;
	check_precision(pph, wp);
}
