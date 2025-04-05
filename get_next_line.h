/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:58:27 by romargar          #+#    #+#             */
/*   Updated: 2025/04/05 17:02:03 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		find_newline(char *str);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str, int c);
char	*ft_strncpy(char *dest, char *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*extract_line(char *str);
char	*get_remaining(char *str);
char	*ft_strdup(const char *s);

#endif