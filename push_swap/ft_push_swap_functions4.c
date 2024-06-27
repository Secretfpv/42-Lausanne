/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_functions4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 02:28:18 by mwikiera          #+#    #+#             */
/*   Updated: 2024/06/27 02:28:18 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	stackbtoa(char *argv[], int argc, int *stack_a)
{
	int	sec_num;
	int	big_num_pos;
	int	big_num;
	
	sec_num = 2;

	big_num_pos = b_top_num(argv, argc, stack_a);
	big_num = ft_atoi(argv[*stack_a + big_num_pos]);


//	ft_printf("big num pos: %d\n", big_num_pos);
//	ft_printf("big num:     %d\n\n", big_num);

	while (ft_atoi(argv[*stack_a + 1]) != big_num) // This code is to put bigger on top
	{
		if ((argc - 1 - *stack_a) / 2 > big_num_pos / 2) // this is false
			rotate_b(argc, &argv, *stack_a);
		reverse_rotate_b(argc, &argv, *stack_a);
	}


	func_display(argc, argv, *stack_a);

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

//	ft_printf("\n\n Stack_a:        %d\n", *stack_a + 1);
//	ft_printf("\n\n Argc:           %d\n", argc);

	while (*stack_a < argc - 1)
		push_a(&argv, stack_a);

}

int	b_top_num(char *argv[], int argc, int *stack_a)
{
	int	i;
	int	i_pos;
	int	big_num;

//	ft_printf("\n\n Stack_a:        %d\n", *stack_a + 1);
//	ft_printf("\n\n Argc:           %d\n", argc);

	i = 1;
	i_pos = 1;
	big_num = ft_atoi(argv[*stack_a + i]);

	//ft_printf("big num2 : %d\n", ft_atoi(argv[*stack_a + i]));

	while (*stack_a + i < argc)
	{
		if (big_num < ft_atoi(argv[*stack_a + i]))
		{
			big_num = ft_atoi(argv[*stack_a + i]);
			i_pos = i;
		}
	//	ft_printf("\n => num:        %d\n", big_num);
		i++;
	}
//	ft_printf("\n Big num:        %d\n", big_num);
//	ft_printf("\n i_pos:        %d\n", i_pos);

	return (i_pos);
}
