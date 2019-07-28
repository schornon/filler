/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:45:14 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 15:49:08 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		create_val_map(t_f *f)
{
	int t;
	int j;

	t = -1;
	f->v_map = (int**)malloc(sizeof(int*) * f->map_y);
	while (++t < f->map_y)
	{
		j = -1;
		f->v_map[t] = (int*)malloc(sizeof(int) * f->map_x);
		while (++j < f->map_x)
			f->v_map[t][j] = 0;
	}
	f->map_secur = 3;
}

char		*conv(unsigned int num, int base)
{
	static char	rep[] = "0123456789abcdef";
	char		*temp;
	static char	buffer[50];
	char		*ptr;

	temp = rep;
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
	{
		*--ptr = '0';
		return (ptr);
	}
	if (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	while (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	return (ptr);
}
