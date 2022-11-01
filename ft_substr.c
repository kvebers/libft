/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:46:06 by kvebers           #+#    #+#             */
/*   Updated: 2022/10/30 15:57:00 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	cnt;

	cnt = 0;
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub == NULL || s == NULL)
		return (NULL);
	if ((size_t)ft_strlen((char *)s) < start)
		return (sub);
	while (cnt < len)
	{
		*(sub + cnt) = *(s + cnt + start);
		cnt++;
	}
	return (sub);
}
