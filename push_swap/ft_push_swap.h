/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:01:24 by mwikiera          #+#    #+#             */
/*   Updated: 2024/04/25 12:01:24 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdio.h> // dont forget to remove

int	main(int argc, char *argv[]);
int	push_swap(int argc, char *argv[]);
void	func_display(int argc, char *argv[], int stack_a);

void	swap_a(char **argv[], int stack_a);
void	swap_b(char **argv[], int stack_a, int argc);
void	ss(char **argv[], int stack_a, int argc);
void	push_a(char **argv[], int *stack_a);
void	push_b(char **argv[], int *stack_a);
void	rotate_a(char **argv[], int stack_a);
void	rotate_b(int argc, char **argv[], int stack_a);
void	rr(char **argv[], int stack_a, int argc);
void	reverse_rotate_a(char **argv[], int stack_a);
void	reverse_rotate_b(int argc, char **argv[], int stack_a);
void	rrr(char **argv[], int stack_a, int argc);

int	checker(int argc, char *argv[]);
void	ft_sort_3_a(char *argv[], int stack_a);
void	ft_sort(char *argv[], int argc, int *stack_a);
int path1(char *argv[], int argc, int stack_a);
int path2(char *argv[], int argc, int stack_a);
int path3(char *argv[], int argc, int stack_a);

int	moves_up(char *argv[], int argc, int stack_a, int n);
int	moves_down(char *argv[], int argc, int stack_a, int n);
void	sorta1(char *argv[], int argc, int *stack_a);

#endif