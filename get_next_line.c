/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:58:22 by romargar          #+#    #+#             */
/*   Updated: 2025/04/08 16:13:50 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		{
			free(file_content);
			return (-1);
		}
		if (bytes_read == 0)
			return (free(file_content), 0);
		file_content[bytes_read] = '\0';
		*remaining_part = ft_strjoin(*remaining_part, file_content);
		if (!*remaining_part)
			return (-1);
		if (find_newline(file_content) != -1)
			break ;
	}
	return (free(file_content), 1);
}

char	*get_next_line(int fd)
{
	static char	*remaining_part = NULL;
	char		*extracted_line;
	int			res;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!remaining_part)
	{
		remaining_part = ft_strdup("");
	}
	if (find_newline(remaining_part) == -1)
	{
		res = read_file(fd, &remaining_part);
		if (res == -1 || (res == 0 && remaining_part[0] == '\0'))
		{
			free(remaining_part);
			remaining_part = NULL;
			return (NULL);
		}
	}
	extracted_line = extract_line(remaining_part);
	remaining_part = get_remaining(remaining_part);
	return (extracted_line);
}

// int main()
// {
//   char *str;
// //   char *str1;

//   int fd = open("test.txt", O_RDONLY);
//   str = get_next_line(fd);
//   printf("%s", str);
//   free(str);
//   str = get_next_line(fd);
//   printf("%s", str);
//   free(str);
//   close(fd);
//   str = get_next_line(fd);
// printf("%s", str);

//   // while (str = get_next_line(fd))
//   // {
//   //   printf("%s", str);
//   // }

//   // get_next_line(fd);
//   // get_next_line(fd);
//   // str = get_next_line(fd);
//   // str1 = get_next_line(fd);

//   // printf("%s", str);
//   // printf("%s", str1);
//   // free(str);
//   // free(str1);
//   // system("leaks a.out");

// }
