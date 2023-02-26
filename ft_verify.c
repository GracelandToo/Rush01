/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orios-me <orios-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:25:59 by orios-me          #+#    #+#             */
/*   Updated: 2023/02/25 22:39:56 by orios-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

/*checks if the puzzle is even solvable given input parameters
already writes its own temporary error message and returns 0*/
int	ft_verify_solvability(int parameters[16], int i)
{
	while (i < 4)
	{
		if (parameters[i] + parameters[i + 4] > 5)
		{
			write(1, "Error: Unsolvable puzzle", 25);
			return (0);
		}
		i++;
	}
	i = 8;
	while (i < 12)
	{
		if (parameters[i] + parameters[i + 4] > 5)
		{
			write(1, "Error: Unsolvable puzzle", 25);
			return (0);
		}
		i++;
	}
	return (1);
}

//verifies that there are no repeated values on any given row
int	ft_verify_rows(int comb[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (comb[i][0] == comb[i][1] || comb[i][0] == comb[i][2] || \
		comb[i][0] == comb[i][3] || comb[i][1] == comb[i][2] || \
		comb[i][1] == comb[i][3] || comb[i][2] == comb[i][3])
			return (0);
		i++;
	}
	return (1);
}

//verifies that there are no repeated values on any given column
int	ft_verify_columns(int comb[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (comb[0][i] == comb[1][i] || comb[0][i] == comb[2][i] || \
		comb[0][i] == comb[3][i] || comb[1][i] == comb[2][i] || \
		comb[1][i] == comb[3][i] || comb[2][i] == comb[3][i])
			return (0);
		i++;
	}
	return (1);
}
