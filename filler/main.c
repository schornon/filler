/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:59:39 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 18:19:31 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		line_control(t_f *f)
{
	if (ft_strncmp(f->line, "$$$", 3) == 0)
		return (1);
	if (ft_strncmp(f->line, "Plateau", 7) == 0)
		return (2);
	if (ft_strncmp(f->line, "    ", 4) == 0)
		return (3);
	if (ft_strncmp(f->line, "000", 3) == 0)
		return (4);
	if (ft_strncmp(f->line, "Piece", 5) == 0)
		return (5);
	return (0);
}

void	f_to_0(t_f *f)
{
	f->i = 0;
	f->r = -1;
	f->lc = 0;
	f->dx = 0;
	f->dy = 0;
	f->pi_cnt = 0;
	f->res_v = 2000000000;
	f->tmp_x = 0;
	f->tmp_y = 0;
	f->pl_x = 0;
	f->pl_y = 0;
}

int		main(void)
{
	t_f *f;

	f = ft_lstnewf();
	f->map_secur = 0;
	f->global_fd = 0;
	while (1)
	{
		if (get_next_line(f->global_fd, &f->line) < 1)
			break ;
		f->lc = line_control(f);
		f->lc == 1 ? check_player(f) : 0;
		f->lc == 2 ? check_map_size(f) : 0;
		f->lc == 3 ? read_map(f) : 0;
		f->lc == 5 ? check_peace(f) : 0;
		if (f->lc == 5)
		{
			free(f->line);
			algo(f);
			f_to_0(f);
		}
		else
			free(f->line);
	}
	cleaner(f);
	return (0);
}
