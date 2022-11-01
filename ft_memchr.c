/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:23:53 by kvebers           #+#    #+#             */
/*   Updated: 2022/10/20 16:16:25 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	counter;
	char	*ptr;

	ptr = (char *)s;
	counter = 0;
	while (*(ptr + counter) != '\0' && counter < n)
	{
		if (*(ptr + counter) == c)
			return (ptr + counter);
		counter++;
	}
	if (*(ptr + counter) == c)
		return (ptr + counter);
	return (NULL);
}
