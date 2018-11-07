#include "ft_printf.h"

/*
STUFF WE NEEEDS:
flags + - 0 ' '
- + puts a + before positive nbrs
- ' ' puts a space before positive nbrs (ingnored with +)

- 0 fills the min width with 0;
- left align the nbrs into the width;

length conversions
-l long
-ll long long
-j __int_max_t
-z size_t

precision
- overrides witdh
- if more chars need to be printed they are 0s before the nbr;
- 0 flag is ignored with precision -> set 0 flag to zero?



*/
//
// int ft_has_len_flag(t_fmt *fmt)
// {
//   if (fmt->l.l || fmt->l.ll || fmt->l.j || fmt->l.z)
//   {
//     (fmt->l.l) ? (ft_d_l(fmt, ap)) : 0;
//     (fmt->l.ll) ? (ft_d_ll(fmt, ap)) : 0;
//     (fmt->l.j) ? (ft_d_j(fmt, ap)) : 0;
//     (fmt->l.z) ? (ft_d_z(fmt, ap)) : 0;
//     return (1);
//   }
//   return (0);
// }


char *ft_add_plus(char *buff, int *size, int neg)
{
  char *res;
  if (neg)
      return (buff);
  res = malloc(*size+1);
  res[*size] = 0;
  res[0] = '+';
  res = ft_strcpy(++res, buff);
  *size += 1;
  return (--res);
}

char *ft_add_space( char *buff, int size, int neg)
{
  char *res;
  if (neg)
      return (buff);
  res = malloc(size+1);
  res[size] = 0;
  res[0] = ' ';
  res = ft_strcpy(++res, buff);
  return (--res);
}

char *ft_add_zeros(char *buff, int pre, int size, int neg, char p)
{
  char *res;
  (neg || p) ? pre++ : 0;
  res = malloc(pre+1);
  res[pre--] = 0;
  while (pre >= 0)
  {
    if (size-2 >= 0 && buff[size-2] != '-' && buff[size-2] != '+')
      res[pre] = buff[size-2];
    else
      res[pre] = '0';
    pre--;
    size--;
  }
  (neg) ? res[0] = '-': 0;
  (p && !neg) ? res[0] = '+': 0;
  return (res);
}

char *ft_put_buff_into_width(t_fmt *fmt, char *buff)
{
  int len;
  char prefix;
  char *width;
  int offset;

  offset = 0;
  (buff[0] == '-' || buff[0] == '+') ? (prefix = buff[0]): (prefix = 0);
  len = ft_strlen(buff);
  if (len >= fmt->w.l)
    return (buff);
  width = malloc(fmt->w.l+1);
  (fmt->flags.zero) ? (memset(width,'0', fmt->w.l)) : (memset(width, ' ', fmt->w.l));
  (prefix && fmt->flags.zero) ? (width[0] = prefix, buff++, len--): 0;
  (fmt->flags.minus) ? 0 :(offset += fmt->w.l - len);
  ft_memcpy((width+offset), buff, len);
  if (fmt->flags.space && width[0] != '-')
    width[0] = ' ';
  return (width);
}

char *ft_d_buff(t_fmt *fmt, char *buff, int *size, int neg)
{
  if (fmt->flags.plus)
    buff = ft_add_plus(buff, size, neg);
  if (*size-1 > fmt->pre.l) // size includes the '\0' byte
      return(buff);
  buff = ft_add_zeros(buff, fmt->pre.l, *size, neg, fmt->flags.plus);
  fmt->flags.zero = 0;
  return (buff);
}
/*
char o;
char l_o;
char u;
char l_u;
char x;
char l_x;
*/
void ft_d(t_fmt *fmt, va_list *ap)
{
  int size[1];
  int negative[1];
  char *buff;
  long long d = 0;
  (fmt->l.j || fmt->l.z) ? fmt->l.ll = 1: 0;
//  (fmt->type.o || fmt->type.l_o || fmt->type.u || fmt->type.l_u) ? fmt->l.ll = 1: 0;
  (fmt->l.l) ? (d = va_arg(*ap, long)) : 0;
  (fmt->l.ll) ? (d = va_arg(*ap, long long)) : 0;
  (!fmt->l.l && ! fmt->l.ll) ? (d = va_arg(*ap, int)) : 0;
  buff = ft_itoa_2(d , size , negative);

  buff = ft_d_buff(fmt, buff, size, *negative);
  buff = ft_put_buff_into_width(fmt, buff);
  ft_putstr(buff);
}
