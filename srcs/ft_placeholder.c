/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:32:02 by karisti-          #+#    #+#             */
/*   Updated: 2020/02/29 12:10:45 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

t_pholder	*init_placeholder(void)
{
	t_pholder *pph;

	if ((pph = ft_calloc(1, sizeof(t_pholder))))
	{
		pph->fill = ' ';
		pph->jright = 0;
		pph->precision = -2;
		pph->sign = 0;
		pph->specifier = 0;
		pph->width = 0;
	}
	return (pph);
}

char		*is_placeholder(char *str)
{
	char	*ret;
	char	*del;

	ret = ft_substr("", 0, 0);
	if (ret && *str == '%')
	{
		while (++str && ft_strchr("0123456789-+*. ", *str))
		{
			del = ret;
			ret = ft_strjoinchar(ret, *str);
			free(del);
		}
		if (str && ft_strchr("cspdiuxX%", *str))
		{
			del = ret;
			ret = ft_strjoinchar(ret, *str);
			free(del);
		}
		if (ft_strlen(ret) > 0)
			return (ret);
	}
	free(ret);
	return (NULL);
}

int			take_num(char *placeholder)
{
	int width;

	width = 0;
	if (*placeholder == '*')
		return (-1);
	else
	{
		while (ft_isdigit(*placeholder))
			width = (width * 10) + *(placeholder++) - '0';
	}
	return (width);
}

t_pholder	*get_flags(char *placeholder)
{
	t_pholder *pph;

	pph = init_placeholder();
	while (*placeholder == '-' || *placeholder == '+' ||
		*placeholder == ' ' || *placeholder == '0')
	{
		if (*placeholder == '0')
			pph->fill = *placeholder;
		if ((*placeholder == ' ' || *placeholder == '+') && pph->sign == 0)
			pph->sign = *placeholder;
		if (*placeholder == '-')
			pph->jright = 1;
		placeholder++;
	}
	pph->width = take_num(placeholder);
	while (*placeholder == '*' || ft_isdigit(*placeholder))
		placeholder++;
	if (*placeholder == '.')
		pph->precision = take_num(++placeholder);
	pph->specifier = placeholder[ft_strlen(placeholder) - 1];
	return (pph);
}
