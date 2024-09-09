/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:52:27 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:24:55 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	sl_lstadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*tmp;

	tmp = NULL;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = sl_lstlast(*lst);
	if (!tmp)
		*lst = new;
	tmp->next = new;
}

t_enemy	*sl_lstlast(t_enemy *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
