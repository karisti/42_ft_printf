/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:16:55 by karisti-          #+#    #+#             */
/*   Updated: 2020/02/29 17:16:15 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "libft.h"
# include <stdarg.h>

typedef	struct	s_pholder
{
	int		sign;
	int		jright;
	int		fill;
	int		width;
	int		precision;
	int		specifier;
}				t_pholder;

typedef	struct	s_wpieces
{
	char	*prev;
	int		prev_len;
	int		pad_l;
	int		precision;
	char	*str;
	int		pad_r;
	int		str_len;
	int		count;
}				t_wpieces;

char			*is_placeholder(char *str);
t_pholder		*get_flags(char *placeholder);
int				print_argument(va_list valist, t_pholder *pph);
void			check_neg_width(t_pholder *pph);
void			check_pads(t_pholder *pph, t_wpieces *wp);
void			check_neg_nbr(t_pholder *pph, t_wpieces *wp, int nbr);
void			check_precision(t_pholder *pph, t_wpieces *wp);
void			get_c(va_list valist, t_pholder *pph, t_wpieces *wp);
void			get_s(va_list valist, t_pholder *pph, t_wpieces *wp);
void			get_i(va_list valist, t_pholder *pph, t_wpieces *wp);
void			get_d(va_list valist, t_pholder *pph, t_wpieces *wp);
void			get_u(va_list valist, t_pholder *pph, t_wpieces *wp);
void			get_x(va_list valist, t_pholder *pph, t_wpieces *wp);
void			get_p(va_list valist, t_pholder *pph, t_wpieces *wp);
void			get_per(va_list valist, t_pholder *pph, t_wpieces *wp);
#endif
