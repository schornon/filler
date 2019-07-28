/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:27:33 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 16:28:55 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		save_position(t_f *f)
{
	f->res_v = f->t_res_v;
	f->pl_x = f->i;
	f->pl_y = f->r;
}

void		check_place(t_f *f, int fr, int fi)
{
	f->t_r = -1;
	f->pl_count = 0;
	f->t_res_v = 0;
	f->one_pi = 0;
	f->tmp_x = fi;
	while (++f->t_r < f->pi_y)
	{
		++fr;
		f->t_i = -1;
		fi = f->tmp_x;
		while (++f->t_i < f->pi_x)
		{
			++fi;
			if (f->pi[f->t_r][f->t_i] == '*' && (f->map[fr][fi] == '.' ||
				f->map[fr][fi] == f->pchr || f->map[fr][fi] == f->pchr - 32))
			{
				if (f->map[fr][fi] == f->pchr || f->map[fr][fi] == f->pchr - 32)
					f->one_pi++;
				f->pl_count++;
			}
			f->t_res_v += f->v_map[fr][fi];
		}
	}
	if (f->pi_cnt == f->pl_count && f->t_res_v < f->res_v && f->one_pi == 1)
		save_position(f);
}

void		place_finder(t_f *f)
{
	f->r = -1;
	while (++f->r < f->map_y - f->pi_y + 1)
	{
		f->i = -1;
		while (++f->i < f->map_x - f->pi_x + 1)
		{
			check_place(f, f->r - 1, f->i - 1);
		}
	}
}

void		algo(t_f *f)
{
	eval_val_map(f);
	place_finder(f);
	write(1, conv(f->pl_y, 10), ft_strlen(conv(f->pl_y, 10)));
	write(1, " ", 1);
	write(1, conv(f->pl_x, 10), ft_strlen(conv(f->pl_x, 10)));
	write(1, "\n", 1);
	piece_cleaner(f);
}
