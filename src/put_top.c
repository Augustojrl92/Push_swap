/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:34:27 by aurodrig          #+#    #+#             */
/*   Updated: 2024/08/11 19:27:07 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_top_a(t_list **lst, int index, char moves[], int j)
{
	int	size;
	int	i;

	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			j = ra(lst, moves, j);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			j = rra(lst, moves, j);
			i++;
		}
	}
	return (j);
}

int	ft_put_top_b(t_list **lst, int index, char moves[], int j)
{
	int	size;
	int	i;

	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			j = rb(lst, moves, j);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			j = rrb(lst, moves, j);
			i++;
		}
	}
	return (j);
}
