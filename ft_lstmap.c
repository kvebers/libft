/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:31:21 by kvebers           #+#    #+#             */
/*   Updated: 2022/11/01 19:15:21 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*out;

	if (f == NULL || del == NULL)
		return (lst);
	out = NULL;
	while ((lst != NULL))
	{
		ptr = ft_lstnew((f)(lst->content));
		if (ptr == NULL)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&out, ptr);
		free (ptr);
		lst = lst -> next;
	}
	return (out);
}
