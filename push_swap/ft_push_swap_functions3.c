/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_functions3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:16:36 by mwikiera          #+#    #+#             */
/*   Updated: 2024/05/21 20:20:20 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	moves_up(char *argv[], int argc, int stack_a, int n/*the number*/)
{
	int moves_needed_up;


	//ft_printf("1a - %s\n", argv[1]);
	//ft_printf("1b - %s\n", argv[stack_a + 1]);
	//ft_printf("last - %s\n", argv[argc - 1]);

	//int first_number;
	//first_number =
	ft_printf("\nthis is 1b: %d\n", ft_atoi(argv[stack_a + 1]));
	ft_printf("\nthis is 1a: %d\n\n", ft_atoi(argv[n]));



	moves_needed_up = 0; /// Smallest number goes down
	while (ft_atoi(argv[n]) > ft_atoi(argv[stack_a + 1]) && ft_atoi(argv[n]) < ft_atoi(argv[stack_a + 2]) && ((stack_a + 1) < (argc - 1)))
	{
		moves_needed_up++;
		stack_a++;
	ft_printf("\nthis is 1a???????: \n");
	}
	//if (ft_atoi(argv[n]) > ft_atoi(argv[argc - 1])) //need check this case
	//	moves_needed_up++;
	ft_printf("a: %d - moves needed from up: %d\n", n, moves_needed_up + n);

	return (moves_needed_up + n);
}

int	moves_down(char *argv[], int argc, int stack_a, int n)
{
	int moves_needed_down;

	func_display(argc, argv, stack_a);

	moves_needed_down = 0;
	while (ft_atoi(argv[n]) < ft_atoi(argv[argc - 1]) && ft_atoi(argv[n]) > ft_atoi(argv[argc - 2]) && ((argc - 1) > (stack_a + 1)))
	{
		moves_needed_down++;
		argc--;
	}
	//if (ft_atoi(argv[n]) > ft_atoi(argv[stack_a + 1]))
	//	moves_needed_down++;
	ft_printf("a: %d - moves needed from down: %d, last b: %d\n", n, moves_needed_down + n, ft_atoi(argv[argc - 1]));
	
	return (moves_needed_down + n + 1); // i wanna number pass up
}

void	sorta1(char *argv[], int argc, int *stack_a)
{
	if (moves_up(argv, argc, *stack_a, 1) <= moves_down(argv, argc, *stack_a, 1))
	{
		//ft_printf("\n\n HEEELLLLOOOOOO3 \n\n");
		while (ft_atoi(argv[1]) < ft_atoi(argv[*stack_a + 1]))
			rotate_b(argc, &argv, *stack_a);
		push_b(&argv, stack_a);
	}
	else
	{
		ft_printf("\nwoooow: \n\n");
		ft_printf("\nb1 number: %d \n\n", ft_atoi(argv[*stack_a + 1]));
		while (ft_atoi(argv[1]) > ft_atoi(argv[argc - 1]))
			reverse_rotate_b(argc, &argv, *stack_a);
		reverse_rotate_b(argc, &argv, *stack_a); // to put nuber 1 up
		push_b(&argv, stack_a);
	}
}

void	sorta2(char *argv[], int argc, int *stack_a)
{
	if (moves_up(argv, argc, *stack_a, 2) <= moves_down(argv, argc, *stack_a, 2))
	{
		//ft_printf("\n\n HEEELLLLOOOOOO3 \n\n");
		while (ft_atoi(argv[2]) < ft_atoi(argv[*stack_a + 1]))
			rotate_b(argc, &argv, *stack_a);
		rotate_a(&argv, *stack_a);
		push_b(&argv, stack_a);
	}
	else
	{
		//ft_printf("\nwoooow: \n\n");
		ft_printf("\nb1 number: %d \n\n", ft_atoi(argv[*stack_a + 1]));
		while (ft_atoi(argv[2]) > ft_atoi(argv[argc - 1]))
			reverse_rotate_b(argc, &argv, *stack_a);
		//rotate_a(&argv, *stack_a); // idl what this is???
		reverse_rotate_b(argc, &argv, *stack_a); // to put nuber 1 up
		push_b(&argv, stack_a);
	}
}

void	sorta3(char *argv[], int argc, int *stack_a)
{
	if (moves_up(argv, argc, *stack_a, 3) <= moves_down(argv, argc, *stack_a, 3))
	{
		//ft_printf("\n\n HEEELLLLOOOOOO3 \n\n");
		while (ft_atoi(argv[3]) > ft_atoi(argv[*stack_a + 1]))
			rotate_b(argc, &argv, *stack_a);
		rotate_a(&argv, *stack_a);
		rotate_a(&argv, *stack_a);
		push_b(&argv, stack_a);
	}
	else
	{
		//ft_printf("\nwoooow: \n\n");
		ft_printf("\nb1 number: %d \n\n", ft_atoi(argv[*stack_a + 1]));
		while (ft_atoi(argv[3]) < ft_atoi(argv[argc - 1]))
			reverse_rotate_b(argc, &argv, *stack_a);
		rotate_a(&argv, *stack_a);
		rotate_a(&argv, *stack_a);
		push_b(&argv, stack_a);
	}
}
