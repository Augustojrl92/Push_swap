/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:09:30 by dsa-mora          #+#    #+#             */
/*   Updated: 2024/08/11 19:30:02 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_get_max(t_list *lst)
{
	int	i;
	int	max;

	if (!lst)
		return (-1);
	i = 0;
	max = lst->content;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	ft_get_min(t_list *lst)
{
	int	i;
	int	min;

	if (!lst)
		return (-1);
	i = 0;
	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

int	ft_get_index(int nb, t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == nb)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
