/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:37:10 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:52:41 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

int		ft_arr_len(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	free_double_tab(char **tab)
{
	int i;
	int size;

	i = 0;
	size = ft_arr_len(tab);
	while (i < size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}

char	*ft_strjoin_free(char *s1, char *s2, int to_free)
{
	char *new;

	new = NULL;
	new = ft_strjoin(s1, s2);
	if (to_free == 1)
		free(s1);
	else if (to_free == 2)
	{
		free(s1);
		free(s2);
	}
	if (new)
		return (new);
	return (NULL);
}

int		str_is_digit(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (FALSE);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
