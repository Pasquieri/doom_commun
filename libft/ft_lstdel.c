/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:44:07 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/21 19:02:59 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	if (alst)
	{
		while (tmp)
		{
			del(tmp->content, tmp->content_size);
			next = tmp->next;
			tmp->next = NULL;
			free(tmp);
			tmp = next;
		}
	}
	*alst = NULL;
}
