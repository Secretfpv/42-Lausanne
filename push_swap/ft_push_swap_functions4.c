/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_functions4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:41:28 by mwikiera          #+#    #+#             */
/*   Updated: 2024/05/24 18:32:07 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	stackbtoa(char *argv[], int argc, int *stack_a)
{
	int		sec_num;
	int	big_num_pos;
	int	big_num;
	
	sec_num = 2;

	big_num_pos = b_top_num(argv, argc, stack_a);
	big_num = ft_atoi(argv[*stack_a + big_num_pos]);

	while (ft_atoi(argv[*stack_a + 1]) != big_num) // This code is to put bigger on top
	{
		if ((argc - 1 - *stack_a) / 2 > big_num_pos / 2) // this is false
			rotate_b(argc, &argv, *stack_a);
		reverse_rotate_b(argc, &argv, *stack_a);
	}

	ft_printf("\n\n argv[i] is biggest   %d\n", big_num_pos);
	ft_printf("\n %d is biggest\n", ft_atoi(argv[big_num_pos + *stack_a]));
	
	func_display(argc, argv, *stack_a);

	ft_printf("\n\n Argv[1]:        %s\n", (argv[1]));
	ft_printf("\n\n Argv[2]:        %s\n", (argv[2]));
	ft_printf("\n\n Argv[argc + 1]: %s\n", (argv[*stack_a + 1]));


	while (ft_atoi(argv[*stack_a + 1]) < ft_atoi(argv[1]) && ft_atoi(argv[*stack_a + 1]) > ft_atoi(argv[sec_num]))
	{
		sec_num++;
		push_a(&argv, stack_a);
	}

	reverse_rotate_a(&argv, *stack_a);

	while (ft_atoi(argv[*stack_a + 1]) < ft_atoi(argv[1]) && ft_atoi(argv[*stack_a + 1]) > ft_atoi(argv[sec_num]))
	{
		sec_num++;
		push_a(&argv, stack_a);
	}

	reverse_rotate_a(&argv, *stack_a);

	ft_printf("\n\n Stack_a:        %d\n", *stack_a + 1);
	ft_printf("\n\n Argc:           %d\n", argc);

	while (*stack_a < argc - 1)
		push_a(&argv, stack_a);

}

int	b_top_num(char *argv[], int argc, int *stack_a)
{
	int	i;
	int	big_num;

//	ft_printf("\n\n Stack_a:        %d\n", *stack_a + 1);
//	ft_printf("\n\n Argc:           %d\n", argc);

	i = 1;
	big_num = ft_atoi(argv[*stack_a + i]);
	while (*stack_a + i < argc)
	{
		if (big_num < ft_atoi(argv[*stack_a + i]))
		{
			big_num = ft_atoi(argv[*stack_a + i]);
		}
//		ft_printf("\n => num:        %d\n", big_num);
		i++;
	}
//	ft_printf("\n Big num:        %d\n", big_num);
//	ft_printf("\n Stack_a:        %d\n", *stack_a);

	return (i + /**stack_a*/ - 1);
}
