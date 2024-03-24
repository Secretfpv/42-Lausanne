/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:57:18 by mwikiera          #+#    #+#             */
/*   Updated: 2024/03/19 20:57:18 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_a(char **argv[], int stack_a)
{
	char *temp;

	ft_printf("sa\n");
	if (stack_a >= 2)
	{
		temp = (*argv)[1];
		(*argv)[1] = (*argv)[2];
		(*argv)[2] = temp;
	}
}

void	swap_b(char **argv[], int stack_a, int argc)
{
	char *temp;

	ft_printf("sb\n");
	if ((argc - 1) - stack_a >= 2)
	{
		temp = (*argv)[stack_a + 1];
		(*argv)[stack_a + 1] = (*argv)[stack_a + 2];
		(*argv)[stack_a + 2] = temp;
	}
}

void	ss(char **argv[], int stack_a, int argc)
{
	char *temp1;
	char *temp2;

	ft_printf("ss\n");
	if (stack_a >= 2)
	{
		temp1 = (*argv)[1];
		(*argv)[1] = (*argv)[2];
		(*argv)[2] = temp1;
	}
	if ((argc - 1) - stack_a >= 2)
	{
		temp2 = (*argv)[stack_a + 1];
		(*argv)[stack_a + 1] = (*argv)[stack_a + 2];
		(*argv)[stack_a + 2] = temp2;
	}
}

int	push_a(char **argv[], int stack_a)
{
	int		i;
	char	*temp;

	ft_printf("pa\n");
	temp = (*argv)[stack_a + 1];
	i = stack_a + 1;// next element
	while (i >= 1)
	{
		(*argv)[i] = (*argv)[i - 1];
		i--;
	}
	(*argv)[1] = temp;
	return (stack_a + 1);
}

int	push_b(char **argv[], int stack_a)
{
	int		i;
	char	*temp;

	ft_printf("pb\n");
	temp = (*argv)[1];
	i = 1;// next element
	while (i <= stack_a)
	{
		(*argv)[i] = (*argv)[i + 1];
		i++;
	}
	(*argv)[stack_a] = temp;
	return (stack_a - 1);
}

void	rotate_a(char **argv[], int stack_a)
{
	int		i;
	char	*temp;

	ft_printf("ra\n");
	temp = (*argv)[1];
	i = 1;// next element
	while (i <= stack_a)
	{
		(*argv)[i] = (*argv)[i + 1];
		i++;
	}
	(*argv)[stack_a] = temp;
}

void	rotate_b(int argc, char **argv[], int stack_a)
{
	char	*temp;

	ft_printf("rb\n");
	temp = (*argv)[stack_a + 1];
	while (stack_a <= (argc - 1))
	{
		(*argv)[stack_a + 1] = (*argv)[stack_a + 2];
		stack_a++;
	}
	(*argv)[argc - 1] = temp;
}

void	rr(char **argv[], int stack_a, int argc)
{
	ft_printf("rr\n");
	rotate_a(argv, stack_a);
	rotate_b(argc, argv, stack_a);
}

void	reverse_rotate_a(char **argv[], int stack_a)
{
	int		i;
	char	*temp;

	ft_printf("rra\n");
	temp = (*argv)[stack_a];
	i = stack_a;// next element
	while (i > 1)
	{
		(*argv)[i] = (*argv)[i - 1];
		i--;
	}
	(*argv)[1] = temp;
}

void	reverse_rotate_b(int argc, char **argv[], int stack_a)
{
	int		i;
	char	*temp;

	ft_printf("rrb\n");
	temp = (*argv)[argc - 1];
	i = stack_a + 1;// next element
	while ((argc - 1) >= i)
	{
		(*argv)[argc - 1] = (*argv)[argc - 2];
		argc--;
	}
	(*argv)[stack_a + 1] = temp;
}

void	rrr(char **argv[], int stack_a, int argc)
{
	ft_printf("rrr\n");
	reverse_rotate_a(argv, stack_a);
	reverse_rotate_b(argc, argv, stack_a);
}
