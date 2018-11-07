#include "ft_printf.h"

void ft_error(char *s)
{
  ft_putstr(s);
  exit(1);
}

char *ft_set_flags(char *str, t_flags *flags)
{
  while (*str == '0' || *str == ' ' || *str == '+' || *str == '-' || *str == '#')
  {
    if (!flags->zero && *str == '0')
      flags->zero = 1;
    else if (!flags->space && *str == ' ')
      flags->space = 1;
    else if (!flags->plus && *str == '+')
      flags->plus = 1;
    else if (!flags->minus && *str == '-')
      flags->minus = 1;
    else if (!flags->hash && *str == '#')
      flags->hash = 1;
    str++;
  }
  (flags->minus) ? (flags->zero = 0): 0;
  return (str);
}
char *ft_set_width(char *str, t_width *w, va_list *ap)
{
  if (*str == '*')
  {
    w->l = va_arg(*ap, int);
    str++;
    return (str);
  }
  else
  {
    w->l = ft_atoi(str);
    while(*str >= '0' && *str <= '9')
      str++;
  }
  return (str);
}

char *ft_set_precision(char *str, t_precision *pre, va_list *ap)
{
  if (*str != '.')
    return(str);

  if (*++str == '*')
  {
    pre->l = va_arg(*ap, int);
    str++;
    return (str);
  }
  else
  {
    pre->l = ft_atoi(str);
    while(*str >= '0' && *str <= '9')
      str++;
  }
  return (str);
}
char *ft_set_length(char *str, t_length *l)
{
  (*str == 'h' && *(str+1) == 'h') ? l->hh = 1 : 0;
  (*str == 'h' && *(str+1) != 'h') ? l->h = 1 : 0;
  (*str == 'l' && *(str+1) == 'l') ? l->ll = 1 : 0;
  (*str == 'l' && *(str+1) != 'l') ? l->l = 1 : 0;
  (*str == 'j') ? l->j = 1 : 0;
  (*str == 'z') ? l->z = 1 : 0;
  while (*str == 'h'||  *str == 'l'||  *str == 'j'|| *str == 'z')
    str++;
  return (str);
}
// void ft_check_for_bad_format(char *str, t_fmt *fmt);
void ft_set_type(char *str, t_datatype *type)
{
  (*str == '%') ? type->percent = 1 : 0;
  (*str == 's') ? type->s = 1 : 0;
  (*str == 'S') ? type->l_s = 1 : 0;
  (*str == 'p') ? type->p = 1 : 0;
  (*str == 'd') ? type->d = 1 : 0;
  (*str == 'D') ? type->l_d = 1 : 0;
  (*str == 'i') ? type->i = 1 : 0;
  (*str == 'o') ? type->o = 1 : 0;
  (*str == 'O') ? type->l_o = 1 : 0;
  (*str == 'u') ? type->u = 1 : 0;
  (*str == 'U') ? type->l_u = 1 : 0;
  (*str == 'x') ? type->x = 1 : 0;
  (*str == 'X') ? type->l_x = 1 : 0;
  (*str == 'c') ? type->c = 1 : 0;
  (*str == 'C') ? type->w_c = 1 : 0;
}
