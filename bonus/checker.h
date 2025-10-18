/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:34 by aurodrig          #+#    #+#             */
/*   Updated: 2024/08/11 19:16:27 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../src/push_swap.h"
# include "../Get_Next_Line/get_next_line.h"

int		main(int argc, char **argv);
void	ft_push(t_list **stack_get, t_list **stack_give);
void	ft_swap(t_list *stack);
void	ft_rotate(t_list **stack);
void	ft_swap(t_list *stack);
void	ft_reverse_rotate(t_list **stack);
void	checker_moves(t_list **stack_a, t_list **stack_b, char *move);

#endif