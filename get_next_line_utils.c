/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:58:11 by romargar          #+#    #+#             */
/*   Updated: 2025/04/05 17:01:41 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *str)
{
	int	i;

	if (!str)
	{
		return (-1);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
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

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_string;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (NULL);
	new_string = (char *)malloc(sizeof(char) * (ft_strlen(str1)
				+ ft_strlen(str2) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		new_string[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		new_string[i++] = str2[j++];
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new_str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// int main()
// {
//   char str[] = "gass kajx saj jx aoi";
//   char *string;

//   string = ft_strdup(str);
//   printf("%s", string);

//   return (0);
// }