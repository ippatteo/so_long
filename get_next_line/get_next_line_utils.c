/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:47:13 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/13 17:12:06 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *source, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(source);
	if (n > 0)
	{
		while (source[i] && i < (n - 1))
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s, char *b)
{
	int		i;
	int		t;
	char	*str;

	i = -1;
	t = 0;
	if (!s)
	{
		s = (char *) malloc(sizeof(char));
		s[0] = '\0';
	}
	str = malloc(ft_strlen(s) + ft_strlen(b) + 1);
	if (!str)
		return (NULL);
	while (s[++i])
		str[i] = s[i];
	while (b[t])
		str[i++] = b[t++];
	str[i] = '\0';
	free (s);
	return (str);
}


