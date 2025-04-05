/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:56:59 by romargar          #+#    #+#             */
/*   Updated: 2025/04/05 19:58:28 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_file(int fd, char **remaining_part)
{
	char	*file_content;
	int		bytes_read;

	file_content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!file_content)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, file_content, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(file_content), -1);
		if (bytes_read == 0)
			break ;
		file_content[bytes_read] = '\0';
		*remaining_part = ft_strjoin(*remaining_part, file_content);
		if (!*remaining_part)
			return (-1);
		if (find_newline(file_content) != -1)
			break ;
	}
	free(file_content);
	if (bytes_read == 0)
		return (0);
	return (1);
}

char	*extract_line(char *str)
{
	int		index;
	char	*extracted_line;

	if (!str)
		return (NULL);
	index = find_newline(str);
	if (index == -1)
		index = ft_strlen(str);
	extracted_line = (char *)malloc(sizeof(char) * (index + (str[index] == '\n')
				+ 1));
	if (!extracted_line)
	{
		free(str);
		return (NULL);
	}
	ft_strncpy(extracted_line, str, index + (str[index] == '\n'));
	extracted_line[index + (str[index] == '\n')] = '\0';
	return (extracted_line);
}

char	*get_remaining(char *str)
{
	int		index;
	char	*remaining_part;
	int		remaining_length;

	if (!str)
		return (NULL);
	index = find_newline(str);
	if (index == -1)
	{
		free(str);
		return (NULL);
	}
	index++;
	remaining_length = ft_strlen(str) - index;
	remaining_part = (char *)malloc(sizeof(char) * (remaining_length + 1));
	if (!remaining_part)
		return (NULL);
	ft_strncpy(remaining_part, str + index, remaining_length);
	remaining_part[remaining_length] = '\0';
	free(str);
	return (remaining_part);
}

char	*get_next_line(int fd)
{
	static char	*remaining_part[OPEN_MAX] = {NULL};
	char		*extracted_line;
	int			res;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!remaining_part[fd])
	{
		remaining_part[fd] = ft_strdup("");
	}
	if (find_newline(remaining_part[fd]) == -1)
	{
		res = read_file(fd, &remaining_part[fd]);
		if (res == -1 || (res == 0 && remaining_part[fd][0] == '\0'))
		{
			free(remaining_part[fd]);
			remaining_part[fd] = NULL;
			return (NULL);
		}
	}
	extracted_line = extract_line(remaining_part[fd]);
	remaining_part[fd] = get_remaining(remaining_part[fd]);
	return (extracted_line);
}
