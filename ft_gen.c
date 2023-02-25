/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orios-me <orios-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:47:46 by jaarteag          #+#    #+#             */
/*   Updated: 2023/02/25 20:35:02 by jaarteag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_comb(int comb[4][4]);

void	ft_init_row(int row[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		row[i] = i + 1;
		i++;
	}
}

void	ft_init_comb(int comb[4][4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_init_row(comb[i]);
		i++;
	}
}

int ft_next_row(int row[4])
{
	printf("ft_next_row\n");

	int	i;
	int changed;

	if ((row[4] == 4) || (row [3] == 3) || (row[2] == 2) || (row[1] == 1))
	{
		return (0);
	}
	changed = 0;
	i = 3;
	printf ("i: %d, row[i]: %d\n", i, row[i]);
	while (row[i] == 4)
	{
		i--;
		printf ("i: %d, row[i]: %d\n", i, row[i]);
	}
	row[i]++;
	printf ("i: %d, row[i]: %d\n", i, row[i]);
	while (i++ < 3)
	{
		row[i] = 1;
//		printf ("i: %d, row[i]: %d\n", i, row[i]);
	}
	changed = 1;
	printf ("Changed: %d\n", changed);
	return (changed);
}

int	ft_next_comb(int comb[4][4])
{
	int i;
	int changed;
//	printf("ft_next_comb\n");

	i = 3;
	changed = 0;
	while ((!changed && i > 0)) 
	{
//		printf ("Row %d\n", i);
		changed = ft_next_row(comb[i]);
		i--;
//		printf ("Changed: %d\n", changed);
	}
	if (changed)
//		printf("i: %d", i);
		while (++i < 3)
		{
//			printf ("Init row");
			ft_init_row(comb[i]);
		}
//	ft_print_comb(comb);
	return (changed);
}
