/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:29:00 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 18:42:36 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct		s_flag
{
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hashtag;
}					t_flag;

typedef struct		s_format
{
	char			convert;
	char			*length;
	int				width;
	int				len;
	int				dot;
	int				precision;
	t_flag			flag;
}					t_format;

typedef char		*(*t_fun)(t_format*, va_list*);

char				*ft_print_char(t_format *format, va_list *arg);
char				*ft_print_str(t_format *format, va_list *arg);
char				*ft_print_nbr(t_format *format, va_list *arg);
char				*ft_print_unbr(t_format *format, va_list *arg);
char				*ft_print_hex(t_format *format, va_list *arg);
char				*ft_print_octal(t_format *format, va_list *arg);
char				*ft_print_point(t_format *format, va_list *arg);
char				*ft_print_wstr(t_format *format, va_list *arg);
char				*ft_print_binary(t_format *format, va_list *arg);

size_t				ft_wstrlen(unsigned *str);

t_flag				ft_firstflags(char *format, size_t *i);
long long			ft_convertflags(t_format *format, va_list *arg);
unsigned long long	ft_uconvertflags(t_format *format, va_list *arg);
int					ft_flag_width(char *format, size_t *i,
					va_list *arg, t_format *star);
char				*ft_length(char *format, size_t *i);
int					ft_precision(char *format, size_t *i,
					va_list *arg, t_format *conv);
t_format			*ft_flags(char *format, va_list *arg, size_t *i);

int					ft_type(t_format *format, va_list *arg);
t_fun				ft_function(char c);

void				ft_delmem(t_format *array);
int					ft_printf(char *format, ...);

#endif
