/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:01:04 by aurodrig          #+#    #+#             */
/*   Updated: 2024/08/12 16:16:11 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_list *stack)
{
	int	temp;

	if (!(stack) || !(stack->next))
		return ;
	temp = (stack->content);
	stack->content = stack->next->content;
	stack->next->content = temp;
}

int	sa(t_list *stack_a, char moves[], int i)
{
	ft_swap(stack_a);
	moves[i] = '1';
	i++;
	return (i);
}

int	sb(t_list *stack_b, char moves[], int i)
{
	ft_swap(stack_b);
	moves[i] = '2';
	i++;
	return (i);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
