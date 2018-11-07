#include "ft_printf.h"

// void ft_ls(t_fmt *fmt, va_list *ap)
// {
//
// }

/* Stuff we need:

  From the flags:
  -only the '-' minus flags

  the width (the minimum chars prited for that arg);
  the precision (the maximum chars printed from the arg);
  length: is there a l present!

*/

char *ft_fill_buff(char *s, int s_len, int len, int left)
{
    int offset;
    char *buff;

    offset = 0;
    buff = malloc(len + 1);
    buff[len] = 0;
    memset(buff, ' ', len);
    if (!left)
      offset = len - s_len;
    ft_strncpy((buff + offset), s, s_len);
    return buff;
}

void ft_s(t_fmt *fmt, va_list *ap)
{
  char *s;
  int s_len;
  int i;
  char *buff;

  //(fmt->l.l) ? ft_ls(fmt, ap): 0;
  s = va_arg(*ap, char *);
  (fmt->pre.l) ? (s_len = fmt->pre.l) : (s_len = ft_strlen(s));
  (s_len > (int)ft_strlen(s)) ? (s_len = (int)ft_strlen(s)): 0;
  buff = 0;
  if (fmt->w.l > s_len)
  {
      buff = ft_fill_buff(s, s_len, fmt->w.l, fmt->flags.minus);
      while (*buff)
        write(1,buff++,1);
  }
  else
  {
        i = 0;
        while (i < s_len)
          write(1,&s[i++],1);
  }
}
