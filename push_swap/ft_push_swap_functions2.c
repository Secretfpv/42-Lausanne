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
