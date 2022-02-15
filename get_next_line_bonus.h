/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:11:14 by poscenes          #+#    #+#             */
/*   Updated: 2021/12/08 17:11:42 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define FD_MAX 8192

size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
char		*get_str(int fd, char *line);
char		*get_line(char *str);
char		*get_remain(char *str);
int			check_endl(char *str);

#endif
