/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:41:28 by mwikiera          #+#    #+#             */
/*   Updated: 2024/03/11 17:50:02 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	find_biggest_num_a(int argc, char *argv[], int stack_a)
{
	int		last_a;
	int 	first_a;
	int		biggest;

	first_a = 1;// first element
	last_a = 2;// takes the second argument of the list to make comparaison
	while (last_a <= stack_a)
	{
		if (ft_atoi(argv[first_a]) < ft_atoi(argv[last_a]))
		{
			first_a = last_a;
		}
		last_a++;
	}
	ft_printf("biggest args found _ a: %s\n", argv[first_a]);
}

void	find_biggest_num_b(int argc, char *argv[], int stack_a)
{
	int		last_b;
	int 	first_b;
	int		biggest;

	first_b = stack_a + 1;// first element
	last_b = argc - 1;// takes the second argument of the list to make comparaison
	while (last_b < argc)
	{
		if (ft_atoi(argv[first_b]) < ft_atoi(argv[last_b]))
		{
			first_b = last_b;
		}
		last_b++;
	}
	ft_printf("biggest args found _ b: %s\n", argv[first_b]);
}

void	move(char *argv[])
{

}

void	func_display(int argc, char *argv[], int stack_a)
{
	int	i;

	ft_printf("\n");
	i = 1;
	while (i <= stack_a)
	{
		ft_printf("a - %s\n", argv[i]);
		i++;
	}
	ft_printf("========\n");
	while ((i - stack_a)  <= (argc - 1) - stack_a)
	{
		ft_printf("b - %s\n", argv[i]);
		i++;
	}
	ft_printf("\n");
}

int	check_number_args(int argc, char *argv[])
{
	//int	i;

	if (argc < 3)
	{
		ft_printf("Not enough arguments\n");
		return (0);
	}
	/*i = argc;
	ft_printf("Number of arguments: ");
	while(i - 1 > 0)
	{
		ft_printf("%d ", i - 1);
		i--;
	}*/
	return (1);
}

void	push_swap(int argc, char *argv[])
{
	int	stack_a;

	stack_a = argc - 1;

	func_display(argc, argv, stack_a);

	/*stack_a = push_b(&argv, stack_a);
	stack_a = push_b(&argv, stack_a);
	stack_a = push_b(&argv, stack_a);

	func_display(argc, argv, stack_a);*/

	/*ft_printf("%s\n", argv[1]);
	ft_printf("%s\n", argv[2]);

	if(ft_atoi(argv[1]) > ft_atoi(argv[2]))
	{
		ft_printf("Hello\n");
		swap_a(&argv, stack_a);
	}*/

	while (stack_a > 1)
	{	
		/*if(ft_atoi(argv[1]) > ft_atoi(argv[2]))
			swap_a(&argv, stack_a);*/
		if ((argc - 1) - stack_a > 1)
		{
			if (ft_atoi(argv[1]) > ft_atoi(argv[2]) && ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))
			{
				ss(&argv, stack_a, argc);
				stack_a = push_b(&argv, stack_a);
			}
		}
		if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
			swap_a(&argv, stack_a);
		else if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
			swap_a(&argv, stack_a);
		else if (ft_atoi(argv[1]) < ft_atoi(argv[2]))
			stack_a = push_b(&argv, stack_a);
		if ((argc - 1) - stack_a > 1)
			if (ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))
				swap_b(&argv, stack_a, argc);
		//func_display(argc, argv, stack_a);
	}

	func_display(argc, argv, stack_a);

	while ((argc - 1) - stack_a > 1)
	{
		if (stack_a > 1)
		{
			if (ft_atoi(argv[1]) > ft_atoi(argv[2]) && ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))
			{
				ss(&argv, stack_a, argc);
				stack_a = push_b(&argv, stack_a);
			}
		}
		if(ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))
		{
			swap_b(&argv, stack_a, argc);
			ft_printf("im here\n");
		}
		else if (ft_atoi(argv[stack_a + 1]) > ft_atoi(argv[stack_a + 2]))
			stack_a = push_a(argc, &argv, stack_a);
		else if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
			swap_a(&argv, stack_a);
		if (stack_a > 1)
			if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
				swap_a(&argv, stack_a);
		func_display(argc, argv, stack_a);
	}
	if ((argc - 1) - stack_a == 1)
		stack_a = push_a(argc, &argv, stack_a);

	func_display(argc, argv, stack_a);
	
}

int main(int argc, char *argv[])
{

	push_swap(argc, argv);



	/*int	stack_a;

	stack_a = argc - 1;
	
	if (check_number_args(argc, argv) == 0)
		return (0);
	
	
	ft_printf("Number of arguments: %d\n", argc);
	ft_printf("Size of Stack A: %d\n", stack_a);
	ft_printf("Size of Stack B: %d\n", (argc - 1) - stack_a);
	
	
	func_display(argc, argv, stack_a);
	find_biggest_num_a(argc, argv, stack_a);
	
	ft_printf("\n-------------------------------\n");
	ft_printf("\nNew Stack:\n\n");

	//reverse_rotate_a(&argv, stack_a);
	//rotate_a(&argv, stack_a);
	stack_a = push_b(&argv, stack_a);
	stack_a = push_b(&argv, stack_a);
	stack_a = push_b(&argv, stack_a);

	func_display(argc, argv, stack_a);
	//ft_printf("Size of Stack A: %d\n", stack_a);
	//ft_printf("Size of Stack B: %d\n", (argc - 1) - stack_a);

	//reverse_rotate_b(argc, &argv, stack_a);

	//stack_a = push_a(argc, &argv, stack_a);
	//rotate_b(argc, &argv, stack_a);
	//func_display(argc, argv, stack_a);
	//rotate_b(argc, &argv, stack_a);
	//rotate_b(argc, &argv, stack_a);
	//swap_a(&argv, stack_a);
	//swap_b(&argv, stack_a, argc);
	//rr(&argv, stack_a, argc);
	rrr(&argv, stack_a, argc);
	
	func_display(argc, argv, stack_a);

	ft_printf("Size of Stack A: %d\n", stack_a);
	ft_printf("Size of Stack B: %d\n", (argc - 1) - stack_a);

	find_biggest_num_a(argc, argv, stack_a);
	find_biggest_num_b(argc, argv, stack_a);
	//move(argv);*/
	return (0);
}

// gcc -g ft_push_swap.c ft_push_swap.h -Ilibft -Llibft -lft

// make clean

// make or make all


// https://github.com/mohsink20/42cursus/blob/main/push_swap/mylib/Makefile      makefile to check