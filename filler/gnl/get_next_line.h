/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:56:26 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 16:20:42 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2
# define CHECKRESULT(x) if (x == -1) return (-1); if (x == 1) return (1);
# define DOUBLECH(x) if (!x) return (-1);
# define BYTESERROR(x) if (x == -1) return (-1);
# define CHK1(x, y) if (y == 0 && x != NULL) return (1);
# define CHECKSTAT(x) if (x == 1) return (1);
# define CHK2(x, y) if (y == 0 && x == NULL) return (0);
# define ZEROBYTES(x) if (x == 0) return (1);

int			get_next_line(const int fd, char **line);
char		*ft_strjoin_f(char *s1, char const *s2);
char		*ft_strdup_f(char *src);

#endif
