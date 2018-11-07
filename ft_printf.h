#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h> // just for testing!
#include <unistd.h>
#include <wchar.h>
#include "libft.h"

typedef struct s_flags
{
  char hash;
  char zero;
  char space;
  char plus;
  char minus;
} t_flags;

typedef struct s_width
{
  int l;
} t_width;

typedef struct s_precision
{
  int l;
} t_precision;

typedef struct s_length
{
  char hh;
  char h;
  char l;
  char ll;
  char j;
  char z;
} t_length;

typedef struct s_data
{
  char percent;
  char s;
  char l_s;
  char p;
  char d;
  char l_d;
  char i;
  char o;
  char l_o;
  char u;
  char l_u;
  char x;
  char l_x;
  char c;
  char w_c;
} t_datatype;

typedef struct s_fmt
{
  t_flags flags;
  t_width w;
  t_precision pre;
  t_length l;
  t_datatype type;
} t_fmt;

void ft_printf(char *fmt, ...);
/*
*/
void ft_reset_fmt(t_fmt *fmt);
void ft_reset_flags(t_flags *flags);
void ft_reset_width(t_width *w);
void ft_reset_precision(t_precision *pre);
void ft_reset_length(t_length *len);
void ft_reset_type(t_datatype *type);
/*
*/
char *ft_set_flags(char *str, t_flags *flags);
char *ft_set_width(char *str, t_width *w, va_list *ap);
char *ft_set_precision(char *str, t_precision *pre, va_list *ap);
char *ft_set_length(char *str, t_length *len);
void ft_set_type(char *str, t_datatype *type);
void ft_check_for_bad_format(t_fmt *fmt);
/*
*/
void ft_percent(void);
void ft_s(t_fmt *fmt, va_list *ap);
void ft_d(t_fmt *fmt, va_list *ap);
void ft_p(t_fmt *fmt, va_list *ap);

char *ft_itoa_2(long long int n, int *ret,  int *neg);
void ft_itoabase_max(long long int base, long long int nb, char *buff, int *i);

char *ft_d_buff(t_fmt *fmt, char *buff, int *size, int neg);
char *ft_put_buff_into_width(t_fmt *fmt, char *buff);
char *ft_add_zeros(char *buff, int pre, int size, int neg, char p);
char *ft_add_space( char *buff, int size, int neg);
char *ft_add_plus(char *buff, int *size, int neg);

char			*ft_itoa_16(long long int n, int *ret, int *neg);
void ft_x(t_fmt *fmt, va_list *ap);
void ft_o(t_fmt *fmt, va_list *ap);
char			*ft_itoa_8(long long int n, int *ret, int *neg);


#endif
