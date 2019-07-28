/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:28:58 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 15:51:01 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(t_f *f)
{
	f->r = -1;
	free(f->line);
	while (f->r < f->pi_y - 1)
	{
		get_next_line(f->global_fd, &f->line);
		f->i = 0;
		f->j = -1;
		f->r++;
		while (f->line[f->i] == '.' || f->line[f->i] == '*' ||
			(f->line[f->i] != '\n' && f->line[f->i] != '\0'))
			f->pi[f->r][++f->j] = f->line[f->i++];
		f->r < f->pi_y - 1 ? free(f->line) : 0;
	}
	piece_cnt(f);
}

void	create_piece(t_f *f)
{
	int t;

	t = -1;
	f->pi = (char**)malloc(sizeof(char*) * f->pi_y);
	while (++t < f->pi_y)
	{
		f->pi[t] = (char*)malloc(sizeof(char) * f->pi_x + 1);
		f->pi[t][f->pi_x] = '\0';
	}
}

void	piece_cleaner(t_f *f)
{
	int i;

	i = -1;
	while (f->pi_y > ++i)
		free(f->pi[i]);
	free(f->pi);
}

void	check_peace(t_f *f)
{
	char tmp[50];

	f->i = 0;
	f->j = -1;
	while (!(f->line[f->i] >= '0' && f->line[f->i] <= '9'))
		f->i++;
	while (f->line[f->i] >= '0' && f->line[f->i] <= '9')
		tmp[++f->j] = f->line[f->i++];
	tmp[++f->j] = '\0';
	f->pi_y = ft_atoi(tmp);
	f->i++;
	f->j = -1;
	while (f->line[f->i] <= '0' && f->line[f->i] >= '9')
		f->i++;
	while (f->line[f->i] >= '0' && f->line[f->i] <= '9')
		tmp[++f->j] = f->line[f->i++];
	tmp[++f->j] = '\0';
	f->pi_x = ft_atoi(tmp);
	create_piece(f);
	read_piece(f);
}
