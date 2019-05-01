/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:23:44 by cyfelbac          #+#    #+#             */
/*   Updated: 2017/11/17 12:23:46 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *p;
	t_list *p2;

	result = NULL;
	if (lst == NULL || (*f) == NULL)
		return (NULL);
	p2 = (*f)(lst);
	if ((result = ft_lstnew(p2->content, p2->content_size)) != NULL)
	{
		p = result;
		lst = lst->next;
		while (lst != NULL)
		{
			p2 = (*f)(lst);
			if (!(p->next = ft_lstnew(p2->content, p2->content_size)))
				return (NULL);
			p = p->next;
			lst = lst->next;
		}
	}
	return (result);
}
