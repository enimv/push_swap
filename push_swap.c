/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:53:21 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/01 00:01:29 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_mainalloc(int ac, t_stack *stacka, t_stack *stackb)
{
	stacka->len = ac - 1;
	stacka->top = -1;
	stackb->top = -1;
	stackb->len = ac - 1;
	stacka->last = 0;
	stacka->array = malloc(sizeof(int) * stacka->len);
	stackb->array = malloc(sizeof(int) * stackb->len);
}

int	ft_sortcheck(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->array[i] < stack->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_sizeofsort(int ac, t_stack *stacka, t_stack *stackb)
{
	if (ac == 4 || ac == 3)
		ft_smallsort(stacka);
	else if (ac >= 5 && ac <= 11)
		ft_medieumsort(stacka, stackb);
	else if (ac > 11)
		ft_largesort(stacka, stackb);
}

int	ft_free(t_stack *stacka, t_stack *stackb)
{
	free(stacka->array);
	free(stackb->array);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	stacka;
	t_stack	stackb;

	if (ac < 2)
		return (-1);
	if (ft_checker(ac, av) == 1)
		return (ft_putstr("ERROR...NUMBER ONLY!!!"));
	if (ft_duplicate(ac, av) != 0)
		return (ft_putstr("ERROR...DUPLICATION!!!"));
	ft_mainalloc(ac, &stacka, &stackb);
	i = stacka.len;
	while (i > 0)
		push(&stacka, ft_atoi(av[i--]), 'c');
	if (ft_sortcheck(&stacka) == 1)
		return (ft_free(&stacka, &stackb));
	ft_sizeofsort(ac, &stacka, &stackb);
	return (ft_free(&stacka, &stackb));
}
