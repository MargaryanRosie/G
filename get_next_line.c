/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:58:22 by romargar          #+#    #+#             */
/*   Updated: 2025/04/05 17:01:51 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char **remaining_part)
{
	char	*file_content;
	int		bytes_read;
	char	*temp;

	file_content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!file_content)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, file_content, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(file_content);
			return (-1);
		}
		if (bytes_read == 0)
			break ;
		file_content[bytes_read] = '\0';
		temp = ft_strjoin(*remaining_part, file_content);
		if (!temp)
		{
			free(*remaining_part);
			*remaining_part = NULL;
			return (-1);
		}
		free(*remaining_part);
		*remaining_part = temp;
		if (find_newline(file_content) != -1)
			break ;
	}
	free(file_content);
	if (bytes_read == 0)
		return (0);
	return (1);
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