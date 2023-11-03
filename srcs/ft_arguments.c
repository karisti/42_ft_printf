/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:34:24 by karisti-          #+#    #+#             */
/*   Updated: 2020/02/29 17:07:32 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void		ft_printn(char *s, int len)
{
	while (len-- > 0)
		ft_putchar_fd(*s++, 1);
}

void		put_padding(int len, char c)
{
	while (len-- > 0)
		ft_putchar_fd(c, 1);
}

t_wpieces	*init_wpieces(va_list valist, t_pholder *pph,
		void (*param_to_str)(va_list valist, t_pholder *pph,
		t_wpieces *wp))
{
	t_wpieces *wp;

	if ((wp = ft_calloc(1, sizeof(t_wpieces))))
	{
		wp->precision = 0;
		wp->pad_l = 0;
		wp->pad_r = 0;
		wp->str_len = 0;
		wp->count = 0;
		wp->prev = NULL;
		wp->prev_len = 0;
		param_to_str(valist, pph, wp);
		check_neg_width(pph);
		check_pads(pph, wp);
		wp->count = wp->pad_l + wp->prev_len + wp->precision + \
				wp->str_len + wp->pad_r;
	}
	return (wp);
}

int			print(va_list valist, t_pholder *pph,
		void (*param_to_str)(va_list valist, t_pholder *pph,
		t_wpieces *wp))
{
	t_wpieces	*wp;

	wp = init_wpieces(valist, pph, param_to_str);
	if (wp->prev && pph->fill == '0')
		ft_printn(wp->prev, wp->prev_len);
	put_padding(wp->pad_l, pph->fill);
	if (wp->prev && (pph->fill == ' '))
		ft_printn(wp->prev, wp->prev_len);
	put_padding(wp->precision, '0');
	ft_printn(wp->str, wp->str_len);
	put_padding(wp->pad_r, ' ');
	free(wp->str);
	free(wp->prev);
	free(wp);
	return (wp->count);
}

int			print_argument(va_list valist, t_pholder *pph)
{
	if (pph->width == -1)
		pph->width = va_arg(valist, int);
	if (pph->precision == -1)
		pph->precision = va_arg(valist, int);
	if (pph->specifier == 'c')
		return (print(valist, pph, get_c));
	else if (pph->specifier == 's')
		return (print(valist, pph, get_s));
	else if (pph->specifier == 'i')
		return (print(valist, pph, get_i));
	else if (pph->specifier == 'd')
		return (print(valist, pph, get_d));
	else if (pph->specifier == 'u')
		return (print(valist, pph, get_u));
	else if (pph->specifier == 'x' || pph->specifier == 'X')
		return (print(valist, pph, get_x));
	else if (pph->specifier == 'p')
		return (print(valist, pph, get_p));
	else if (pph->specifier == '%')
		return (print(NULL, pph, get_per));
	return (-1);
}
