#include "ft_printf.h"

void ft_p(t_fmt *fmt, va_list *ap)
{
  int size[1];
  int negative[1];
  char *buff;
  size_t d = va_arg(*ap, size_t);

  buff = ft_itoa_16(d , size , negative);
  buff = ft_d_buff(fmt, buff, size, *negative);
  buff = ft_put_buff_into_width(fmt, buff);
  ft_putstr(buff);
}

void ft_to_upper(char *s)
{
  while (*s)
  {
    if (*s >= 'a' && *s <= 'z')
      *s -= 32;
    s++;
  }
}

void ft_x(t_fmt *fmt, va_list *ap)
{
  int size[1];
  int negative[1];
  char *buff;
  size_t d = va_arg(*ap, size_t);

  buff = ft_itoa_16(d , size , negative);
  (fmt->type.l_x) ? (ft_to_upper(buff)):0;
  (fmt->flags.hash) ? 0: (buff+= 2);
  buff = ft_d_buff(fmt, buff, size, *negative);
  buff = ft_put_buff_into_width(fmt, buff);
  ft_putstr(buff);
}
void ft_o(t_fmt *fmt, va_list *ap)
{
  int size[1];
  int negative[1];
  char *buff;
  size_t d = va_arg(*ap, size_t);

  buff = ft_itoa_8(d , size , negative);
  (fmt->flags.hash) ? 0: (buff+= 2);
  buff = ft_d_buff(fmt, buff, size, *negative);
  buff = ft_put_buff_into_width(fmt, buff);
  ft_putstr(buff);
}
