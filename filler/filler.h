/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:57:03 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 16:29:41 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_f
{
	char		*line;
	int			i;
	int			j;
	int			r;
	int			lc;
	char		pchr;
	char		enemy;
	int			map_x;
	int			map_y;
	char		**map;
	int			**v_map;
	int			res_v;
	int			tmp_x;
	int			tmp_y;
	int			pl_x;
	int			pl_y;
	int			pi_x;
	int			pi_y;
	char		**pi;
	int			pi_cnt;
	int			map_secur;
	int			dx;
	int			dy;
	int			t_r;
	int			t_i;
	int			pl_count;
	int			t_res_v;
	int			one_pi;
	int			global_fd;
}				t_f;

t_f				*ft_lstnewf(void);
void			cleaner(t_f *f);
void			check_player(t_f *f);
void			create_map(t_f *f);
void			read_map(t_f *f);
void			check_map_size(t_f *f);
void			create_piece(t_f *f);
void			read_piece(t_f *f);
void			check_peace(t_f *f);
void			piece_cnt(t_f *f);
void			find_dxy(t_f *f);
void			eval_val_map_sec(t_f *f, int val);
void			eval_val_map2(t_f *f);
void			piece_cleaner(t_f *f);
void			eval_val_map(t_f *f);
void			algo(t_f *f);
void			create_val_map(t_f *f);
char			*ft_strjoin_f(char *s1, char const *s2);
char			*ft_jchar_f_i(char *s, char chr, int j);
char			*ft_jchar_f(char *s, char chr);
char			*ft_jchar_f_w(char *s, char chr);
char			*ft_strdup_f(char *src);
char			*conv(unsigned int num, int base);

#endif
