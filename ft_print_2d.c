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
#include <stdio.h>

//has its own main for testing, must remove later
#define SIZE 4

void	ft_init_comb(int comb[4][4]);
int		ft_next_comb(int comb[4][4]);
void	ft_putchar(char c);
int		ft_verify_rows(int comb[4][4]);
int		ft_verify_columns(int comb[4][4]);



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

int main(int argc, char **argv)
{
	int i = 0;
	int changed = 1;
	int comb[SIZE][SIZE];

	ft_init_comb(comb);
//	ft_print_comb(comb);
//	printf("hola");
//	changed = ft_next_comb(comb);
//	printf ("Changed: %d\n", changed);
//	ft_print_comb(comb);



	/* This benchmarks how long all permutations take */
	
//	while(changed)
	while (i < 4)
	{
		changed = ft_next_comb(comb);
		ft_print_comb(comb);
		printf("\n");
	
		i++;
		if (i % 1000000 == 0)
		{
			printf("%d", i);
			printf("\n");
			ft_print_comb(comb);


		}

		//printf("\n");
	}
//	ft_print_comb(comb);
}
