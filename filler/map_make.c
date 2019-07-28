/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:28:53 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 15:50:23 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_player(t_f *f)
{
	if (f->line[0] == '$')
	{
		if (ft_strncmp(f->line, "$$$ exec p1", 11) == 0)
			f->pchr = 'o';
		if (ft_strncmp(f->line, "$$$ exec p2", 11) == 0)
			f->pchr = 'x';
	}
	if (f->pchr == 'o')
		f->enemy = 'x';
	if (f->pchr == 'x')
		f->enemy = 'o';
}

void	piece_cnt(t_f *f)
{
	f->r = -1;
	f->pi_cnt = 0;
	while (++f->r < f->pi_y)
	{
		f->i = -1;
		while (++f->i < f->pi_x)
			if (f->pi[f->r][f->i] == '*')
				f->pi_cnt++;
	}
}

void	create_map(t_f *f)
{
	int t;

	t = -1;
	f->map = (char**)malloc(sizeof(char*) * f->map_y);
	while (++t < f->map_y)
	{
		f->map[t] = (char*)malloc(sizeof(char) * f->map_x + 1);
		f->map[t][f->map_x] = '\0';
	}
	f->map_secur = 2;
}

void	read_map(t_f *f)
{
	free(f->line);
	f->line = NULL;
	f->r = 0;
	while (f->r < f->map_y)
	{
		get_next_line(f->global_fd, &f->line);
		f->i = 0;
		f->j = 0;
		while ((f->line[f->i] >= '0' && f->line[f->i] <= '9') ||
			f->line[f->i] == ' ')
			f->i += 1;
		ft_strcpy(f->map[f->r], &f->line[f->i]);
		f->r < f->map_y - 1 ? free(f->line) : 0;
		f->r += 1;
	}
}

void	check_map_size(t_f *f)
{
	char tmp[50];

	f->i = 0;
	f->j = -1;
	if (ft_strncmp(f->line, "Plateau", 7) == 0)
	{
		f->map_secur == 0 ? f->map_secur = 1 : 0;
		while (!(f->line[f->i] >= '0' && f->line[f->i] <= '9'))
			f->i++;
		while (f->line[f->i] >= '0' && f->line[f->i] <= '9')
			tmp[++f->j] = f->line[f->i++];
		tmp[++f->j] = '\0';
		f->map_y = ft_atoi(tmp);
		f->i++;
		f->j = -1;
		while (f->line[f->i] <= '0' && f->line[f->i] >= '9')
			f->i++;
		while (f->line[f->i] >= '0' && f->line[f->i] <= '9')
			tmp[++f->j] = f->line[f->i++];
		tmp[++f->j] = '\0';
		f->map_x = ft_atoi(tmp);
	}
	if (f->map_secur == 1)
		create_map(f);
}
