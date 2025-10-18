/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:34 by aurodrig          #+#    #+#             */
/*   Updated: 2024/08/11 19:53:07 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_execute_moves(t_stack *pair, t_list **stack_a, \
t_list **stack_b, char moves[])
{
	pair->i = ft_put_top_a(stack_a, pair->final_p, moves, pair->i);
	pair->i = ft_put_top_b(stack_b, pair->final_nb, moves, pair->i);
	pair->i = pa(stack_a, stack_b, moves, pair->i);
	return (pair->i);
}

void	ft_init_pair(t_stack *cost_pair, t_list **stack_a, \
t_list **stack_b, int i)

{
	cost_pair->i = i;
	cost_pair->temp = *stack_b;
	cost_pair->best = INT_MAX;
	cost_pair->index_nb = 0;
	cost_pair->size_b = ft_lstsize(*stack_b);
	cost_pair->size_a = ft_lstsize(*stack_a);
}

int	ft_find_best_cost(t_list **stack_a, t_list **stack_b, char moves[], int i)

{
	t_stack	pair;

	ft_init_pair(&pair, stack_a, stack_b, i);
	while (*stack_b)
	{
		pair.index_p = ft_find_optimalcost(stack_a, (*stack_b)->content);
		if (pair.index_p != -1)
		{
			pair.cost_p = ft_calculate_cost_up(pair.size_a, pair.index_p);
			pair.cost_nb = ft_calculate_cost_up(pair.size_b, pair.index_nb);
			if ((pair.cost_p + pair.cost_nb) < pair.best \
					&& (pair.cost_p + pair.cost_nb) >= 0)
			{
				pair.final_nb = pair.index_nb;
				pair.final_p = pair.index_p;
				pair.best = pair.cost_nb + pair.cost_p;
			}
		}
		(*stack_b) = (*stack_b)->next;
		pair.index_nb++;
	}
	*stack_b = pair.temp;
	i = ft_execute_moves(&pair, stack_a, stack_b, moves);
	return (i);
}

int	ft_cost_algorithm(t_list **stack_a, t_list **stack_b, char moves[], int i)
{
	int	average;

	average = ft_get_dynamic_average(*stack_a);
	while (ft_lstsize(*stack_a) > 5)
	{
		if ((*stack_a)->content > average)
			i = ra(stack_a, moves, i);
		else
		{
			i = pb(stack_a, stack_b, moves, i);
			average = ft_get_dynamic_average(*stack_a);
		}
	}
	i = ft_sort_five(stack_a, stack_b, moves, i);
	while (ft_lstsize(*stack_b) > 0)
	{
		i = ft_find_best_cost(stack_a, stack_b, moves, i);
	}
	i = ft_rotate_until_max_is_top(stack_a, moves, i);
	return (i);
}
