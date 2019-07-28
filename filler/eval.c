/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:41:57 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 16:07:45 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		eval_player_plc(t_f *f)
{
	f->r = -1;
	while (++f->r < f->map_y)
	{
		f->i = -1;
		while (++f->i < f->map_x)
		{
			if (f->map[f->r][f->i] == f->pchr ||
				f->map[f->r][f->i] == f->pchr - 32)
			{
				f->v_map[f->r][f->i] = -1;
			}
		}
	}
}

void		eval_val_map_sec2(t_f *f, int val)
{
	if (f->i + 1 < f->map_x)
		f->v_map[f->r][f->i + 1] == 0 ?
	(f->v_map[f->r][f->i + 1] = val + 1) : 0;
	if (f->r - 1 >= 0 && f->i - 1 >= 0)
		f->v_map[f->r - 1][f->i - 1] == 0 ?
	(f->v_map[f->r - 1][f->i - 1] = val + 1) : 0;
	if (f->r + 1 < f->map_y && f->i - 1 >= 0)
		f->v_map[f->r + 1][f->i - 1] == 0 ?
	(f->v_map[f->r + 1][f->i - 1] = val + 1) : 0;
	if (f->r - 1 >= 0 && f->i + 1 < f->map_x)
		f->v_map[f->r - 1][f->i + 1] == 0 ?
	(f->v_map[f->r - 1][f->i + 1] = val + 1) : 0;
	if (f->r - 1 > 0 && f->i - 1 > 0)
		f->v_map[f->r + 1][f->i + 1] == 0 ?
	(f->v_map[f->r + 1][f->i + 1] = val + 1) : 0;
}

void		eval_val_map_sec(t_f *f, int val)
{
	f->r = -1;
	while (++f->r < f->map_y - 1)
	{
		f->i = -1;
		while (++f->i < f->map_x - 1)
		{
			if (f->v_map[f->r][f->i] == val &&
				f->r < f->map_y && f->i < f->map_x)
			{
				if (f->r - 1 >= 0)
					f->v_map[f->r - 1][f->i] == 0 ?
				(f->v_map[f->r - 1][f->i] = val + 1) : 0;
				if (f->r + 1 < f->map_y)
					f->v_map[f->r + 1][f->i] == 0 ?
				(f->v_map[f->r + 1][f->i] = val + 1) : 0;
				if (f->i - 1 >= 0)
					f->v_map[f->r][f->i - 1] == 0 ?
				(f->v_map[f->r][f->i - 1] = val + 1) : 0;
				eval_val_map_sec2(f, val);
			}
		}
	}
	if (val + 1 < f->map_x || val + 1 < f->map_y)
		return (eval_val_map_sec(f, val + 1));
}

void		eval_val_map2(t_f *f)
{
	if (f->i - 1 >= 0)
		f->map[f->r][f->i - 1] == '.' ?
	(f->v_map[f->r][f->i - 1] = 1) : 0;
	if (f->i + 1 < f->map_x)
		f->map[f->r][f->i + 1] == '.' ?
	(f->v_map[f->r][f->i + 1] = 1) : 0;
	if (f->r - 1 >= 0 && f->i - 1 >= 0)
		f->map[f->r - 1][f->i - 1] == '.' ?
	(f->v_map[f->r - 1][f->i - 1] = 1) : 0;
	if (f->r + 1 < f->map_y && f->i - 1 >= 0)
		f->map[f->r + 1][f->i - 1] == '.' ?
	(f->v_map[f->r + 1][f->i - 1] = 1) : 0;
	if (f->r - 1 >= 0 && f->i + 1 < f->map_x)
		f->map[f->r - 1][f->i + 1] == '.' ?
	(f->v_map[f->r - 1][f->i + 1] = 1) : 0;
	if (f->r - 1 > 0 && f->i - 1 > 0)
		f->map[f->r + 1][f->i + 1] == '.' ?
	(f->v_map[f->r + 1][f->i + 1] = 1) : 0;
	f->v_map[f->r][f->i] = -2;
}

void		eval_val_map(t_f *f)
{
	f->map_secur == 2 ? create_val_map(f) : 0;
	f->r = -1;
	while (++f->r < f->map_y - 1)
	{
		f->i = -1;
		while (++f->i < f->map_x - 1)
		{
			if (f->map[f->r][f->i] == f->enemy ||
				f->map[f->r][f->i] == f->enemy - 32)
			{
				if (f->r - 1 >= 0)
					f->map[f->r - 1][f->i] == '.' ?
				(f->v_map[f->r - 1][f->i] = 1) : 0;
				if (f->r + 1 < f->map_y)
					f->map[f->r + 1][f->i] == '.' ?
				(f->v_map[f->r + 1][f->i] = 1) : 0;
				eval_val_map2(f);
			}
		}
	}
	eval_val_map_sec(f, 1);
	eval_player_plc(f);
}
