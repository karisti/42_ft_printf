/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2020/02/29 17:04:24 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	check_pads(t_pholder *pph, t_wpieces *wp)
{
	int pad;

	pad = pph->width - wp->str_len - wp->precision - wp->prev_len;
	if (pad < 0)
		pad = 0;
	if (pph->width)
	{
		if (pph->jright)
			wp->pad_r = pad;
		else
			wp->pad_l = pad;
	}
}

void	check_neg_width(t_pholder *pph)
{
	if (pph->width < 0)
	{
		pph->width = pph->width * -1;
		if (!pph->jright)
			pph->jright = 1;
	}
}

void	check_neg_nbr(t_pholder *pph, t_wpieces *wp, int nbr)
{
	char	*tmp;

	if (nbr < 0 || pph->sign == ' ' || pph->sign == '+')
	{
		if (nbr < 0)
		{
			wp->prev = ft_strdup("-");
			tmp = wp->str;
			wp->str = ft_substr(tmp, 1, wp->str_len--);
			free(tmp);
		}
		else
		{
			wp->prev = ft_strfromchar(pph->sign);
		}
		wp->prev_len = ft_strlen(wp->prev);
	}
}

void	check_precision(t_pholder *pph, t_wpieces *wp)
{
	if (pph->precision > -2)
	{
		pph->fill = ' ';
		if (pph->precision > wp->str_len)
			wp->precision = pph->precision - wp->str_len;
		if (pph->precision == 0 && wp->str[0] == '0')
			wp->str_len = pph->precision;
	}
}
