/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cntrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:51:14 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 15:53:20 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_f			*ft_lstnewf(void)
{
	t_f *new;

	if (!(new = (t_f*)malloc(sizeof(t_f))))
		return (NULL);
	new->i = 0;
	new->r = -1;
	new->lc = 0;
	new->dx = 0;
	new->dy = 0;
	new->pi_cnt = 0;
	new->res_v = 2000000000;
	new->tmp_x = 0;
	new->tmp_y = 0;
	new->pl_x = 0;
	new->pl_y = 0;
	return (new);
}

void		cleaner(t_f *f)
{
	int i;

	i = -1;
	while (f->map_y > ++i)
		free(f->map[i]);
	free(f->map);
	i = -1;
	while (f->map_y > ++i)
		free(f->v_map[i]);
	free(f->v_map);
	free(f->line);
	free(f);
}
