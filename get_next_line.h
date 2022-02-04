/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:02:44 by lseiller          #+#    #+#             */
/*   Updated: 2022/02/01 11:32:58 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*fill_no_nl(char *buffer);
char	*fill_nl(char *buffer);
char	*fill_join(char *line, char *buffer, int fd, int read_value);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	ft_strrcpy(char *dst, char *src, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strmcpy(char *dst, char *src, size_t size);

#endif
