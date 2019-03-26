/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:34:55 by cpalmier          #+#    #+#             */
/*   Updated: 2018/01/10 17:36:02 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*before;

	before = *alst;
	if (alst && new)
	{
		new->next = NULL;
		while (before->next != NULL)
			before = before->next;
		before->next = new;
	}
}
