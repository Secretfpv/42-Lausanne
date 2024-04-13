/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:46:27 by mwikiera          #+#    #+#             */
/*   Updated: 2024/03/20 19:46:27 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

int	checker(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
		{
			//ft_printf("\nNot sorted  :(\n");
			return (0);// this case its not sorted
		}
		i++;
	}
	//ft_printf("\nSorted!  :)\n");
	return (1);// in this case its sorted
}

int	middle_number_a(char *argv[], int stack_a)
{
	int	i;
	int	suma;

	i = 1;
	suma = 0;
	while (i <= stack_a)
	{
		suma = suma + ft_atoi(argv[i]);
		i++;
	}
	suma = suma / stack_a;
	ft_printf("Srednia: %d\n\n", suma);
	return (suma);
}

int	middle_number_b(int argc, char *argv[], int stack_a)
{
	int	suma;

	suma = 0;
	while (stack_a + 1 <= argc)
	{
		suma = suma + ft_atoi(argv[stack_a + 1]);
		stack_a++;
	}
	suma = suma / (argc - 1 - stack_a);// do sprawdzenia
	return (suma);
}

int	midvalue(char *argv[], int argc)
{
	int	mid_val;
	int	start;
	int	i;
	int	last_a;
	int	first_a;
	char	*temp;

	first_a = 1;// first element
	last_a = 2;// takes the second argument of the list to make comparation
	mid_val = 1;
	start = 1;
	ft_printf("(Argc - 1)/2 : %d\n", ((argc - 0)/2));// zaokraglone w gore
	while (start <= (argc/2))
	{
		i = 1;
		last_a = 2;
		first_a = 1;
		while (i < (argc - start))
		{
			ft_printf("firts element: %s\n", argv[start]);
			if (ft_atoi(argv[first_a]) < ft_atoi(argv[last_a]))
			{
				ft_printf("---------lasta: %d\n", last_a);
				first_a = last_a;
				temp = argv[last_a];
				ft_printf("-> %s\n", argv[last_a]);
				ft_printf("-< %s\n", temp);
				argv[last_a] = argv[start];
				ft_printf("-> %s\n", argv[start]);
				ft_printf("-> %s\n", argv[last_a]);
				argv[start] = argv[last_a];
				ft_printf("-> %s\n", temp);
			}
			last_a++;
			ft_printf("MV: %d\n", ft_atoi(argv[mid_val]));
			ft_printf("last a: %d\n", last_a);
			ft_printf("first a: %d\n", first_a);
			i++;
		}
		first_a++;
		ft_printf("start: %d\n", start);
		start++;
	}
	return (mid_val);
}

void	ft_sort_3_a(char *argv[], int stack_a)
{
//	ft_printf("%d\n", ft_atoi(argv[1]));
//	ft_printf("%d\n", ft_atoi(argv[2]));
//	ft_printf("%d\n", ft_atoi(argv[3]));

	if (ft_atoi(argv[1]) < ft_atoi(argv[2]) && ft_atoi(argv[3]) < ft_atoi(argv[2]))
	{
		reverse_rotate_a(&argv, stack_a);
		swap_a(&argv, stack_a);
	}
	if (ft_atoi(argv[3]) < ft_atoi(argv[2]) && ft_atoi(argv[2]) < ft_atoi(argv[1]))
	{
		rotate_a(&argv, stack_a);
		swap_a(&argv, stack_a);
	}
	if (ft_atoi(argv[2]) < ft_atoi(argv[3]) && ft_atoi(argv[2]) < ft_atoi(argv[1]) && ft_atoi(argv[3]) < ft_atoi(argv[1]))
		rotate_a(&argv, stack_a);
	if (ft_atoi(argv[2]) < ft_atoi(argv[3]) && ft_atoi(argv[2]) < ft_atoi(argv[1]))
		swap_a(&argv, stack_a);
	if (ft_atoi(argv[3]) < ft_atoi(argv[2]) && ft_atoi(argv[1]) < ft_atoi(argv[2]))
		reverse_rotate_a(&argv, stack_a);
}

int	ft_sort(char *argv[], int argc, int stack_a)
{
	stack_a = push_b(&argv, stack_a);
	stack_a = push_b(&argv, stack_a);

	while (stack_a > 3)
	{
		if ()
		{

		}
		
	}
	
	argc++;

	return (stack_a);
}
