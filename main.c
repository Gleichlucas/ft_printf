#include "ft_printf.h"

void ft_reset_fmt(t_fmt *fmt)
{
  ft_reset_flags(&fmt->flags);
  ft_reset_width(&fmt->w);
  ft_reset_precision(&fmt->pre);
  ft_reset_length(&fmt->l);
  ft_reset_type(&fmt->type);
}

char *ft_set_fmt(char *str, t_fmt *fmt, va_list *ap)
{
  ft_reset_fmt(fmt);
  str = ft_set_flags(str, &fmt->flags);
  str = ft_set_width(str, &fmt->w, ap);
  str = ft_set_precision(str, &fmt->pre, ap);
  str = ft_set_length(str, &fmt->l);
  //ft_check_for_bad_format(fmt);
  ft_set_type(str, &fmt->type);
  (fmt->type.percent) ? ft_percent(): 0;
  (fmt->type.s) ? ft_s(fmt, ap): 0;
  // (fmt->type.l_s) ? ft_ls(fmt, ap): 0; // wide chars
  (fmt->type.p) ? ft_p(fmt, ap): 0; // hex
  (fmt->type.d) ? ft_d(fmt, ap): 0;
  (fmt->type.l_d) ? ft_d(fmt, ap): 0;
  (fmt->type.i) ? ft_d(fmt, ap): 0;
  (fmt->type.o) ? ft_o(fmt, ap): 0; // octal
  (fmt->type.l_o) ? ft_o(fmt, ap): 0; // octal
  (fmt->type.u) ? ft_d(fmt, ap): 0;
  (fmt->type.l_u) ? ft_d(fmt, ap): 0;
  (fmt->type.x) ? ft_x(fmt, ap): 0; // hex
  (fmt->type.l_x) ? ft_x(fmt, ap): 0;
  (fmt->type.c) ? ft_putchar(va_arg(*ap, int)): 0; // need ft_ for width and flags!
  // (fmt->type.w_c) ? ft_w_c(fmt, ap): 0; // wide char
  return (str);
}

void ft_printf(char *str, ...)
{
  va_list ap;
  t_fmt fmt;
  va_start(ap, str);
  while(*str)
  {
    if (*str == '%')
      str = ft_set_fmt(++str, &fmt, &ap);
    else
      write(1,str, 1);
    str++;
  }
  va_end(ap);
}

int main(void)
{

  char *buff = "abcpandaaufdembaumnospace";
  ft_printf("%^^!~~ą, ć, or ęs\n", buff);
  //printf("%+132s\n", buff);

  return (0);
}
