/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_functions3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:52 by mwikiera          #+#    #+#             */
/*   Updated: 2024/04/27 17:57:24 by mwikiera         ###   ########.fr       */
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
	ft_printf("\nthis is 1b: %d\n\n", ft_atoi(argv[stack_a + 1]));
	ft_printf("\nthis is 1a: %d\n\n", ft_atoi(argv[n]));



	moves_needed_up = 0; /// Smallest number goes down
	while (ft_atoi(argv[n]) > ft_atoi(argv[stack_a + 1]) && ((stack_a + 1) < (argc - 1)))
	{
		moves_needed_up++;
		stack_a++;
		ft_printf("\nthis is 1a???????: \n\n");
	}
	//if (ft_atoi(argv[n]) > ft_atoi(argv[argc - 1])) //need check this case
	//	moves_needed_up++;
	ft_printf("a1 - moves needed from up: %d\n", moves_needed_up + n);

	return (moves_needed_up + n);
}

int	moves_down(char *argv[], int argc, int stack_a, int n)
{
	int moves_needed_down;

	moves_needed_down = 0;
	while (ft_atoi(argv[n]) < ft_atoi(argv[argc - 1]) && ((argc - 1) > (stack_a + 1)))
	{
		moves_needed_down++;
		argc--;
	}
	//if (ft_atoi(argv[n]) > ft_atoi(argv[stack_a + 1]))
	//	moves_needed_down++;
	ft_printf("a1 - moves needed from down: %d\n", moves_needed_down + n);
	
	return (moves_needed_down + n);
}

void	sorta1(char *argv[], int argc, int *stack_a)
{
	ft_printf("\n\n HEEELLLLOOOOOO \n\n");
	//if ((moves_up(argv, argc, *stack_a, 1) == 1) || (moves_down(argv, argc, *stack_a, 1)))
	//{
	//	ft_printf("\n\n 2HEEELLLLOOOOOO \n\n");
	//}
	//else
	//{
	if (moves_up(argv, argc, *stack_a, 1) <= moves_down(argv, argc, *stack_a, 1))
	{
		ft_printf("\n\n HEEELLLLOOOOOO3 \n\n");
		while (ft_atoi(argv[1]) < ft_atoi(argv[*stack_a + 1]))
		{
			reverse_rotate_b(argc, &argv, *stack_a);
		//	push_b(&argv, stack_a);
		//	reverse_rotate_b(argc, &argv, *stack_a);
		//	ft_printf("\n\n HEEELLLLOOOOOO4 \n\n");
		}
		push_b(&argv, stack_a);
		//reverse_rotate_b(argc, &argv, *stack_a);
	}
	else
	{
		ft_printf("\nwoooow: \n\n");
		ft_printf("\nb1 number: %d \n\n", ft_atoi(argv[*stack_a + 1]));
		while (ft_atoi(argv[1]) > ft_atoi(argv[argc - 1]))
		{
			reverse_rotate_b(argc, &argv, *stack_a);
		}
		push_b(&argv, stack_a);
		//rotate_b(argc, &argv, *stack_a);
		//rotate_b(argc, &argv, *stack_a);
	}
	//}
	//rotate_b(argc, &argv, *stack_a);
	//push_b(&argv, stack_a);
}
