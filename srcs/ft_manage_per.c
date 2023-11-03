/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2020/02/29 15:27:27 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	get_per(va_list valist, t_pholder *pph, t_wpieces *wp)
{
	wp->str = ft_strfromchar('%');
	wp->str_len = 1;
	if (!valist)
		NULL;
	pph->fill = pph->fill;
}
