#include "ft_printf.h"

void ft_reset_flags(t_flags *fl)
{
  fl->zero = 0;
  fl->space = 0;
  fl->plus = 0;
  fl->minus = 0;
  fl->hash = 0;
}

void ft_reset_width(t_width *w)
{
  w->l = 0;
}

void ft_reset_precision(t_precision *pre)
{
  pre->l = 0;
}

void ft_reset_length(t_length *len)
{
  len->hh = 0;
  len->h = 0;
  len->l = 0;
  len->ll = 0;
  len->j = 0;
  len->z = 0;
}

void ft_reset_type(t_datatype *type)
{
  type->percent = 0;
  type->s = 0;
  type->l_s = 0;
  type->p = 0;
  type->d = 0;
  type->l_d = 0;
  type->i = 0;
  type->o = 0;
  type->l_o = 0;
  type->u = 0;
  type->l_u = 0;
  type->x = 0;
  type->l_x = 0;
  type->c = 0;
  type->w_c = 0;
}
