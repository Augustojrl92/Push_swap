/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_buddy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:15:10 by aurodrig          #+#    #+#             */
/*   Updated: 2024/08/11 19:38:45 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate_cost_up(int size, int index)
{
	int	counter;

	counter = 0;
	if (index <= (size / 2))
	{
		counter = index;
	}
	else if (index > (size / 2))
		counter = size - index;
	return (counter);
}

int	ft_find_optimalcost(t_list **stack_a, long long nb)
{
	long int	best_pair;
	long int	counter;
	long int	tmp;
	t_list		*temp;

	counter = __LONG_LONG_MAX__;
	best_pair = __LONG_LONG_MAX__;
	temp = *stack_a;
	while (*stack_a)
	{
		tmp = (*stack_a)->content - nb;
		if ((tmp < counter) && ((*stack_a)->content > nb))
		{
			counter = tmp;
			best_pair = (*stack_a)->content;
		}
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = temp;
	if (best_pair == __LONG_LONG_MAX__)
		return (-1);
	return (ft_get_index(best_pair, *stack_a));
}
