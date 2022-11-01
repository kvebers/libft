/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:21:09 by kvebers           #+#    #+#             */
/*   Updated: 2022/11/01 10:36:58 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_yeet_blanks(char const *s, char c, int start_pos, int len)
{
	while (*(s + start_pos) == c && start_pos != len)
		start_pos++;
	return (start_pos);
}

int	ft_getpos(char const *s, char c, int start_pos, int len)
{
	while (*(s + start_pos) != c && start_pos < len)
		start_pos++;
	return (start_pos);
}

int	ft_get_words(char const *s, char c, int start_pos, int len)
{
	int	words;
	int	temp;

	words = 0;
	while (start_pos != len)
	{
		start_pos = ft_yeet_blanks(s, c, start_pos, len);
		temp = start_pos;
		start_pos = ft_getpos(s, c, start_pos, len);
		if (start_pos == temp)
			return (words);
		words++;
	}
	return (words);
}

char	*ft_create_word(const char *s, int pos_x, int pos_y)
{
	char	*word;
	int		cnt;

	cnt = 0;
	word = ft_calloc((pos_y - pos_x + 1), sizeof(char));
	if (word == NULL)
		return (NULL);
	while (pos_x < pos_y)
	{
		*(word + cnt) = *(s + pos_x);
		pos_x++;
		cnt++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		pos_x;
	int		pos_y;
	int		cnt;
	char	**dest;

	if (s == NULL)
		return (NULL);
	words = ft_get_words(s, c, 0, ft_strlen((char *)s));
	dest = malloc(((words + 1) * sizeof(char *)));
	if (dest == NULL)
		return (NULL);
	cnt = 0;
	pos_y = 0;
	while (cnt < words)
	{
		pos_x = ft_yeet_blanks(s, c, pos_y, ft_strlen((char *)s));
		pos_y = ft_getpos(s, c, pos_x, ft_strlen((char *)s));
		*(dest + cnt) = ft_create_word(s, pos_x, pos_y);
		cnt++;
	}
	*(dest + cnt) = NULL;
	return (dest);
}
