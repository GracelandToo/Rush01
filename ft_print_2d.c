/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orios-me <orios-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:40:28 by orios-me          #+#    #+#             */
/*   Updated: 2023/02/25 22:44:05 by orios-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//has its own main for testing, must remove later
#define SIZE 4

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//simple print function for the whole grid
void	ft_print_comb(int comb[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ft_putchar(comb[i][j] + 48);
			if (j < 4)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}