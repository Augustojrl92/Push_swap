/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:21:34 by aurodrig          #+#    #+#             */
/*   Updated: 2024/08/12 16:14:48 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_list **stack_get, t_list **stack_give)
{
	t_list	*temp;

	if (!(*stack_give))
		return ;
	temp = (*stack_give)->next;
	(*stack_give)->next = *stack_get;
	*stack_get = *stack_give;
	*stack_give = temp;
}

int	pa(t_list **stack_a, t_list **stack_b, char moves[], int i)
{
	ft_push(stack_a, stack_b);
	moves[i] = '4';
	i++;
	return (i);
}

int	pb(t_list **stack_a, t_list **stack_b, char moves[], int i)
{
	ft_push(stack_b, stack_a);
	moves[i] = '5';
	i++;
	return (i);
}
