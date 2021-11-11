/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:33:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/11 11:21:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# define FLAG_CHARS		"-0+ #"
# define LEN_MODIF		"hlL"
# define CONVERT_SPEC	"cspdiuxX%"

# include <wchar.h>
# include <stdarg.h>
# include <stdbool.h>
# include "type/t_ctx.h"

int		ft_atoi(char const *str);
int		ft_llintlen(t_llint nb);
int		ft_lluintlen_bin(t_lluint nb);
int		ft_lluintlen_hexa(t_lluint nb);
int		ft_lluintlen_oct(t_lluint nb);
int		ft_lluintlen(t_lluint nb);
int		ft_putchar(char const c);
int		ft_putwchar(wchar_t const wc);
int		ft_strlen(char const *str);
int		ft_wclen(wchar_t const wc);
int		ft_wstrlen(wchar_t const *str);
int		ft_wstrsize(wchar_t const *str);
int		padding(int const c, int padlen);
int		putnil(t_ctx *const ctx);
int		putnull(t_ctx *const ctx);

char	*ft_strchr(char const *str, char const c);
char	*manage_cvrt(char const *format, t_ctx *const ctx, va_list va);
char	*parse_flags(char const *format, t_ctx *const ctx);
char	*parse_fwidth(char const *format, t_ctx *const ctx, va_list va);
char	*parse_lmod(char const *format, t_ctx *const ctx);
char	*parse_prec(char const *format, t_ctx *const ctx, va_list va);
char	*manage_spec(char const *format, t_ctx *const ctx, va_list va);
char	*manage_text(char const *format, t_ctx *const ctx);

void	ft_putllint(t_llint const nb);
void	ft_putlluint_bin(t_lluint const nb);
void	ft_putlluint_hexa(t_lluint const nb, char const c);
void	ft_putlluint_oct(t_lluint const nb);
void	ft_putlluint(t_lluint const nb);

bool	ft_isspace(char const c);
bool	ft_isdigit(char const c);

#endif
