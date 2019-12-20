/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 14:19:34 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/20 12:05:52 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int		width;
	int		precision;
	int		leftj;
	char	sign;
	int		signornot;
	int		zero;
	int		hash;
	char	length;
	int		nbrlen;
}				t_flags;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);

int				parse_spec(char **start, t_flags *flags, va_list list, int *rv);
void			parse_flags(char **start, t_flags *flags);
void			parse_hub(char **start, t_flags *flags, va_list list, int *rv);
void			parse_length(char **start, t_flags *flags);
void			parse_precision(char **start, t_flags *flags, va_list list);
void			parse_width(char **start, t_flags *flags, va_list list);

int				ft_printf(const char *str, ...);
void			printchar(t_flags *flags, va_list list, int *rv);
void			printhex(char **start, t_flags *flags, va_list list, int *rv);
void			printhex_lower(t_flags *flags, va_list list, int *rv);
void			printhex_upper(t_flags *flags, va_list list, int *rv);
void			printint(t_flags *flags, va_list list, int *rv);
void			printint_reg(t_flags *flags, va_list list, int *rv);
void			printint_l(t_flags *flags, va_list list, int *rv);
void			printint_ll(t_flags *flags, va_list list, int *rv);
void			printstr(t_flags *flags, va_list list, int *rv);
void			printun(t_flags *flags, va_list list, int *rv);
void			padder(int width, int precision, char pad, int *rv);

void			prepare_hex(t_flags *flags, unsigned int *nbr);
void			prepare_int(t_flags *flags, int *nbr);
void			prepare_l_int(t_flags *flags, long int *nbr);
void			prepare_ll_int(t_flags *flags, long long int *nbr);
void			prepare_un(t_flags *flags, unsigned int *nbr);

int				ft_nbrlen(int nbr);
int				ft_nbrlen_hex(unsigned int nbr);
int				ft_nbrlen_l(long int nbr);
int				ft_nbrlen_ll(long long int nbr);
int				ft_nbrlen_un(unsigned int nbr);

void			ft_putchar_fd_count(char c, int fd, int *rv);
void			ft_puthex_lower_count(unsigned int nbr, int *rv);
void			ft_puthex_upper_count(unsigned int nbr, int *rv);
void			ft_putnbr_fd_count(int n, int fd, int *rv);
void			ft_putnbr_l_fd_count(long int nbr, int *rv);
void			ft_putnbr_ll_fd_count(long long int nbr, int *rv);
void			ft_putnstr_fd_count(char *s, int fd, int n, int *rv);
void			ft_putunsigned_fd(unsigned n, int fd, int *rv);

#endif